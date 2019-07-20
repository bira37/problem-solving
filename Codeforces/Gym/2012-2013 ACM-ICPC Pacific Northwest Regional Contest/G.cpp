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
 
string s;
 
int dp[65][65][2];
int map[] = {0, 2, 1};
int mx = -1;
 
int solve(int i, int cur, bool f){
 
  if(i == s.size()){
    if(cur == 0) return 1;
    else return 0;
  }
  
  if(dp[i][cur][f] != -1) return dp[i][cur][f];
  
  dp[i][cur][f] = 0;
  
  //put 1
  if(f || s[i] == '1'){
    dp[i][cur][f] += solve(i+1, cur-1, f);
  }
  
  //put 0
  dp[i][cur][f] += solve(i+1, cur, (s[i] == '1' ? true : f));
  
  return dp[i][cur][f];
}
 
string convert(int n){
  string ret;
  for(int i=57; i>=0; i--){
    if((1LL<<i) & n){
      ret += '1';
      if(mx == -1) mx = i+1;
    }
    else ret += '0';
  }
  return ret;
}
 
int32_t main(){
  DESYNC;
  int n;
  while(cin >> n){
    for(int i=0; i<65; i++){
      for(int j=0; j<65; j++) dp[i][j][0] = dp[i][j][1] = -1;
    }
    mx = -1;
    s = convert(n);
    int ans = 0;
    for(int i=0; i<=mx; i++){
      if(i%3 == 0) ans += solve(0, i, false);
    } 
    cout << "Day " << n << ": Level = " << ans - 1 << endl;
  }
}
 
