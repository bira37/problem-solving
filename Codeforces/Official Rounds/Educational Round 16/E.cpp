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
  int n,x,y;
  cin >> n >> x >> y;
  deque< ii > dq;
  int dp[n+1];
  dp[1] = x;
  dq.push_back(ii(1, dp[1] + 2LL*1*x));
  for(int i=2; i<=n; i++){
    while(dq.size() > 0 && dq.front().ff < i/2 + (i%2)) dq.pop_front();
    if(dq.size() == 0) dp[i] = dp[i-1] + x;
    else dp[i] = min(dp[i-1] + x, dq.front().ss - i*x + y);
    int val = dp[i] + 2LL*i*x;
    while(dq.size() > 0 && dq.back().ss > val) dq.pop_back();
    dq.push_back(ii(i, val));
  }
  cout << dp[n] << endl;
}
 
