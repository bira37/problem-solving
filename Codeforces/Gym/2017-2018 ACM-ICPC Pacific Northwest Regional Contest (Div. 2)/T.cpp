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
 
struct edge{
  int v, l, r;
  edge() {}
  edge(int v, int l, int r) : v(v), l(l), r(r) {}
};
 
vector< edge > adj[1123];
bool vis[1123];
int t;
 
bool dfs(int u, int l, int r){
  vis[u] = true;
  if(u == t) return true;
  for(edge e : adj[u]){
    if(vis[e.v]) continue;
    if(e.l <= l && r <= e.r){
      if(dfs(e.v, l, r)) return true;
    }
  }
  return false;
}
 
int32_t main(){
  DESYNC;
  int n,m,k;
  cin >> n >> m >> k;
  int s;
  cin >> s >> t;
  vector<int> uhu;
  for(int i=0; i<m; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    adj[a].pb(edge(b,c-1,d));
    uhu.pb(c-1);
    uhu.pb(d);
  }
  sort(uhu.begin(), uhu.end());
  int lef = 0;
  int ans = 0;
  for(int rig : uhu){
    for(int i=0; i<=n; i++) vis[i] = false;
    ans += (rig-lef)*dfs(s, lef, rig);
    lef = rig;
  }
  cout << ans << endl;
}
 
