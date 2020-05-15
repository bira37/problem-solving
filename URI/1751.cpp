#include <bits/stdc++.h>

using namespace std;

vector<int> adj[112345], adjc[112345];
int dist[112345];
bool vis[112345];

int ans = 0;
int best = 0;
void dfs(int u, int d){
	dist[u] = d;
	if(vis[u]) best = max(dist[u], best);
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		dfs(v,dist[u]+adjc[u][i]);
		vis[u] |= vis[v];
		if(vis[v]) ans += adjc[u][i];
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) dist[i] = 0;
	for(int i=0; i<n-1; i++){
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adjc[u].push_back(c);
	}
	
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		vis[x] = true;
	}
	
	dfs(1,0);
	
	cout << ans - best << endl;
}
