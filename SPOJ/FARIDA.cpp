#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
  int t;
  cin >> t;
  int test = 1;
  while(t--){
    cout << "Case " << test++ << ": ";
    int n;
    cin >> n;
    int v[n];
    int dp[n];
    if(n == 0){
      cout << 0 << endl;
      continue;
    }
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    dp[0] = v[0];
    if(n > 1) dp[1] = max(v[0], v[1]);
    for(int i=2; i<n; i++){
      dp[i] = max(dp[i-1], dp[i-2] + v[i]);
    }
    cout << dp[n-1] << endl;
  }
}
