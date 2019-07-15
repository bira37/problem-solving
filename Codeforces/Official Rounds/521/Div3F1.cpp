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
#define INF 1e15
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
  int n,k,x;
  cin >> n >> k >> x;
  int v[n];
  int dp[n+1][x+1];
  for(int i=1; i<=n; i++){
    cin >> v[i];
  }
  for(int i=0; i<=n; i++){
    for(int j=0; j<=x;j++){
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  for(int j=1; j<=x; j++){  
    deque< ii > dq;
    dq.pb(ii(dp[0][j-1],0));
    for(int i=1; i<=n; i++){
      while(dq.size() > 0 && dq.front().ss < i-k) dq.pop_front();
      if(dq.size() == 0){
        cout << -1 << endl;
        return 0;
      }
      dp[i][j] = max(dp[i][j], v[i] + dq.front().ff);
      while(dq.size() > 0 && dq.back().ff <= dp[i][j-1]) dq.pop_back();
      dq.pb(ii(dp[i][j-1], i));
    }
  }
  int ans = -INF;
  for(int i=max(1LL, n-k+1); i<=n; i++) ans = max(ans, dp[i][x]);
  if(ans < 0) cout << -1 << endl;
  else cout << ans << endl;  
}

