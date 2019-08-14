#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

vector<int> adj[210];
bool vis[210];
int pi[210];
int capacity[210][210];
int source,sink,flow;

void ford_fulkerson(){
	bool improving = true;
	while(improving){
		
		for(int i=0; i<210; i++){
			vis[i] = false;
			pi[i] = -1;
		}
		
		queue< pii > q;
		q.push(pii(source,INT_MAX));
		int bottleneck = 0;
		while(!q.empty()){
			pii u = q.front();
			//cout << "used " << pi[u.ff] << "->" << u.ff << "capacity " << capacity[pi[u.ff]][u.ff] << endl;
			q.pop();
			if(vis[u.ff]) continue;
			vis[u.ff] = true;
			if(u.ff == sink){
				bottleneck = u.ss;
				break;
			}
			
			for(int i=0; i<adj[u.ff].size(); i++){
				int v = adj[u.ff][i];
				if(vis[v]) continue;
				//cout << u.ff << " " << v << " " << capacity[u.ff][v] << endl;
				if(!capacity[u.ff][v]) continue;
				pi[v] = u.ff;
				q.push(pii(v, min(u.ss, capacity[u.ff][v])));
			}
		}
				
		if(pi[sink] == -1){
			improving = false;
			continue;
		}
	
		int curr = sink;
		while(pi[curr] != -1){
			capacity[pi[curr]][curr]-=bottleneck;
			capacity[curr][pi[curr]]+=bottleneck;
			curr = pi[curr];
		}
		flow+=bottleneck;
	}
}

int main(){
	int m,n,k, t=0;
	while(cin >> m >> n >> k){
		source = 0;
		sink = m+n+1;
		flow = 0;
		for(int i=0; i<210; i++){
			adj[i].clear();
			for(int j=0; j<210; j++) capacity[i][j] = 0;
		}

		int cap[m+1];

		for(int i=1; i<=m; i++){
			cin >> cap[i];
		}
		for(int i=0; i<k; i++){
			int u,v;
			cin >> v >> u;
			adj[u].push_back(v+n);
			adj[v+n].push_back(u);
			capacity[u][v+n]++;
		}
		for(int i=1; i<=n; i++){
			adj[source].push_back(i);
			capacity[source][i]++;
		}
		for(int i=1; i<=m; i++){
			adj[i+n].push_back(sink);
			capacity[i+n][sink]+=cap[i];
		}
		ford_fulkerson();
	
		cout << "Instancia " << ++t << endl;
		cout << flow << endl;
	}
}
