#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define td(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
 
vector<int> adj[212345];
 
struct LCA{
	
	int tempo;
	vector<int> st, ed, dad, anc[20], L;
	vector<bool> vis;
	
	LCA(){}
	
	LCA(int n){
		tempo = 0;
		st.resize(n+1);
		ed.resize(n+1);
		dad.resize(n+1);
		L.resize(n+1);
		for(int i=0; i<20; i++) anc[i].resize(n+1);
		vis.resize(n+1);
		for(int i=0; i<=n; i++) vis[i] = false;
	}
	
	void dfs(int u){
		vis[u] = true;
		st[u] = tempo++;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(!vis[v]){
				dad[v] = u;
				L[v] = L[u]+1;
				dfs(v);
			}
		}
		ed[u] = tempo++;
	}
	
	bool is_ancestor(int u, int v){
		return st[u] <= st[v] && ed[v] <= ed[u];
	}
	
	int query(int u, int v){
		if(is_ancestor(u,v)) return u;
		for(int i=19; i>=0; i--){
			if(anc[i][u] == -1) continue;
			if(!is_ancestor(anc[i][u], v)) u = anc[i][u];
		}
		return dad[u];
	}
	
	int distance(int u, int v){
		return L[u] + L[v] - 2*L[query(u,v)];
	}
	
	void precalculate(){
		dad[1] = -1;
		L[1] = 0;
		dfs(1);
		for(int i=1; i<st.size(); i++){
			anc[0][i] = dad[i];
		}
		for(int i=1; i<20; i++){
			for(int j=1; j<st.size(); j++){
				if(anc[i-1][j] != -1){
					anc[i][j] = anc[i-1][anc[i-1][j]];
				}
				else anc[i][j] = -1;
			}
		}
	}
};
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	LCA lca(n);
	lca.precalculate();
	int q;
	cin >> q;
	while(q--){
		int r,b;
		cin >> r >> b;
		vector<int> red, blue;
		for(int i=0; i<r; i++){
			int x;
			cin >> x;
			red.pb(x);
		}
		for(int i=0; i<b; i++){
			int x;
			cin >> x;
			blue.pb(x);
		}
		int lca_r = red[0];
		int lca_b = blue[0];
		for(int i=1; i<r; i++) lca_r = lca.query(lca_r, red[i]);
		for(int i=1; i<b; i++) lca_b = lca.query(lca_b, blue[i]);
		
		bool ans = true;
		for(int x : red){
			if(lca.distance(x, lca_r) == lca.distance(x, lca_b) + lca.distance(lca_b, lca_r)) ans = false;
		}
		for(int x : blue){
			if(lca.distance(x, lca_b) == lca.distance(x, lca_r) + lca.distance(lca_r, lca_b)) ans = false;
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
