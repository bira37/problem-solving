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

int dp[2123+10][2123+10][2];

int solve(int n, int open, bool got){
  if(dp[n][open][got] != -1) return dp[n][open][got];
  if(n == 0){
    return 0;
  }
  
  //tries to open
  if(got){ 
    dp[n][open][got] = 0;
    if(n-1 >= open+1) dp[n][open][got] = mod(dp[n][open][got] + solve(n-1, open+1, !got), M);
    //tries to close
    if(open > 0) dp[n][open][got] = mod(dp[n][open][got] + solve(n-1, open-1, !got), M);
  }
  else {
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    if(n-1 >= open+1){
      x1 = solve(n-1, open+1, !got);
      x2 = solve(n-1, open+1, got);
    }
    if(open > 0){
      x3 = solve(n-1, open-1, !got);
      x4 = solve(n-1, open-1, got);
    }
    dp[n][open][got] = mod(max(1 + x1 + x3, x2+x4), M);
  } 
  //cout << "dp[" << n << "][" << open << "][" << got << "] = " << dp[n][open][got] << endl;
  dp[n][open][got] = mod(dp[n][open][got], M);
  return mod(dp[n][open][got], M);
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << solve(2*n, 0, false) << endl;
}

