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
 
inline int mod(int n){ return (n%123456789); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
  DESYNC;
  int l,s;
  cin >> l >> s;
  int dp[l];
  dp[0] = 1;
  int sum = 1;
  for(int i=1; i<l; i++){
    dp[i] = sum;
    sum += dp[i];
    if(i >= s) sum -= dp[i-s];
    sum = (sum%123456789+123456789)%123456789;
  }
  int ans = 0;
  for(int i=0; i<s; i++){
    ans = (ans + dp[l - (i+1)]*(i+1))%123456789;
  }
  cout << ans << endl;
  //for(int i=0; i<l; i++) cout << dp[i] << " ";
  //cout << endl;
}
 
