#include <bits/stdc++.h>
 
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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int dp[1LL<<20];
int cst[20][20];
int n,m;
 
void print(int msk){
  cout << "dp of ";
  for(int i=0; i<m; i++) if(msk & (1<<i)){
    cout << 1;
  }
  else cout << 0;
}
int solve(int msk){
  if(msk == (1<<m)-1) return 0;
  if(dp[msk] != -1) return dp[msk];
  dp[msk] = INF;
  int cur = 0;
  for(int i=0; i<m; i++){
    if(msk & (1<<i)){
      for(int j=0; j<m; j++){
        if(msk & (1<<j)) continue;
        cur += cst[i][j];
      }
    }
  }
  for(int bit = 0; bit < m; bit++){
    if(msk & (1<<bit)) continue;
    //choose bit
    int new_cur = cur;
    for(int i=0; i<m; i++){
      if(msk & (1<<i)) new_cur -= cst[bit][i];
      else new_cur += cst[bit][i];
    }
    int ret = solve(msk | (1<<bit));
    dp[msk] = min(dp[msk], ret + new_cur);
    //print(msk);
    //cout << " newcur = " << new_cur << " adding bit " << bit << " is " << ret + new_cur << endl;
  }
  return dp[msk];
}
int32_t main(){
  DESYNC;
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  string s;
  cin >> s;
  for(int i=1; i<n; i++){
    int a = s[i]-'a';
    int b = s[i-1]-'a';
    if(a == b) continue;
    cst[a][b]++;
    cst[b][a]++;
  }
  int ans = solve(0);
  cout << ans << endl;
}
