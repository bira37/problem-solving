#include <bits/stdc++.h>

using namespace std;

struct par{
	int v;
	int d;
};

bool operator<(par x, par y) {
		if(x.d <= y.d) return false;
		else return true; 
}

vector <int> adj[1002];
vector <int> adj_cost[1002];
int dist[1002];


void calculaMenorDist(int n){
	priority_queue <par> q;
	par vertice;
	vertice.v = n;
	vertice.d=0;
	dist[n]=0;
	q.push(vertice);
	while(!q.empty()){
		par vertice = q.top();
		q.pop();
		if(dist[vertice.v] > vertice.d) continue;
		for(int i=0; i< adj[vertice.v].size(); i++){
			if(dist[vertice.v]+adj_cost[vertice.v][i] < dist[adj[vertice.v][i]]){
				dist[adj[vertice.v][i]] = dist[vertice.v]+adj_cost[vertice.v][i];
				par x;
				x.v = adj[vertice.v][i];
				x.d = dist[adj[vertice.v][i]];
				q.push(x);
			}
		}
	}
}
	

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0; i <= n+1; i++){
		adj[i].clear();
		adj_cost[i].clear();
		dist[i]=0x3f3f;
	}
	for(int i=0;i<m;i++){
		int a,b,cost;
		cin >> a >> b >> cost;
		adj[a].push_back(b);
		adj_cost[a].push_back(cost);
		adj[b].push_back(a);
		adj_cost[b].push_back(cost);
	}
	calculaMenorDist(0);
	cout << dist[n+1] << endl;
}
		
	

