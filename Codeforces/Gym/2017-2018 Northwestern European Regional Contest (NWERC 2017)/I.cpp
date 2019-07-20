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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct app{
  int s,d, id;
  app (){}
  app(int s, int d, int id) : s(s), d(d), id(id) {}
  bool operator<(const app & b) const{
    return s-d < b.s - b.d;
  }
};
 
int32_t main(){
  DESYNC;
  int n, k;
  cin >> n >> k;
  app v[n];
  for(int i=0; i<n; i++){
    cin >> v[i].d >> v[i].s;
    v[i].id = i+1;
  }
  sort(v, v+n);
  int dp[n+1][n+1];
  tuple<int,int,int> back[n+1][n+1];
  for(int i=0; i<=n; i++){
    for(int j = 0; j<=n; j++){
      dp[i][j] = INF; 
      back[i][j] = make_tuple(-1,-1,-1);
    }
  }
  for(int i=0; i<=n; i++){
    dp[i][0] = 0;
  }  
  for(int i=1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      if(dp[i-1][j-1] + v[i-1].s < dp[i][j] && dp[i-1][j-1] + v[i-1].s <= k && dp[i-1][j-1] + v[i-1].d <= k){
        back[i][j] = make_tuple(i-1, j-1, v[i-1].id);
        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + v[i-1].s);
      }
      if(dp[i-1][j] < dp[i][j]){
        back[i][j] = make_tuple(i-1, j, -1);
        dp[i][j] = min(dp[i][j], dp[i-1][j]);
      }
    }
  }
  int x = n, y, z;
  for(int i=n; i>=0; i--){
    if(dp[n][i] <= k){
      y = i;
      break;
    }
  }
  vector<int> ans;
  while(x >= 0 && y >= 0){
    tie(x,y,z) = back[x][y];
    if(z != -1) ans.pb(z);
  }
  cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  for(int x : ans) cout << x << " ";
  if(ans.size() > 0) cout << endl; 
}
 
