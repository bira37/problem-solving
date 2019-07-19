#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int h[2][n+1];
  int dp[2][n+1];
  for(int i=0; i<2; i++){
    dp[i][0] = -INF;
    for(int j=1; j<=n; j++){
      cin >> h[i][j];
      dp[i][j] = -INF;
    }
  }
  dp[0][1] = h[0][1];
  dp[1][1] = h[1][1];
  for(int j=2; j<=n; j++){
    dp[0][j] = max(dp[0][j], dp[0][j-1]);
    dp[0][j] = max(dp[0][j], dp[1][j-1] + h[0][j]);
    
    dp[1][j] = max(dp[1][j], dp[1][j-1]);
    dp[1][j] = max(dp[1][j], dp[0][j-1] + h[1][j]);
    //cout << dp[0][j] << " " << dp[1][j] << endl;
  }
  cout << max(dp[0][n], dp[1][n]) << endl;
}
 
