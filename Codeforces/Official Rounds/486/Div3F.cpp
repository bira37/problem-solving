#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main(){
  int a,n,m;
  cin >> a >> n >> m;
  int umbrella[a+1];
  int w[m+1];
  bool rain[a+1];
  for(int i=0; i<=a; i++){
    umbrella[i] = -1;
    rain[i] = false;
  }
  
  int dp[a+1][m+1];
  for(int i=0; i<=a; i++){
    for(int j=0; j<=m; j++){
      dp[i][j] = (int)1e9;
    }
  }
  
  for(int i=0; i<n; i++){
    int l, r;
    cin >> l >> r;
    for(int k = l ; k<r; k++){
      rain[k] = true;
    }
  }
  for(int i=1; i<=m; i++){
    int x;
    cin >> x >> w[i];
    if(umbrella[x] == -1) umbrella[x] = i;
    else if(w[i] < w[umbrella[x]]) umbrella[x] = i;
  }
  
  dp[0][0] = 0;
  
  for(int i=0; i<a; i++){
    for(int j=0; j<=m; j++){
      if(dp[i][j] == (int)1e9) continue;
      if(j != 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + w[j]);
      if(!rain[i]) dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
      if(umbrella[i] != -1) dp[i+1][umbrella[i]] = min(dp[i+1][umbrella[i]], dp[i][j] + w[umbrella[i]]);
    }
  }
  
  int ans = (int)1e9;
  for(int i=0; i<=m; i++){
    ans = min(ans, dp[a][i]);
  }
  
  if(ans >= (int)1e9) cout << -1 << endl;
  else cout << ans << endl;
}
