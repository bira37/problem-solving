#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int,int>
 
using namespace std;
 
vector<int> adj[112345];
double prob[112345];
int dist[112345];
bool vis[112345];
double acc = 0.0;
int leaf = 0;
bool mark[112345];
 
void dfs(int u, int d){
	int cont = 0;
	vis[u] = true;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v]) continue;
		cont++;
	}
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v]) continue;
		dist[v] = d+1;
		if(d!= 0) prob[v] = prob[u]*(1/(cont*1.0));
		else prob[v] = (1/(cont*1.0));
		dfs(v, d+1);
	}
	if(cont == 0) mark[u] = true;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		adj[i].clear();
		prob[i] = 0;
		dist[i] = 0;
		vis[i] = false;
		mark[i] = false;
	}
	
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	dfs(1,0);
 
	double ans = 0.0;
	for(int i=1; i<=n; i++){
		if(mark[i]) ans += prob[i]*dist[i];
	}
	cout << fixed << setprecision(15) << ans << endl;
	
}
