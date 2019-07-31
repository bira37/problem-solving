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

int dp[112345][13];
string s;

int solve(int i, int r){
  if(i == s.size()) return r == 5;
  if(dp[i][r] != -1) return dp[i][r];
  dp[i][r] = 0;
  if(s[i] != '?'){
    dp[i][r] = solve(i+1, (r*10+(s[i]-'0'))%13);
    //cout << "dp[" << i+1 << "][" << (r*10+(s[i]-'0'))%13 << "] = " << dp[i+1][(r*10+(s[i]-'0'))%13] << endl;
    dp[i][r] = mod(dp[i][r], M);
  }
  else {
    for(int d = 0; d <= 9; d++){
      dp[i][r] += solve(i+1, (r*10+d)%13);
      //cout << "dp[" << i+1 << "][" << (r*10+d)%13 << "] = " << dp[i+1][(r*10+d)%13] << endl;
      //cout << dp[i][r] << endl;
      dp[i][r] = mod(dp[i][r], M);
    }
  }
  return dp[i][r];
}
int32_t main(){
  DESYNC;
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
}


