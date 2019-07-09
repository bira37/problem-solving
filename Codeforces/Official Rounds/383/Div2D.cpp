#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[1001];
vector<int> group[1001];
bool vis[1001];
int weight[1001];
int beauty[1001];
int k=0;
 
pair<int, int> groupSize[1001];
 
void dfs(int n){
 
	vis[n] = true;
	groupSize[k].first += weight[n];
	groupSize[k].second += beauty[n];
	group[k].push_back(n);
 
	for(int i=0; i< adj[n].size(); i++){
		if(vis[adj[n][i]]) continue;
		dfs(adj[n][i]);
	}
}
 
int main(){
	int n,m,w;
	cin >> n >> m >> w;
	for(int i=0; i<=n; i++){
		vis[i] = false;
		weight[i] = 0;
		beauty[i] = 0;
		group[i].clear();
		adj[i].clear();
		groupSize[i].first = 0;
		groupSize[i].second = 0;
	}
	
	for(int i=1; i<=n; i++){
		cin >> weight[i];
	}
	
	for(int i=1; i<=n; i++){
		cin >> beauty[i];
	}
 
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		++k;
		dfs(i);
	}
 
	int dp[k+1][w+1];
	for(int i=0; i<=k; i++) dp[i][0] = 0;
	for(int i=0; i<=w; i++) dp[0][i] = 0;
	
	for(int i=1; i<=k; i++){
		
		for(int j=1; j <= w; j++){
			dp[i][j] = dp[i-1][j];
			if(groupSize[i].first <= j){
				dp[i][j] = max(dp[i][j], dp[i-1][j-groupSize[i].first] + groupSize[i].second);
			}
			for(int wa=0, len = group[i].size(); wa<len; wa++){
				if(weight[group[i][wa]] <= j){
					dp[i][j] = max(dp[i][j], dp[i-1][j -weight[group[i][wa]]] + beauty[group[i][wa]]);
				}
			}
		}
	}
 
	int ans = 0;
	for(int i=0; i<=w; i++){
		ans = max(ans, dp[k][i]);
	}
	
	cout << ans << endl;
}
