#include <bits/stdc++.h>

using namespace std;

vector< map<char, int> > trie;

bool flag;

void new_node(){
	trie.push_back(map<char,int>());
}

void build_trie(string & s){
	int curr=0;
	for(int i=0; i<s.size();i++){
		if(!trie[curr].count(s[i])){
			new_node();
			trie[curr][s[i]] = trie.size()-1;
		}
		curr = trie[curr][s[i]];
	}
}

bool search_trie(string & s){
	int curr = 0;
	for(int i=0; i<s.size(); i++){
		if(trie[curr].size() == 0) return true;
		if(trie[curr].count(s[i])) curr = trie[curr][s[i]];
		else return false;
	}
	return true;
}
	

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		trie.clear();
		new_node(); //root
		int n;
		cin >> n;
		flag = false;
		for(int i=0;i<n; i++){
			string x;
			cin >> x;
			if(i) if(search_trie(x)) flag = true;
			if(!flag) build_trie(x);
		}
		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
		
