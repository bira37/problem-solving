#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<map<char,int> > trie(1);

vector<map<char,int> > trie2(1);

void insert(string s){
	int cur = 0;
		for(int i =0;i<(int)s.size();i++){
		char c = s[i];
		if(trie[cur].count(c)==0){
			map<char,int> a;
			trie.push_back(a);
			trie[cur][c] = trie.size()-1;
		
		}
		cur = trie[cur][c];
		}
}

int find(string s){
	int cur = 0;
		for(int i =0;i<(int)s.size();i++){
		char c = s[i];
		if(!trie[cur].count(c)){
			return false;
		}
		cur = trie[cur][c];
		}
	return true;
}

void insert2(string s){
	int cur = 0;
		for(int i =0;i<(int)s.size();i++){
		char c = s[i];
	
		if(trie2[cur].count(c)==0){
			map<char,int> a;
			trie2.push_back(a);
			trie2[cur][c] = trie2.size()-1;

		}
		cur = trie2[cur][c];
	
		}
}

int find2(string s){
	int cur = 0;
		for(int i =0;i<(int)s.size();i++){
		char c = s[i];
		if(!trie2[cur].count(c)){
			return false;
		}
		cur = trie2[cur][c];
		}
	return true;
}

int main(){
	fastio;
	int n;
	cin>>n;
	int flag = true;
	
	string res;
	for(int i=0;i<n;i++){
	string aux;
	cin>>aux;
	
	if(!flag)continue;
	
	if(find(aux)){
		flag=false;
		res=aux;
	}
	string pre="";
	for(int j=0;j<9;j++){
		string suf="",pre2="",suf2="";
		if(!flag)break;
		
		
		for(int k = j+1;k<=9;k++){
			pre2+=aux[k];
		}
		for(int k=j;k>=0;k--){
			suf2+=aux[k];
		}
		
		if(find2(suf2) && find(pre2)){
			res=aux;
			flag=false;
			break;
		}
			
	}
		string anti="";
		for(int j=9;j>=0;j--){
			anti+=aux[j];
		}
		
		insert(aux);
		
		insert2(anti);
	}
	
	if(flag){
		cout<<"ok"<<endl;
	}else{
		cout<<res<<endl;
	}
	
	
}