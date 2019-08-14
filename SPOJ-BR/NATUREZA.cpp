#include <bits/stdc++.h>

using namespace std;

//Ubiratan Correia Barbosa Neto - UFBA

int uf[5001];
int sz[5001];

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

map<string, int> convert;

int main(){
	int n,m;
	while(cin >> n >> m, n+m){
		convert.clear();
		for(int i=1; i<=n; i++){
			string x;
			cin >> x;
			convert[x] = i;
		}
		init(n);
		for(int i=0; i<m; i++){
			string x,y;
			cin >> x >> y;
			merge(convert[x], convert[y]);
		}
		int ans = 0;
		for(int i=1; i<=n; i++){
			int k = find(i);
			ans = max(ans, sz[k]);
		}
		cout << ans << endl;
		//getchar();
	}
}
