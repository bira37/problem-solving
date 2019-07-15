#include <bits/stdc++.h>
#define edge pair<int, int>
#define ff first
#define ss second
using namespace std;

int uf[1123];
int sz[1123];
map<char, map<edge, int> > idx;

void init(){
	for(int i=0; i<1123; i++){
		uf[i] = i;
		sz[i] = 1;
	}
}

int find(int u){
	if( u == uf[u]) return u;
	else return uf[u] = find(uf[u]);
}

void merge(int a, int b){
	int x = find(a);
	int y = find(b);
	if(sz[x] < sz[y]) swap(x,y);
	uf[y] = x;
	sz[x] += sz[y];
}



int main(){
	int n,k;
	cin >> n >> k;
	if(n%2 == 0){
		cout << -1 << endl;
		return 0;
	}
	init();
	vector<edge> s,m;
	for(int i=0; i<k; i++){
		int u,v;
		char c;
		cin >> u >> v >> c;
		idx[c][edge(u,v)] = i;
		if(c == 'S') s.push_back(edge(u,v));
		else m.emplace_back(u,v);
	}
	
	vector<edge> ans;
	for(edge eg : s){
		if(find(eg.ff) == find(eg.ss)) continue;
		merge(eg.ff, eg.ss);
		ans.push_back(eg);
	}
	
	if(ans.size() < (n-1)/2){
		cout << -1 << endl;
		return 0;
	}
	
	vector<edge> new_ans;
	
	for(edge eg : m){
		if(find(eg.ff) == find(eg.ss)) continue;
		merge(eg.ff, eg.ss);
		new_ans.push_back(eg);
		ans.push_back(eg);
	}
	
	if(ans.size() < n-1){
		cout << -1 << endl;
		return 0;
	}
	
	ans.clear();
	
	init();
	
	vector<char> identify;
	
	for(edge eg : new_ans){
		merge(eg.ff, eg.ss);
		ans.push_back(eg);
		identify.push_back('M');
	}
	
	
	for(edge eg : m){
		if(ans.size() == (n-1)/2) break;
		if(find(eg.ff) == find(eg.ss)) continue;
		merge(eg.ff, eg.ss);
		ans.push_back(eg);
		identify.push_back('M');
	}
	
	if(ans.size() != (n-1)/2){
		cout << -1 << endl;
		return 0;
	}
	
	
	for(edge eg : s){
		if(find(eg.ff) == find(eg.ss)) continue;
		merge(eg.ff, eg.ss);
		ans.push_back(eg);
		identify.push_back('S');
	}
	
	
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		if(i) cout << " ";
		cout << idx[identify[i]][ans[i]]+1;
	}
	cout << endl;
}