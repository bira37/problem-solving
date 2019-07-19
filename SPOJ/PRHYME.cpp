#include <bits/stdc++.h>

using namespace std;

struct node{
	int ptr;
	string smaller;
	string last;
};


vector< map<char, node> > trie;

void new_node(){
	trie.push_back(map<char,node>());
}

string ans;

void build(string & s){
	int curr = 0;
	string revs = s;
	reverse(revs.begin(), revs.end());
	for(int i=0; i<s.size(); i++){
		if(!trie[curr].count(revs[i])){
			new_node();
			trie[curr][revs[i]].ptr= trie.size()-1;
			trie[curr][revs[i]].smaller = s;
		}
		if(s < trie[curr][revs[i]].smaller){
			trie[curr][revs[i]].last = trie[curr][revs[i]].smaller;
			trie[curr][revs[i]].smaller = s;
		}
		else {
			if(s != trie[curr][revs[i]].smaller && (s < trie[curr][revs[i]].last || trie[curr][revs[i]].last == "")){
				trie[curr][revs[i]].last = s;
			}
		}
		curr = trie[curr][revs[i]].ptr;
	}
}

void run(string & s){
	int curr = 0;
	string revs = s;
	reverse(revs.begin(), revs.end());
	for(int i=0; i<s.size(); i++){
		//cout << "visitando " << curr << endl;
		//cout << "ans: " << ans << endl << "smaller: " << trie[curr][s[i]].smaller << endl << "last: " << trie[curr][s[i]].last << endl;
		if(trie[curr].count(revs[i])){
			if(s != trie[curr][revs[i]].smaller) ans = trie[curr][revs[i]].smaller;
			else if(trie[curr][revs[i]].last != "") ans = trie[curr][revs[i]].last;
			curr = trie[curr][revs[i]].ptr;
		}
		else break;
	}
}			

int main(){
	ios_base::sync_with_stdio(false);
	new_node();
	string input;
	string minima,last;
	while(getline(cin, input), input.size() > 0){
		if(input[input.size()-1] == ' ') input =  input.substr(0, input.size()-1);
		if(minima == "") minima = input;
		else{
			if(input < minima){
				last = minima;
				minima = input;
			}
			else if(input < last || last == "") last = input;
		}
		string aux = input;
		build(input);
	}
	while(cin >> input){
		ans = "";
		run(input);
		if(ans == ""){
			//cout << minima << " " << last << " " << revtostr[input] << endl;
			if(minima != input) cout << minima << endl;
			else cout << last << endl;
		}
		else cout << ans << endl;
	}
}
