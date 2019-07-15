#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int g[312345];
vector<int> adj[312345];
vector<int> cst[312345];
int dp[312345];

int ans = 0;

void go(int u, int p){
  vector<int> paths;
  dp[u] = g[u];
  ans = max(ans, g[u]);
  for(int i=0; i<adj[u].size(); i++){
    int v = adj[u][i];
    int c = cst[u][i];
    if(v == p) continue;
    go(v, u);
    if(dp[v]  - c > 0){
      dp[u] = max(dp[u], dp[v] - c + g[u]);
      paths.pb(dp[v] - c);
    } 
  }
  sort(paths.begin(), paths.end(), greater<int>());
  for(int x : paths) ans = max(ans, x + g[u]);
  if(paths.size() >= 2) ans = max(ans, paths[0] + paths[1] + g[u]);
}
    
int32_t main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> g[i+1];
  for(int i=0; i<n-1; i++){
    int u,v,c;
    cin >> u >> v >> c;
    adj[u].pb(v);
    adj[v].pb(u);
    cst[u].pb(c);
    cst[v].pb(c);
  }
  
  go(1, 0);
  
  cout << ans << endl;
}