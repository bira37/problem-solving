#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[112345], adjc[112345];
bool vis[112345], removed[112345];
int rnk[112345], subsz[112345];
 
void init(int n){
	for(int i=0; i<=n;i++){
		vis[i] = removed[i] = false;
		adj[i].clear();
		rnk[i] = 0;
		adjc[i].clear();
		subsz[i] = 1;
	}
}
 
void dfs_sub(int u, int p){
	subsz[u]= 1;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v == p || removed[v]) continue;
		dfs_sub(v,u);
		subsz[u] += subsz[v];
	}
}
 
int find_centroid(int u, int p, int sub){
	//cout << "achando por " << u << "na sub de " << sub << endl;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		//cout << "vizinho " << v << endl;
		if(v == p || removed[v]) continue;
		if(subsz[v] > subsz[sub]/2){
			return find_centroid(v, u, sub);
		}
	}
	return u;
}
 
void centroid_decomp(int u, int r){
	dfs_sub(u,-1);
	int centroid = find_centroid(u, -1, u);
	rnk[centroid] = r;
	//cout << centroid << endl;
	removed[centroid] = true;
	for(int i=0; i<adj[centroid].size(); i++){
		int v = adj[centroid][i];
		if(removed[v]) continue;
		centroid_decomp(v,r+1);
	}
}
 
 
int main(){
	int n;
	cin >> n;
	init(n);
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid_decomp(1, 0);
	for(int i=1; i<=n; i++){
		if(rnk[i] > 25){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	
	for(int i=1; i<=n; i++){
		if(i > 1) cout << " ";
		cout << char('A'+rnk[i]);
	}
	cout << endl;
}
