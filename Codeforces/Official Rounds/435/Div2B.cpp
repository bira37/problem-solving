#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[112345];
bool vis[112345];
int group[2];
int where[112345];
 
void dfs(int u, int g){
	vis[u] = true;
	where[u] = g;
	group[g]++;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v])  continue;
		if(g == 1) dfs(v, 0);
		else dfs(v,1);
	}
}
 
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		adj[i].clear();
		vis[i] = false;
		group[0] = group[1] = 0;
	}
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	dfs(1, 0);
	for(int i=1; i<=n; i++){
		if(where[i] == 0) ans += adj[i].size();
	}
	cout << (long long)group[0]*(long long)group[1] - (long long)ans << endl;
}
