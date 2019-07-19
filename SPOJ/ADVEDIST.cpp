#include <bits/stdc++.h>
#define INF 1e9
#define int long long
using namespace std;  

int32_t main() {

    string a,b;
    
    while(cin >> a >> b, a != "*" && b != "*"){

      int n = a.size();
      int m = b.size();

      int dp[n+2][m+2];

      dp[0][0] = INF;

      for(int i=0; i<=n; i++){
        dp[i+1][1]=i;
        dp[i+1][0]=INF;
      }

      for(int j=0; j<=m; j++){
        dp[1][j+1]=j;
        dp[0][j+1]=INF;
      }

      int da[250];

      for(int d=0;d<250;d++) da[d]=0;
     
      for(int i=1; i<=n; i++){
      
        int db=0;
             
        for(int j=1; j<=m; j++){
        
          int ii = da[b[j-1]];
       
          int jj = db;
       
          int d = (a[i-1] != b[j-1]);
       
          if(d==0) db = j;
          
          dp[i+1][j+1] = INF;
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + d);
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + 1);
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[ii][jj] + (i - ii - 1) + (j - jj - 1) +  1);
        }
       
        da[a[i-1]]=i;
        
      }

    cout << dp[n+1][m+1] << '\n';
         
  }
    
}
