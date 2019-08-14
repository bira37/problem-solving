#include <bits/stdc++.h>

using namespace std;

//Graphs - Minimum Spanning Tree - Kruskal Algorithm + DSU(Union-Find)

//Ubiratan Correia Barbosa Neto

int uf[10000+1];
int sz[10000+1];

void init(int n){
	for(int i=0; i<=n; i++){
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
	if(sz[a] < sz[b]) swap(a,b); // we want a > b
	uf[b] = a;
	sz[a] += sz[b];
}

struct edges{
	int u,v,cost;
	edges(){}
	edges(int u, int v, int cost) : u(u), v(v), cost(cost){}
};

bool cmp(const edges & a, const edges & b){
	return (a.cost < b.cost);
}

int kruskal(vector<edges> & e){
	int ans = 0;
	sort(e.begin(), e.end(), cmp);
	for(int i = 0; i < e.size(); ++i){
		if(find(e[i].u) == find(e[i].v)) continue;
		merge(e[i].u, e[i].v);
		ans += e[i].cost;
	}
	return ans;
}

int main() {
	int n,m;
	cin >> n >> m;
	init(n);
	vector<edges> e;
	for(int i=0; i<m; i++){
		int u,v,c;
		cin >> u >> v >> c;
		e.push_back(edges(u,v,c));
	}
	cout << kruskal(e) << endl;
	return 0;
}
