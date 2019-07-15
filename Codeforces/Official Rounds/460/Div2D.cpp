#include <bits/stdc++.h>

using namespace std;

vector<int> adj[312345];
int dg[312345] = {0};
int l[312345];
int vis[312345] = {0};


bool dfs(int u){
	vis[u] = 1;
	bool ok = true;
	for(int v : adj[u]){
		if(vis[v] == 1) ok = ok & false;
		if(vis[v] == 0) ok = ok & dfs(v);
	}
	vis[u] = 2;
	return ok;
}

int main(){
  int n,m;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    char c;
    cin >> c;
    l[i] = (c - 'a');
  }
  for(int i=0; i<m; i++){
    int u,v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    dg[v]++;
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
		if(!vis[i]){
			if(!dfs(i)){
				cout << -1 << endl;
				return 0;
			}
		}
	}
  for(int c = 0; c<26; c++){
    queue<int> q;
    int dp[n+1];
		int deg[n+1];
    for(int i=1; i<=n; i++){
      dp[i] = 0;
			deg[i] = dg[i];
      if(dg[i] == 0){
        q.push(i);
        dp[i] = (l[i] == c);
      }
    }
    
    while(!q.empty()){
      int u = q.front();
      q.pop();
      ans = max(ans, dp[u]);
      for(int v : adj[u]){
        if(dp[u] + (l[v] == c) > dp[v]){
          dp[v] = dp[u] + (l[v] == c);
        }
				deg[v]--;
				if(deg[v] == 0) q.push(v);
      }
    }
  }
  printf("%d\n", ans);
}