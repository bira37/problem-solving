#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int mat[550][550];
int dp[550][550];
       
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> mat[i][j];
        dp[i][j] = -1;
      }
    }
    int l = 1, r = 10000000000;
    int ans = -1;
    while(l <= r){
      int mid = (l+r)>>1;
      
      for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
          dp[i][j] = -1;
        }
      }
      
      dp[0][0] = mid;
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          //at i,j
          if(dp[i][j] == -1) continue;
          if(i +1 < n){
            int val  = dp[i][j] + mat[i+1][j];
            if(val > 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + mat[i+1][j]);
          }
          if(j + 1 < m){
            int val = dp[i][j] + mat[i][j+1];
            if(val > 0) dp[i][j+1] = max(dp[i][j+1], dp[i][j] + mat[i][j+1]);
          }
        }
      }
      
      if(dp[n-1][m-1] > 0){
        ans = mid;
        r = mid-1;
      }
      else l = mid+1;
    }
    
    cout << ans << endl;        
  }       
}


