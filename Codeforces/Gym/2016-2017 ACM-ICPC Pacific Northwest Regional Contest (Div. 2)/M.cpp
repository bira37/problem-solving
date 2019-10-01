#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  
  int dp[n][2];
  
  dp[0][0] = 1;
  dp[0][1] = 1;
  
  int mx = 1;
  for(int i=1; i<n; i++){
    dp[i][1] = 1;
    dp[i][0] = 1;
    for(int j=0; j<i; j++){
      if(v[i] > v[j]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
      if(v[i] < v[j]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
    }
    mx = max(mx, max(dp[i][0], dp[i][1]));
  }
  cout << mx << endl;
  
}
