

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
#define INF 2e17
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
  int n,m,k;
  cin >> n >> m >> k;
  int dp[n+1][m+1];
  int x;
  for(int j=0; j<=n; j++){
    for(int i=0; i<=m; i++) dp[j][i] = -INF;
    dp[j][m] = 0;
  }
  int ans = 0LL;
  for(int i=1; i<=n; i++){
    cin >> x;
    for(int j=1; j<=m; j++){
      if(j == 1) dp[i][j] = max(dp[i-1][m] + x, x) - k;
      else dp[i][j] = dp[i-1][j-1] + x;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;

