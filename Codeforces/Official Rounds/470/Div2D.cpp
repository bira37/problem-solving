#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;

map<bool, int> trie[6123456];
int how_many[6123456] = {0};

int return_new = 0;


int new_node(){
	return return_new++;
}

void add(int x){
	int curr = 0;
	for(int i=30; i>=0; i--){
		bool bit = (1<<i) & x;
		if(!trie[curr].count(bit)) trie[curr][bit] = new_node();
		curr = trie[curr][bit];
		how_many[curr]++;
		//cout << "adding bit " << bit << "// currently " << how_many[curr] << " are using this path " << endl;
	}
}

void remove(int x){
	int curr = 0;
	stack< pair<int, bool> > to_rem;
	for(int i=30; i>=0; i--){
		bool bit = (1<<i) & x;
		//cout << "removing " << bit << endl;
		how_many[trie[curr][bit]]--;
		//cout << "there are currently " << how_many[trie[curr][bit]] << " using this path " << endl;
		if(how_many[trie[curr][bit]] == 0) to_rem.push(make_pair(curr, bit));
		curr = trie[curr][bit];
	}
	while(!to_rem.empty()){
		pair<int, bool> tmp = to_rem.top();
		to_rem.pop();
		trie[tmp.first].erase(tmp.second);
	}
}

pair<int,int> search(int x){
	int curr = 0;
	int ans = 0;
	int num = 0;
	for(int i=30; i>=0; i--){
		 bool bit = (1<<i) & x;
		 //cout << "at bit " << bit << endl;
		 if(trie[curr].count(bit)){
		 	//cout << "i can go to same" << endl;
		 	curr = trie[curr][bit];
		 	if(bit) num |= (1<<i);
		 }
		 else {
		 	//cout << "i can only go to the opposite" << endl;
		 	ans |= (1<<i);
		 	if(!bit) num |= (1<<i);
		 	curr = trie[curr][!bit];
		 }
	}
	return make_pair(ans,num);
}
		

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	
	new_node();
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		add(x);
	}
	for(int i=0; i<n; i++){
		pair<int,int> curr = search(v[i]);
		cout << curr.first << " ";
		remove(curr.second);
	}
	cout << endl;
}