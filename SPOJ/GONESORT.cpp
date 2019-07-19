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
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for(int i=0; i<n; i++){
      cin >> v[i];
      s.insert(v[i]);
    }
    vector<int> aux;
    for(int x : s) aux.pb(x);
    for(int i=0; i<n; i++) v[i] = lower_bound(aux.begin(), aux.end(), v[i]) - aux.begin();
    int dp[n];
    dp[0] = 1;
    int ans = 1;
    for(int i=1; i<n; i++){
      dp[i] = 1;
      for(int j=0; j<i; j++){
        if(v[j] + 1 == v[i]) dp[i] = max(dp[i], dp[j]+1);
      }
      ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
  }
}


