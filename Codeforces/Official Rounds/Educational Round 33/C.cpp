#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> adj[112345];
int c[112345];
int minimal;
bool vis[112345];

void dfs(int u){
	vis[u] = true;
	minimal = min(minimal, c[u]);
	for(int v : adj[u]){
		if(vis[v]) continue;
		dfs(v);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> c[i+1];
		vis[i+1] = false;
	}
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		minimal = (int)1e9+1;
		dfs(i);
		ans += minimal;
	}
	cout << ans << endl;
}		