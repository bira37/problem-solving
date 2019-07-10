#include <bits/stdc++.h>
#define N 80
#define ff first
#define ss second
 
using namespace std;
 
int n,k;
 
vector< pair<int, int> > adj[N+1];
int dist[N+1][N+1][N+1][N+1];
 
struct state{
	int u, dist, k, l, r;
 
	bool operator<(const state & b) const {
		return dist > b.dist;
	}
};
 
 
bool dijkstra(){
	priority_queue<state> pq;
	for(int i=1; i<=n; i++){
		dist[i][0][1][n] = 0;
		pq.push({i, 0, 0, 1, n});
	}
 
	while(!pq.empty()){
		state atual = pq.top();
		pq.pop();
		if(atual.dist != dist[atual.u][atual.k][atual.l][atual.r]) continue;
		
		if(atual.k == k-1) {
			cout << atual.dist << endl;
			return true;
		}
 
		for(int i=0; i<adj[atual.u].size(); i++){
			int v = adj[atual.u][i].ff;
			int d = adj[atual.u][i].ss;
			if(v < atual.l || v > atual.r) continue;
			
			if(v >= atual.u){
				if(atual.dist + d < dist[v][atual.k+1][atual.u+1][atual.r]){
					dist[v][atual.k+1][atual.u+1][atual.r] = atual.dist + d;
					pq.push({v, atual.dist + d, atual.k+1, atual.u+1, atual.r});
				}
			}
		
			else if(v <= atual.u){
				if(atual.dist + d < dist[v][atual.k+1][atual.l][atual.u-1]){
					dist[v][atual.k+1][atual.l][atual.u-1] = atual.dist + d;
					pq.push({v, atual.dist + d, atual.k+1, atual.l, atual.u-1});
				} 
			}
		}
	}
	
	return false;
}
 
int main(){
	//ios_base::sync_with_stdio(false);
	
	scanf("%d %d", &n, &k);
 
	int m;
	scanf("%d", &m);
	
	for(int i=0; i<=n; i++){
		adj[i].clear();
	
		for(int j=0; j<=n; j++){
			
			for(int l =0; l<=n; l++){
				
				for(int w=0; w<=n; w++){
					
					dist[i][j][l][w] = INT_MAX;
				}
			}
		}
	}
 
	for(int i=0; i<m; i++){
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		adj[x].emplace_back(y,z);
	}
 
	if(!dijkstra()) cout << -1 << endl;
 
}
