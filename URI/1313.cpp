#include <bits/stdc++.h>

using namespace std;

vector< map<char,int> > trieP;
vector< map<char, int> > trieE;

int cntP[26], cntE[26];

long long noP,noE;

void new_node(vector< map<char, int> > & trie){
	trie.push_back(map<char,int>());
}

bool flag;

void build_trie(vector< map<char,int> > & trie, string & s){
	int curr = 0;
	for(int i=0; i<s.size(); i++){
		if(!trie[curr].count(s[i])){
			new_node(trie);
			if(flag && curr) cntP[s[i]-'a']++;
			else if(curr)  cntE[s[i]-'a']++;
			trie[curr][s[i]] = trie.size()-1;
		}
		curr = trie[curr][s[i]];
	}
}

long long retira(){
	long long ans = 0;
	for(int i=0; i<26; i++) ans += cntP[i]*cntE[i];
	return ans;
}

void contaP(int curr){
	if(curr) noP++;
	for(map<char,int>::iterator it = trieP[curr].begin(); it != trieP[curr].end(); ++it){
		contaP(it->second);
	}
}

void contaE(int curr){
	if(curr) noE++;
	for(map<char,int>::iterator it = trieE[curr].begin(); it != trieE[curr].end(); ++it){
		contaE(it->second);
	}
}

int main(){
	int n,m;
	while(cin >> n >> m, n && m){
		trieP.clear();
		trieE.clear();
		new_node(trieP);
		new_node(trieE);
		noP=0;
		noE=0;
		for(int i=0; i<26; i++){
			cntP[i] = 0;
			cntE[i] = 0;
		}
		flag = true;
		for(int i=0; i<n;i++){
			string x;
			cin >> x;
			build_trie(trieP, x);
		}
		flag = false;
		for(int i=0; i<m;i++){
			string x;
			cin >> x;
			reverse(x.begin(), x.end());
			build_trie(trieE, x);
		}
		contaP(0);
		contaE(0);
		cout << noP*noE - retira() << endl;
		//cout << (trieP.size()-1)*(trieE.size()-1) - retira() << endl;
	}
}
	
