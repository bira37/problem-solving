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
 
int dp[112][112][112];
int v[112];
int pos;
 
bool solve(int l, int r, int k){
  if(dp[l][r][k] != -1) return dp[l][r][k];
  
  dp[l][r][k] = 0;
  
  for(int i = l; i < pos; i++){
    if((i == l || v[i] > v[i-1]) && v[i] > v[i+1]) dp[l][r][k] |= !solve(i+1, r, k + (i-l));
  }
  for(int i = pos+1; i <= r; i++){
    if((i == r || v[i] > v[i+1]) && v[i] > v[i-1]) dp[l][r][k] |= !solve(l, i-1, k + (r - i));
  }
  if(k > 0) dp[l][r][k] |= !solve(l, r, k -1);
  return dp[l][r][k];
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> v[i];
      if(v[i] == 1) pos = i;
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        for(int k = 0; k<n; k++){
          dp[i][j][k] = -1;
        }
      }
    }
    
    for(int k = 0; k < n; k++) dp[pos][pos][k] = 1;
    
    cout << (solve(0, n-1, 0) == 1 ? "Alice" : "Bob") << endl;
  }
}
 
