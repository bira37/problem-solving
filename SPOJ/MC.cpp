#include <bits/stdc++.h>

using namespace std;

int dp[6006][6006];

int main(){

  string a, b;
  
  while(cin >> a, a != "#"){
    cin >> b;
    dp[0][0] = 0;
    
    int n = a.size(), m = b.size();
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;
    
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(a[i-1] != b[j-1]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      }
    }
    
    int ans = dp[n][m];
    if(ans > 0) cout << (a.size() - dp[n][m])*15 + (b.size() - dp[n][m])*30 << endl;
    else cout << a.size()*15 + b.size()*30 << endl;
    
  }
  
}
