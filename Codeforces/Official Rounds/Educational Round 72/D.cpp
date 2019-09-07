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
 
vector<int> g[5123];
vector<ii> ed;
int vis[5123];
map< ii, int> color;
void go(int u, int lst){
  vis[u] = 1;
  for(int v : g[u]){
    if(vis[v] == 1){
      if(lst == 1) color[ii(u,v)] = 2;
      else color[ii(u,v)] = 1;
    }
    if(vis[v] == 2) color[ii(u,v)] = lst;
    if(vis[v] == 0){
      color[ii(u,v)] = lst;
      go(v, lst);
    }
  }
  vis[u] = 2;
}
 
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    ed.pb(ii(u,v));
    g[u].pb(v);
  }
  for(int i=1; i<=n; i++){
    if(vis[i] == 0) go(i, 1);
  }
  int mx = 0;
  for(ii e : ed) mx = max(mx, color[ii(e.ff, e.ss)]);
  cout << mx << endl;
  for(ii e : ed) cout << color[ii(e.ff, e.ss)] << " ";
  cout << endl;
}
