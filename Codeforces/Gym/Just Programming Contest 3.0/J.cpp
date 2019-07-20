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
 
int dp[1123][1123][2];
int arr[1123];
 
int go(int l, int r, bool p){
  if(r < l) return 0;
  if(dp[l][r][p] !=  -1) return dp[l][r][p];
  if(p == 0){
    return dp[l][r][p] = max(go(l+1, r, !p) + arr[l], go(l, r-1, !p) + arr[r]);
  }
  else return dp[l][r][p] = min(go(l+1, r, !p) - arr[l], go(l, r-1, !p) - arr[r]);
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> arr[i];
      for(int j=0; j<n; j++){
        dp[i][j][0] = dp[i][j][1] = -1;
      }
    }
    cout << go(0, n-1, 0) << endl;
  }
}
 
