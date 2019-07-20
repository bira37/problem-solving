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
#define M 998244353
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int dp[1123][4];
 
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
  for(int i=1; i<=m-1; i++){
    dp[i][0] = mod(dp[i-1][0] + dp[i-1][1], M);
    dp[i][1] = mod(dp[i-1][0] + dp[i-1][1], M);
    dp[i][2] = mod(dp[i-1][2] + dp[i-1][3], M);
    dp[i][3] = mod(dp[i-1][2] + dp[i-1][3], M);
  }
  int ans = mod(dp[m-1][0] + dp[m-1][1] + dp[m-1][2] + dp[m-1][3], M);
  for(int i=2; i<=n; i++) ans = mod(ans*2LL, M);
  cout << ans << endl;
      
  
}
 
