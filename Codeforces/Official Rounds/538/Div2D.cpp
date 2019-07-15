#include <bits/stdc++.h>

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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int dp[5005][5005];
vector<int> v;
int n;

int solve(int l, int r){
  if(l == 0 && r == n-1) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  
  dp[l][r] = INF;
  if(l > 0) dp[l][r] = min(dp[l][r], solve(l-1, r)+1);
  if(r < n-1) dp[l][r] = min(dp[l][r], solve(l, r+1)+1);
  if(l > 0 && r < n-1 && v[l-1] == v[r+1]) dp[l][r] = min(dp[l][r], solve(l-1, r+1)+1);
  return dp[l][r];
}

int32_t main(){
  DESYNC;
  cin >> n;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    if(v.size() == 0 || v.back() != x) v.pb(x);
  }
  n = v.size();
  memset(dp, -1, sizeof dp);
  int ans = INF;
  for(int i=0; i<n; i++){
    ans = min(ans, solve(i,i));
  }
  cout << ans << endl;
}

