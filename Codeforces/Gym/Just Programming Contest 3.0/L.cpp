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
 
int cst[31234][30];
int tempo[31234][30];
int n,m;
ii dp[31234][30];
 
ii operator+(const ii a, const ii b){
  return ii(a.ff + b.ff, a.ss + b.ss);
}
 
ii go(int pt, int r){
  if(pt == n) return ii(0,0);
  if(dp[pt][r] != ii(-1,-1)) return dp[pt][r];
  //move front
  dp[pt][r] = ii(INF, INF);
  dp[pt][r] = min(dp[pt][r], go(pt+1, r) + ii(cst[pt][r], 0));
  
  //change
  if(r > 0) dp[pt][r] = min(dp[pt][r], go(pt, r-1) + ii(0, tempo[pt][r-1]));
  if(r < m-1) dp[pt][r] = min(dp[pt][r], go(pt, r+1) + ii(0, tempo[pt][r]));
  
  return dp[pt][r];
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i=0; i<=n; i++){
      for(int j=0; j<=m; j++) dp[i][j] = mp(-1,-1);
    }
    for(int i=0; i<n; i++){
      for(int j = 0; j<m; j++){
        cin >> cst[i][j];
      }
    }
    for(int i=0; i<n; i++){
      for(int j = 0; j<m-1; j++){
        cin >> tempo[i][j];
      }
    }
    ii ans = go(0,0);
    cout << ans.ff << " " << ans.ss << endl;
  }
}
 
