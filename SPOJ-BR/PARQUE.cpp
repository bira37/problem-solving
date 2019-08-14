#include <bits/stdc++.h>

using namespace std;

int main(){
  string a, b;
  int teste = 1;
  while(cin >> a, a != "#"){
    cin >> b;
    int dp[a.size()+1][b.size()+1];
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
    
    int x = n, y = m;
    string ans;
    while(x > 0 || y > 0){
      if(x == 0 && y > 0){
        ans += b[y-1];
        y--;
      }
      else if(y == 0 && x > 0){
        ans += a[x-1];
        x--;
      }
      else if(a[x-1] == b[y-1]){
        ans += a[x-1];
        x--,y--;
      }
      else if(dp[x-1][y] > dp[x][y-1]){
        ans += a[x-1];
        x--;
      }
      else {
        ans += b[y-1];
        y--;
      }
    }
    reverse(ans.begin(), ans.end());
    cout << "Teste " << teste++ << endl << ans << endl << endl;
  }
  
}
