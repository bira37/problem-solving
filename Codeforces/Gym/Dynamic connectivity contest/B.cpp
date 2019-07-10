#include <bits/stdc++.h>
#define endl '\n'
#define N 112345
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
 
int tempo = 0;
int st[N];
int ed[N];
int vis[N];
int dad[N];
int anc[20][N];
int lift[112345];
int L[112345];
 
int ans = 0;
 
int uf[112345], sz[112345];
 
vector<int> adj[112345];
 
bool a[112345], b[112345];
 
void dfs_makedad(int u){
	vis[u] = true;
	st[u] = tempo++;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dad[v] = u;
			L[v] = L[u]+1;
			dfs_makedad(v);
		}
	} 
	ed[u] = tempo++;
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
 
void pre_process(int n){
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		dad[i] = -1;
		L[i] = 0;
		dfs_makedad(i);
	}
	for(int i=1; i<=n; i++){
		anc[0][i] = dad[i];
	}
	for(int i=1; i<20; i++){
		for(int j=1; j<=n; j++){
				if(anc[i-1][j] != -1){
					anc[i][j] = anc[i-1][anc[i-1][j]];
				}
				else {
					anc[i][j] = -1;
				}
		}
	}
}
 
void init(int n){
	for(int i=0; i<=n; i++){
		vis[i] = false;
		uf[i] = i;
		sz[i] = 1;
		lift[i] = i;
	}
}
 
int find(int u){
	if(uf[u] == u) return u;
	else return uf[u] = find(uf[u]);
}
 
void merge(int u, int v){
	int a = find(u);
	int b = find(v);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a,b);
	sz[a]+=sz[b];
	uf[b] = a;
}
 
void build_st(vector< pii > & e, vector< pii > & q){
	for(int i=0; i<e.size(); i++){
		if(find(e[i].ff) == find(e[i].ss)){
			a[i] = false;
		}
		else {
			a[i] = true;
			adj[e[i].ff].push_back(e[i].ss);
			adj[e[i].ss].push_back(e[i].ff);
			merge(e[i].ff, e[i].ss);
		}
	}
	for(int i=0; i<q.size(); i++){
		if(find(q[i].ff) == find(q[i].ss)){
			b[i] = false;
		}
		else {
			b[i] = true;
			adj[q[i].ff].push_back(q[i].ss);
			adj[q[i].ss].push_back(q[i].ff);
			merge(q[i].ff, q[i].ss);
		}
	}
}
 
int path_compression(int u){
	if(lift[u] == u) return u;
	else return lift[u] = path_compression(lift[u]);
}
 
int solve(int u, int lc){
	u = path_compression(u);
	if(is_ancestor(lc, u) && u != lc){
		ans--;
		lift[u] = solve(dad[u], lc);
	}
	else return u;
}
 
void remove(int u, int v){
	int lc = lca(u,v);
	//cout << "starting" << endl;
	//cout << "lca of " << u << " and " << v << " is " << lca(u,v) << endl;
	int x = u;
	int y = v;
	int aux;
	solve(u,lc);
	solve(v, lc);
	/*while(true){
		x = path_compression(x);
		if(is_ancestor(lc, x) && dad[x] != -1 && x != lc){
			aux = x;
			x = dad[x];
			lift[aux] = lc;
			ans--;
		}
		else break;
	}
	while(true){
		//cout << "climbing " << y << " dad is " << dad[y] << " lift is " << lift[y] << endl;
		if(lift[y] != -1 && lift[y] != y){
			if(is_ancestor(lc, lift[y])){
				aux = y;
				y = lift[y];
				lift[aux] = lc;
			}
			else break;
		}
		else {
			if(dad[y] == -1) break;
			if(y == lc) break;
			aux = y;
			y = dad[y];
			lift[aux] = lc;
			ans--;
		}
		//cout << "climbed to " << y << endl;
	}*/
	//cout << "finishing" << endl << endl;
}
 
vector< pii > e(112345);
vector< pii > q(112345);
 
int main(){
	ifstream cin("bridges.in");
	ofstream cout("bridges.out");
	int n,m;
	cin >> n >> m;
	init(n);
	for(int i=0; i<m; i++){
		cin >> e[i].ff >> e[i].ss;
	}
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> q[i].ff >> q[i].ss;
	}
	build_st(e,q);
	pre_process(n);
	int aa;
	ans = 0;
	for(int i=0; i<m; i++){
		//cout << "solve for " << e[i].ff << " " << e[i].ss << endl;
		if(e[i].ff == e[i].ss) continue;
		if(a[i]) ans++;
		else remove(e[i].ff, e[i].ss);
		//cout << ans << endl;
	}
	for(int i=0; i<k; i++){
		//cout << "solve for " << q[i].ff << " " << q[i].ss << endl;
		if(q[i].ff == q[i].ss){
			cout << ans << endl;
			continue;
		}
		if(b[i]) ans++;
		else remove(q[i].ff, q[i].ss);
		cout << ans << endl;
	}
}
