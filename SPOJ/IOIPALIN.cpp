#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string a, b;
  cin >> a;
  b = a;
  reverse(b.begin(), b.end());
  int dp[a.size()+1][b.size()+1];
  dp[0][0] = 0;
  
  int m = b.size();
  for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int i=0; i<=m; i++) dp[0][i] = 0;
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(a[i-1] != b[j-1]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
    }
  }
  
  cout << n - dp[n][n] << endl;
}
