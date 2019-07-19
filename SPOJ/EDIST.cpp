#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    string a,b;
    cin >> a >> b;
    int dp[a.size()+1][b.size()+1];
    int n = a.size(), m = b.size();
    for(int i=0; i<=b.size(); i++) dp[0][i] = i;
    for(int i=0; i<=a.size(); i++) dp[i][0] = i;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
      }
    }
    cout << dp[a.size()][b.size()] << endl;
  }
}
