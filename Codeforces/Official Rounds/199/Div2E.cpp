#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[112345];
bool removed[112345];
int L[112345], subsz[112345];
int c_p[112345];
int dist[22][112345];
int closest[112345];
int color[112345];
 
void init(int n){
	for(int i=0; i<=n;i++){
		removed[i] = false;
		adj[i].clear();
		L[i] = 0;
		subsz[i] = 1;
		closest[i] = 1123456;
		c_p[i] = -1;
	}
}
 
void centroid_subsz(int u, int p){
	subsz[u]= 1;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v == p || removed[v]) continue;
		centroid_subsz(v,u);
		subsz[u] += subsz[v];
	}
}
 
int find_centroid(int u, int p, int sub){
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v == p || removed[v]) continue;
		if(subsz[v] > subsz[sub]/2){
			return find_centroid(v, u, sub);
		}
	}
	return u;
}
 
void calculate_dists(int u, int p, int d, int centroid){
	dist[L[centroid]][u] = d;
	if(color[u] == 1) closest[centroid] = min(closest[centroid], dist[L[centroid]][u]);
	//cout << "at vertex " << u << "with closest set to " << closest[centroid] << endl;
	//cout << "dist is " << d << endl;
	//cout << "----------------------------" << endl;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v == p || removed[v]) continue;
		calculate_dists(v, u, d+1, centroid);
	}
}
 
int query(int u){
	//cout << "starting query on " << u << " closest " << closest[u] << endl;
	int ans = closest[u];
	int curr = u;
	while(c_p[curr] != -1){
		int p = c_p[curr];
		//cout << "querying for p[u] = " << p << " update " << closest[p] + dist[L[p]][u] << endl;
		ans = min(ans, closest[p] + dist[L[p]][u]);
		curr = c_p[curr];
	}
	return ans;
}
	
void update(int u){
	color[u] = 1;
	closest[u] = 0;
	int curr = u;
	while(c_p[curr] != -1){
		int p = c_p[curr];
		closest[p] = min(closest[p], dist[L[p]][u]);
		curr = p;
	}
}
	
 
void centroid_decomp(int u, int p, int r){
	centroid_subsz(u,-1);
	int centroid = find_centroid(u, -1, u);
	L[centroid] = r;
	c_p[centroid] = p;
	removed[centroid] = true;
	//cout << "centroid is " << centroid << ", closest is " << closest[centroid] << endl;
	//cout << "starting calc" << endl << "----------------------" << endl;
	calculate_dists(centroid,-1, 0, centroid);
	for(int i=0; i<adj[centroid].size(); i++){
		int v = adj[centroid][i];
		if(removed[v]) continue;
		centroid_decomp(v, centroid, r+1);
	}
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	init(n);
	color[1] = 1;
	for(int i=2; i<=n; i++) color[i] = 2;
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid_decomp(1, -1, 0);
	while(q--){
		int a,b;
		cin >> a >> b;
		if(a == 1) update(b);
		else cout << query(b) << endl;
	}
}
