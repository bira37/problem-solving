#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[11234];
int cost[1123];
int dp[1123][11234];

int32_t main(){
  ios_base::sync_with_stdio(false);
  int n,w,b,x;
  scanf("%lld%lld%lld%lld", &n, &w, &b, &x);
  
  for(int i=1; i<=n; i++) scanf("%lld", &c[i]);
  for(int i=1; i<=n; i++) scanf("%lld", &cost[i]);
  
  dp[0][0] = w;
  for(int i=1; i<=10000; i++) dp[0][i] = (long long)-1e18;
  
  int ans = 0;
  
  for(int i=1; i<=n; i++){
    for(int j=0; j<=10000; j++){
      dp[i][j] = (long long)-1e18;
      //cout << "compute (" << i << ", " << j << ")" << endl;
      for(int k = max(0LL ,j - c[i]); k <= j; k++){
        if(dp[i-1][k] < 0) continue;
        //cout << "for k = " << k << endl;
        //cout << dp[i-1][k] << " " << cost[i]*(j-k) << endl;
        dp[i][j] = max(dp[i][j], min(dp[i-1][k], w + b*k) - cost[i]*(j-k));
      }
      if(dp[i][j] >= 0) dp[i][j] = min(dp[i][j]+x, w + b*j);
      if(dp[i][j] >= 0) ans = max(ans, j);
      //cout << "dp of [" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }
  printf("%lld\n", ans);
}