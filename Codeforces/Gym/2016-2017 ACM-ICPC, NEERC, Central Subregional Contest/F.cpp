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
 
int uf[1123];
vector< int > g[1123];
bool vis[1123][3];
int ans[1123];
int dg[1123];
 
int find(int u){
  if(uf[u] == u) return u;
  else return uf[u] = find(uf[u]);
}
 
bool merge(int a, int b){
  int x = find(a);
  int y = find(b);
  if(x == y) return false;
  if(rand()%2) swap(x,y);
  uf[y] = x;
  return true;
}
 
bool go(int u, int hei){
  int son = 0;
  bool ok = false;
  vis[u][hei] = true;
  for(int v : g[u]){
    if(vis[v][hei+1]){
      if(ans[v] == hei+1){
        ok = true;
        ans[find(u)] = hei;
      }
      continue;
    }
    son++;
    if(go(v, hei+1)){
      ok = true;
      ans[find(u)] = hei;
    }
  }
  if(son == 0 && hei == 2){
    ok = true;
    ans[find(u)] = hei;
  }
  return ok;
}
 
int32_t main(){
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  int n,m;
  cin >> n >> m;
  for(int i=0; i<=n; i++){
    uf[i] = i;
    ans[i] = -1;
  }
  vector< ii > metrics;
  for(int i=0; i<m; i++){
    int u, v;
    char c;
    cin >> u >> c >> v;
    if(c == '=') merge(u,v);
    else {
      if(c == '>') swap(u,v);
      metrics.pb(ii(u,v));
    }
  }
  for(ii e : metrics){
    int u = e.ff;
    int v = e.ss;
    g[find(u)].pb(find(v));
    dg[find(v)]++;
  }
  for(int i=1; i<=n; i++){
    if(vis[find(i)][0] || dg[find(i)]) continue;
    go(find(i), 0);
    vis[find(i)][0] = true;
  }
  for(int i=1; i<=n; i++){
    ans[i] = ans[find(i)];
    if(ans[i] == -1) cout << "?";
    else if(ans[i] == 0) cout << "B";
    else if(ans[i] == 1) cout << "R";
    else cout << "W";
  }
  cout << endl;
}
 
