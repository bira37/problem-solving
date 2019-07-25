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
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int p[3][3][n+1];
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        for(int k=0; k<=n; k++) p[i][j][k] = 0;
      }
    }
    for(int i=1; i<=n; i++){
      char c;
      cin >> c;
      if(c == 'R') p[0][i%3][i]++;
      else if(c == 'G') p[1][i%3][i]++;
      else p[2][i%3][i]++;
    }
    
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        for(int k=0; k<=n; k++) p[i][j][k]+=p[i][j][k-1];
      }
    }
    
    int ans = INF;
    for(int i=1; i<=n && i + k-1 <= n; i++){ 
      //try rgb
      int r = (k+2)/3;
      int g = k/3 + (k%3 == 1);
      int b = k/3;
      
      int cur = (p[0][1][i+k-1] - p[0][1][i-1]) + (p[1][2][i+k-1] - p[1][2][i-1]) + (p[2][0][i+k-1] - p[2][0][i-1]);
      ans = min(ans, k - cur);
      
      //try gbr
      g = (k+2)/3;
      b = k/3 + (k%3 == 1);
      r = k/3;
      
      cur = (p[0][0][i+k-1] - p[0][0][i-1]) + (p[1][1][i+k-1] - p[1][1][i-1]) + (p[2][2][i+k-1] - p[2][2][i-1]);
      ans = min(ans, k - cur);
      //try brg
      
      b = (k+2)/3;
      r = k/3 + (k%3 == 1);
      g = b = k/3;
      
      cur = (p[0][2][i+k-1] - p[0][2][i-1]) + (p[1][0][i+k-1] - p[1][0][i-1]) + (p[2][1][i+k-1] - p[2][1][i-1]);
      ans = min(ans, k - cur);
    }
    cout << ans << endl;
  }
      
      
}
 
