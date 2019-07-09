#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[200001];
bool vis[200001];
int color[200001];
vector<int> visitados;
 
int num;
int countColor[200001];
 
void dfs(int n){
	vis[n] = true;
	num++;
	//cout << "visiting " << n << " with " << num << " vertex connecteds" << endl;
	countColor[color[n]]++;
	visitados.push_back(color[n]);
	for(int i=0; i< adj[n].size(); i++){
		if(vis[adj[n][i]]) continue;
		dfs(adj[n][i]);
	}
}
	
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		adj[i].clear();
		vis[i] = false;
		cin >> color[i];
	}
 
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
 
	long long ans = 0;
 
	for(int i=1; i<= k; i++) countColor[i] = 0;
 
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		num = 0;
		visitados.clear();
		dfs(i);
		
		int maxColor = 0;
		for(int j=0, len = visitados.size(); j<len; j++){
			maxColor = max(maxColor, countColor[visitados[j]]);
		}
		ans += (num - maxColor);
 
		for(int j=0, len = visitados.size(); j< len; j++) countColor[visitados[j]] = 0;
		
	}
 
	cout << ans << endl;
}
