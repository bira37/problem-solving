#include <bits/stdc++.h>

using namespace std;

struct par{
	int v,d;
};

struct cmp{
	
	bool operator()(const par & a, const par & b){
		return a.d > b.d;
	}
};

vector<par> adj[101];

int dist[101];

void dijkstra(int ini, int fim){
	priority_queue<par, vector<par>, cmp> q;
	par aux = {ini, 0};
	q.push(aux);
	while(!q.empty()){
		par atual = q.top();
		q.pop();
		if(dist[atual.v] != INT_MAX) continue;
		dist[atual.v] = atual.d;
		for(int i=0; i<adj[atual.v].size(); i++){
			if(adj[atual.v][i].d + atual.d <= dist[adj[atual.v][i].v]){
				par aux = {adj[atual.v][i].v, atual.d+adj[atual.v][i].d};
				q.push(aux);
			}
		}
	}
}

int main(){
	
	int n,m;
	while(cin >> n >> m, n + m !=0){
		for(int i=1; i<=n; i++){
			dist[i] = INT_MAX;
			adj[i].clear();
		}
	
		for(int i=0; i<m; i++){
			int x,y,z;
			cin >> x >> y >> z;
			par aux = {y,z};
			adj[x].push_back(aux);
		}
	
		int i,f;
		cin >> i >> f;
		dijkstra(i,f);
		cout << (dist[f] == INT_MAX ? -1 : dist[f]) << endl;
	}
}
