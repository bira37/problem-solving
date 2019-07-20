#include <bits/stdc++.h>

#define int long long
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

bool check(int z, int ans){
  if(z <= 0){
    cout << ans << endl;
    return true;
  }
  return false;
}

int dp[900][900];
int v[500];
int pre[500];
int solve(int l, int r){
  if(l == r) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  dp[l][r]= INF;
  for(int x=l; x<r; x++) dp[l][r] = min(dp[l][r], solve(l,x) + solve(x+1, r) + pre[r] - pre[l-1]);
  //cout << "dp[" << l << "][" << r << "= " << dp[l][r] << endl;
  return dp[l][r];
}

void solve(){
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  pre[0] = 0;
  for(int i=1; i<=n; i++){
    cin >> v[i];
    v[i+n] = v[i];
    pre[i] = pre[i-1] + v[i];
  }
  for(int i=n+1; i<=2*n; i++) pre[i] = pre[i-1] + v[i];
  int ans = INF;
  for(int l=1, r=n; l<=n; l++, r++){
    ans = min(ans, solve(l, r));
  }
  cout << ans << endl;
}

int32_t main(){
  int t;
  cin >> t;
  while(t--) solve();

}


