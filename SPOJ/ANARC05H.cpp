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

int dp[30][1000];
string s;

int solve(int i, int sum){
  if(i == s.size()){
    return 1;
  }
  if(dp[i][sum] != -1) return dp[i][sum];
  int ret = 0;
  int cur = 0;
  for(int j = i; j<s.size(); j++){
    cur += s[j] - '0';
    if(cur >= sum) ret += solve(j+1, cur);
  }
  dp[i][sum] = ret;
  return ret;
}
  
int32_t main(){
  DESYNC;
  int test= 1;
  while(cin >> s, s != "bye"){
    memset(dp, -1, sizeof dp);
    cout << test++ << ". " << solve(0, 0) << endl;
  }   
}


