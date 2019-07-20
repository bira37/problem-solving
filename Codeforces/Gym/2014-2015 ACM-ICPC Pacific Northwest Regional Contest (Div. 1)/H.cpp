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
#define INF 1e15
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int dp[5123][5123];
int v[15];
int n;
 
int solve(int s, int last){
  if(s == 0){
    //cout << "dp[" << s << "][" << last << "] = " << 0 << endl;
    return 0;
  }
  
  if(dp[s][last] != -1) return dp[s][last];
  
  dp[s][last] = -INF;
  
  for(int i=0; i<n; i++){
    if(s - v[i] - last >= 0) dp[s][last] = max(dp[s][last], solve(s-v[i]-last, last+v[i]) + v[i]);
  }
  //cout << "dp[" << s << "][" << last << "] = " << dp[s][last] << endl;
  return dp[s][last];
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int s;
    cin >> s >> n;
    for(int i=0; i<=s; i++){
      for(int j = 0; j<=s; j++){
        dp[i][j] = -1;
      }
    }
    for(int i=0; i<n; i++) cin >> v[i];
    
    int ans = solve(s, 0);
    cout << (ans < 0 ? -1 : ans)  << endl;
  }
    
}
 
