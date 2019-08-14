#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define N 510
#define V first
#define C second
#define oo 0x3f3f3f3f

vector< ii > adj[N];
int vis[N];
int n;

struct State {
	int v, dist;
	bool operator<(const State& rhs) const {
		return dist > rhs.dist;
	}
};

int uf[N];
int sz[N];
void init() {
	for(int i = 1; i <= n; i++) {
		uf[i] = i;
		sz[i] = 1;
	}
}
int find(int x) {
	return (uf[x] != x ? find(uf[x]) : x);
}
void merge(int x, int y) {
	int ux = find(x);
	int uy = find(y);
	// cout << "ux " << ux << " uy " << uy << endl; 

	if(ux < uy) swap(ux,uy);

	uf[uy] = ux;
	sz[ux] += sz[uy];
}

int dfs(int v) {
	vis[v] = 1;
	// cout << v << endl;

	int cicle = 0;
	for(int i = 0; i < adj[v].size(); i++) {
		ii ad = adj[v][i];
		if(!vis[ad.V]) {
			cicle = dfs(ad.V);
			if(cicle) {
				if(find(v) != find(ad.V)) {
					merge(v, ad.V);
				} else cicle = 0;
			}
		} else if(vis[ad.V] == 1) {
			if(find(v) != find(ad.V)) {
				merge(v,ad.V);
			}
		}
		// cout << v << " " << ad.V << endl;
		// cout << find(v) << " " << find(ad.V) << endl << endl;
	}
	vis[v] = 2;

	return cicle;
}

int main() {

	int m;
	while(cin >> n >> m, n) {

		for(int i = 1; i <= n; i++) adj[i].clear();
		for(int i = 0; i < m; i++) {
			int a,b,c; cin >> a >> b >> c;
			adj[a].push_back(ii(b,c));
		}

		init();

		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) dfs(i);
		}

		int k; cin >> k;
		for(int i = 0; i < k; i++) {
			int s,d; cin >> s >> d;

			int dist[n+1];
			for(int i = 1; i <= n; i++) dist[i] = oo;

			priority_queue<State> pq; pq.push({s, 0});
			dist[s] = 0;

			while(!pq.empty()) {
				State cur = pq.top(); pq.pop();

				if(cur.dist > dist[cur.v]) continue;

				// cout << adj[cur.v].size() << endl;
				for(int i = 0; i < adj[cur.v].size(); i++) {
					ii ad = adj[cur.v][i];
						// cout << ad.V << " " << dist[ad.V] << endl;

					if(dist[cur.v] + (find(cur.v) == find(ad.V) ? 0 : ad.C) < dist[ad.V]) {
						dist[ad.V] = dist[cur.v] + (find(cur.v) == find(ad.V) ? 0 : ad.C);
						// cout << ad.V << " " << dist[ad.V] << endl;
						pq.push({ad.V, dist[ad.V]});
					}
				}
			}

			if(dist[d] < oo)
				cout << dist[d] << "\n";
			else
				cout << "Nao e possivel entregar a carta" << "\n";
		}
		cout << "\n";

	}
}
