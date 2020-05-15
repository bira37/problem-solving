#include <bits/stdc++.h>

using namespace std;

struct edges{
	int u,v,c;
	edges(int u, int v, int c) : u(u), v(v), c(c) {}
};

int tempo = 0;
int st[112345];
int ed[112345];
int vis[112345];
int dad[112345];
vector<int> adj[112345];
vector<int> adj_cost[112345];
int anc[20][112345];
int best[20][112345];
vector<edges> e,mst;

int uf[112345];
int sz[112345];

bool cmp(const edges & a, const edges & b){
	return a.c > b.c;
}

void init(int n){
	for(int i=1; i<=n; i++){
		uf[i] = i;
		sz[i] = 1;
	}
}

int find(int n){
	if(uf[n] == n) return n;
	else return uf[n] = find(uf[n]);
}

int merge(int a, int b){
	int x = find(a);
	int y = find(b);
	if(sz[x] < sz[y]) swap(x,y);
	sz[x] += sz[y];
	uf[y] = x;
}

void dfs_makedad(int u){
	vis[u] = true;
	st[u] = tempo++;
	//cout << u << endl;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		//cout << v << endl;
		if(!vis[v]){
			dad[v] = u;
			best[0][v] = adj_cost[u][i];
			dfs_makedad(v);
		}
	} 
	ed[u] = tempo++;
}

void kruskal(){
	sort(e.begin(), e.end(), cmp);
	for(int i = 0; i< e.size(); i++){
		if(find(e[i].u) == find(e[i].v)) continue;
		merge(e[i].u, e[i].v);
		mst.push_back(e[i]);
	}
}

bool is_ancestor(int u, int v){
	return st[u] <= st[v] && st[v] <= ed[u];
}

int lca(int u, int v){
	if(is_ancestor(u,v)) return u;
	for(int i=19; i>=0; i--){
		if(anc[i][u] == -1) continue;
		if(!is_ancestor(anc[i][u],v)) u = anc[i][u];
	}
	return dad[u];
}

int query(int u, int lc){
	if(u == lc) return INT_MAX;
	int curr = u;
	int ans = INT_MAX;
	for(int i=19; i>=0; i--){
		if(anc[i][curr] == -1) continue;
		if(!is_ancestor(anc[i][curr], lc)){
			ans = min(ans, best[i][curr]);
			curr = anc[i][curr];
		}
	}
	return min(ans, best[0][curr]);
} 

int main(){
  ios_base::sync_with_stdio(false);
	int n,m,q;
	while(cin >> n >> m >> q){
	  tempo = 0;
		e.clear();
		mst.clear();
		init(n);
		for(int i=1; i<=n; i++){
			adj[i].clear();
			adj_cost[i].clear();
			vis[i] = false;
		}
		for(int i=0; i<m; i++){
			int u,v,c;
			cin >> u >> v >> c;
			e.push_back(edges(u,v,c));
		}
		kruskal();
		for(int i=1; i<=n; i++){
			adj[i].clear();
			adj_cost[i].clear();
		}
		for(int i=0; i<mst.size(); i++){
		  //cout << mst[i].u << " " << mst[i].v << " " << mst[i].c << endl;
			adj[mst[i].u].push_back(mst[i].v);
			adj[mst[i].v].push_back(mst[i].u);
			adj_cost[mst[i].u].push_back(mst[i].c);
			adj_cost[mst[i].v].push_back(mst[i].c);
		}
		dad[1] = -1;
		best[0][1] = -1;
		//cout << "oloco" << endl;
		dfs_makedad(1);
		for(int i=1; i<=n; i++){
			anc[0][i] = dad[i];
		}

	
		for(int i=1; i<20; i++){
			for(int j=1; j<=n; j++){
					if(anc[i-1][j] != -1){
						anc[i][j] = anc[i-1][anc[i-1][j]];
						best[i][j] = min(best[i-1][j],best[i-1][anc[i-1][j]]);
					}
					else {
						anc[i][j] = -1;
						best[i][j] = -1;
					}
			}
		}

		while(q--){
			int u,v;
			cin >> u >> v;
			int lc = lca(u,v);
			cout << min(query(u,lc), query(v,lc)) << endl;
		}
	}
}
