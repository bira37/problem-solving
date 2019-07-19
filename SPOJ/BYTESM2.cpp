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
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    int mat[n][m];
    int dp[n][m];
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++) cin >> mat[i][j];
    }
    for(int i=0; i<m; i++){
      dp[0][i] = mat[0][i];
    }
    for(int i=1; i<n; i++){
      for(int j=0; j < m; j++){
        int a = -INF;
        int b = -INF;
        int c = -INF;
        if(j-1 >= 0) a = dp[i-1][j-1];
        if(j >= 0) b = dp[i-1][j];
        if(j+1 < m) c = dp[i-1][j+1];
        
        dp[i][j] = max({a,b,c}) + mat[i][j];
      }
    }
    int ans = 0;
    for(int i=0; i<m; i++) ans = max(ans, dp[n-1][i]);
    cout << ans << endl;
  }
}


