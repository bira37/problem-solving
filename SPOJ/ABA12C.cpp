#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
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

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int dp[k+1];
    for(int i=0; i<=k; i++) dp[i] = INF;
    dp[0] = 0;
    for(int i=1; i<=k; i++){
      int x;
      cin >> x;
      if(x == -1) continue;
      for(int j = i; j<=k; j++){
        dp[j] = min(dp[j], dp[j-i] + x);
      }
    }
    if(k == 0) cout << 0 << endl;
    else if(dp[k] < INF) cout << dp[k] << endl;
    else cout << -1 << endl;
  }
}


