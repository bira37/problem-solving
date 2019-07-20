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

int dp[55][55][110];
int v[55];

int solve(int l, int r, int k){
  if(r < l) return 0;
  if(k == 0) return 0;
  if(dp[l][r][k] != -INF) return dp[l][r][k];
  
  dp[l][r][k] = solve(l+1, r, k-1) + v[l];
  if(k >= 2) dp[l][r][k] = max(dp[l][r][k], solve(l+1, r, k-2));
  dp[l][r][k] = max(dp[l][r][k], solve(l, r-1, k-1) + v[r]);
  if(k >= 2) dp[l][r][k] = max(dp[l][r][k], solve(l, r-1, k-2));
  return dp[l][r][k];
}

int32_t main(){
  DESYNC;
  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int x=0; x <= k; x++) dp[i][j][x] = -INF;
    }
  }
  for(int i=0; i<n; i++) cin >> v[i];
  int ans = 0;
  for(int i=0; i<=k; i++) ans = max(solve(0, n-1, i), ans);
  cout << ans << endl; 
}


