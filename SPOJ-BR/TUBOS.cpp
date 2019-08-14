#include <bits/stdc++.h>

using namespace std;

int cont = 0;
int st[1001];
int low[1001];
int bridge = 0;
vector<int> adj[1001];

void tarjan(int u, int p){
	st[u] = low[u] = ++cont;
	for(int i=0; i<adj[u].size(); i++){
		if(adj[u][i]==p){
			p = 0;
			continue;
		}
		if(!st[adj[u][i]]) tarjan(adj[u][i], u);
		low[u] = min(low[u], low[adj[u][i]]);
		if(low[adj[u][i]] > st[u]){
			bridge++;
		}
	}
}

int main(){
	
	int n,m;
	while( cin >> n >> m, n+m !=0){
		bridge = 0;
		cont = 0;
		for(int i=1; i<=n; i++){
			low[i] = 0;
			st[i] = 0;
			adj[i].clear();
		}
		
		for(int i=0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	
		tarjan(1,0);
	
		if(bridge) cout << "N" << endl;
		else cout << "S" << endl;
	}
}
	
