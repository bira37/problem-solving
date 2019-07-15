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
#define M 998244353
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int exp(int a, int k){
  if(k == 1) return a;
  if(k == 0) return 1;
  
  int aux = exp(a, k/2);
  aux *= aux;
  aux = mod(aux, M);
  
  if(k%2) aux *= a;
  
  aux = mod(aux, M);
  
  return aux;
}

int inv(int a){
  if(a == 0) return 0;
  return exp(a, M-2);
}

map<int, vector< ii > > coords;
int dp[1123][1123];

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  int r,c;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      int x;
      cin >> x;
      coords[x].pb(ii(i,j));
    }
  }
  cin >> r >> c;
  int sval = 0, srow = 0, scol = 0, srowm = 0, scolm = 0;
  int cnt = 0;
  bool flag = false;
  for(auto bucket : coords){
    for(ii coord : bucket.ss){
      int x = coord.ff, y = coord.ss;
      int k = inv(cnt);
      if(!flag) dp[x][y] = 0;
      else {
        dp[x][y] = mod(sval*k, M) + mod(srow*k, M) + mod(scol*k, M) - mod(2*mod(srowm*x, M)*k, M) - mod(2*mod(scolm*y, M)*k, M) + x*x + y*y;
        dp[x][y] = mod(dp[x][y], M);
      }
    } 
    
    for(ii coord : bucket.ss){
      int x = coord.ff, y = coord.ss;
      sval += dp[x][y];
      sval = mod(sval, M);
      srow += x*x;
      srow = mod(srow, M);
      scol += y*y;
      scol = mod(scol, M);
      srowm += x;
      srowm = mod(srowm, M);
      scolm += y;
      scolm = mod(scolm, M);
      cnt++;
    } 
    if(!flag) flag = true;
  }
  
  cout << dp[r][c] << endl;
}