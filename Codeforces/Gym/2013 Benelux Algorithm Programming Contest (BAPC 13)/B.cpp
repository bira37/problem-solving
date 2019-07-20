#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_tuple
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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int cst[17], p[17];
double dp[(1LL<<17)][17];
bool vis[(1LL<<17)][17];
int n,c,m;
 
double solve(int msk, int c){
  if(c == 0) return 1.;
  if(msk == (1LL<<n)-1) return 0;
  if(vis[msk][c]) return dp[msk][c];
  
  dp[msk][c] = 0;
  vis[msk][c] = true;
  int tot = 0;
  for(int i=0; i<n; i++){
    if((1LL<<i) & msk) tot += cst[i];
  }
  
  for(int i=0; i<n; i++){
    if((1LL<<i) & msk) continue;
    if(tot + cst[i] > m) continue;
    dp[msk][c] = max(dp[msk][c], solve(msk | (1LL<<i), c-1)*(p[i]/100.) + solve(msk | (1LL<<i), c)*(1. - (p[i]/100.)));
  }
  
  return dp[msk][c];
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    cin >> n >> c >> m;
    for(int i=0; i<n; i++){
      cin >> cst[i] >> p[i];
    }
    for(int i=0; i<(1LL<<n); i++){
      for(int j=0; j<=n; j++){
        dp[i][j] = 0;
        vis[i][j] = 0;
      }
    }
    cout << solve(0, c) << endl; 
  }
}
 
