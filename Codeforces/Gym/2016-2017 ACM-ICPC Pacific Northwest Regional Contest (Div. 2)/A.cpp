#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int n = s.size();
  s = '0' + s;
  int dp[n+1];
  
  dp[0] = 0;
  int mx = 0;
  for(int i=1; i<=n; i++){
    dp[i] = 0;
    for(int j=0; j<=i-1; j++) if(s[i] > s[j]) dp[i] = max(dp[i], dp[j]+1);
    mx = max(dp[i], mx);
  }
  
  cout << 26 - mx << endl;
}
