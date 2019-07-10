#include <bits/stdc++.h>
 
using namespace std;
 
//Sets - Union Find 
//Ubiratan Correia Barbosa Neto - UFBA
 
int uf[1000001];
int sz[1000001];
 
void init(int n){
	for(int i=1; i<=n; i++){
		sz[i] = 1;
		uf[i] = i;
	}
}
 
int find(int a){
	if(uf[a] == a) return a;
	else {
		uf[a] = find(uf[a]); //after find the leader l, set uf[i] = l, for all i in the set
		return uf[a];
	}
}
 
void merge(int x, int y){
	int a = find(x);
	int b = find(y);
	if(a==b) return;
	if(sz[a] < sz[b]) swap(a,b); // we want a > b
	uf[b] = a;
	sz[a] += sz[b];
}
 
int main(){
    ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int v[n+1];
	init(n);
	map<int, set<int>> permutation;
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		merge(x,y);
	}
	for(int i=1; i<=n; i++) permutation[find(i)].insert(v[i]);
	for(int i=1; i<=n; i++){
		int k = find(i);
		if(i>1) cout << " ";
	 	cout << *(--permutation[k].end());
	 	permutation[k].erase(--permutation[k].end());
	}
	cout << endl;
}
