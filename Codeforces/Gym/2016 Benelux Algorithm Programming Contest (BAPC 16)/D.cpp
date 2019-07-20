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
 
int v[4123];
 
int calc(int i, int j){
  return max(20*(j-i+1), v[j] - (v[i]+1800) + 20);
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> v[i];
  }
  
  int dp[n+1];
  for(int i=0; i<=n; i++) dp[i] = INF;
  dp[0] = 0;
  
  for(int i=1; i<=n; i++){
    for(int j = 1; j<=i; j++){
      dp[i] = min(dp[i], calc(j, i) + 120 + dp[j-1]);
      //cout << j << ", " << i << " " << calc(j, i) + 120 + dp[j-1] << endl;
    }
  }
  //cout << endl;
  cout << dp[n] << endl;   
}
 
