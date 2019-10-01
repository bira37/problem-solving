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
#define INF 2e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
void solve(){
  int n;
  cin >> n;
  int a[n],b[n];
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  int dp[n][4];
  dp[0][0] = 0;
  dp[0][1] = b[0];
  dp[0][2] = 2*b[0];
  dp[0][3] = 3*b[0];
  for(int i=1; i<n; i++){
    for(int j = 0; j<4; j++){
      dp[i][j] = INF;
      for(int k =0; k<4; k++){
        if(a[i]+j != a[i-1]+k) dp[i][j] = min(dp[i][j], dp[i-1][k] + j*b[i]);
      }
    }
  }
  cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3]}) << endl;;
}
int32_t main(){
  DESYNC;
  int q;
  cin >> q;
  while(q--) solve();
}
