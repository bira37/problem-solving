#include <bits/stdc++.h>

using namespace std;

vector<int> adj[112345];
bool removed[112345];
int L[112345], subsz[112345];
int c_p[112345];
int dist[22][112345];
multiset<int> closest[112345];
int color[112345];

void init(int n){
	for(int i=0; i<=n;i++){
		removed[i] = false;
		adj[i].clear();
		L[i] = 0;
		subsz[i] = 1;
		closest[i].insert(1123456);
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
	if(color[u] == 1) closest[centroid].insert(dist[L[centroid]][u]);
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v == p || removed[v]) continue;
		calculate_dists(v, u, d+1, centroid);
	}
}

int query(int u){
	int ans = *closest[u].begin();
	int curr = u;
	while(c_p[curr] != -1){
		int p = c_p[curr];
		ans = min(ans, *closest[p].begin() + dist[L[p]][u]);
		curr = c_p[curr];
	}
	return ans;
}
	
void update_insert(int u){
	color[u] = 1;
	closest[u].insert(dist[L[u]][u]);
	int curr = u;
	while(c_p[curr] != -1){
		int p = c_p[curr];
		closest[p].insert(dist[L[p]][u]);
		curr = p;
	}
}

void update_remove(int u){
	color[u] = 2;
	closest[u].erase(closest[u].find(dist[L[u]][u]));
	int curr = u;
	while(c_p[curr] != -1){
		int p = c_p[curr];
		closest[p].erase(closest[p].find(dist[L[p]][u]));
		curr = p;
	}
}
	

void centroid_decomp(int u, int p, int r){
	centroid_subsz(u,-1);
	int centroid = find_centroid(u, -1, u);
	L[centroid] = r;
	c_p[centroid] = p;
	removed[centroid] = true;
	calculate_dists(centroid,-1, 0, centroid);
	for(int i=0; i<adj[centroid].size(); i++){
		int v = adj[centroid][i];
		if(removed[v]) continue;
		centroid_decomp(v, centroid, r+1);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin >> n;
	init(n);
	for(int i=1; i<=n; i++) color[i] = 2;
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid_decomp(1, -1, 0);
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		if(a == 0){
			if(color[b] == 1) update_remove(b);
			else update_insert(b);
		}
		else {
			int ans = query(b);
			if(ans == 1123456) cout << -1 << endl;
			else cout << ans << endl;
		}
	}
}
