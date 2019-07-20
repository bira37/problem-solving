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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int v[22];
int dp[1<<22];
int n,m;
int cur = 0;
 
int solve(int msk){
  if(msk == (1<<n)-1) return 0;
  if(dp[msk] != -1) return dp[msk];
 
  for(int i=0; i<n; i++){
    if(((1<<i) & msk) == 0){
      cur -= v[i];
      dp[msk] = max(solve(msk | (1<<i)) + (cur == 0), dp[msk]);
      cur += v[i];
    }
  }
  return dp[msk];
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >>c;
    v[a] -= c;
    v[b] += c;
  }
  for(int i=0; i<n; i++) cur += v[i];
  for(int i=0; i<(1<<n); i++) dp[i] = -1; 
  cout << n - solve(0 ) << endl;
}
 
