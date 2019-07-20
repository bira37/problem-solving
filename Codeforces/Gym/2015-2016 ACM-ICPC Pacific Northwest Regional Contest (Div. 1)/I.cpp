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
 
int dcmp(double a, double b){
  if(abs(a-b) <= EPS) return 0;
  else if(a < b) return -1;
  else return 1;
}
 
struct vec2{
  double x, y;
  vec2() {}
  vec2(double x, double y) : x(x), y(y) {}
};
 
vector<int> adj[5123];
int uf[5123], sz[5123];
vector<vec2> v;
bool vis[5123];
 
double dist(vec2 a, vec2 b){
  double ret = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
  return sqrt(ret);
}
 
void init(int n){
  for(int i=0; i<=n; i++){
    uf[i] = i;
    sz[i] = 1;
  }
}
 
int find(int u){
  if(u == uf[u]) return u;
  else return uf[u] = find(uf[u]);
}
 
bool merge(int a, int b){
  int x = find(a);
  int y = find(b);
  if(x == y) return false;
  if(sz[x] < sz[y]) swap(x,y);
  uf[y] = x;
  sz[x] += sz[y];
  return true;
}
 
void dfs(int u){
  vis[u] = true;
  for(int v : adj[u]){
    if(vis[v]) continue;
    merge(u,v);
    dfs(v);
  }
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  init(n);
  v.resize(n+1);
  for(int i=1; i<=n; i++){
    cin >> v[i].x >> v[i].y;
  }
  for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++){
      if(dcmp(dist(v[i], v[j]), 2) <= 0){
        adj[i].pb(j);
        adj[j].pb(i);
      }
    }
  }
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  vector<vec2> cands;
  for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++){
      vec2 mid;
      mid.x = (v[i].x+v[j].x)/2.;
      mid.y = (v[i].y+v[j].y)/2.;
      double d = dist(v[i], v[j]);
      d = d*d; d /= 4.; d = 4 - d;
      if(dcmp(d, 0) < 0) continue;
      double sz = sqrt(d);
      
      vec2 dir(v[i].x - v[j].x, v[i].y - v[j].y);
      dir.x /= dist(v[i], v[j]); dir.y /= dist(v[i], v[j]);
      vec2 norm;
      norm.x = -dir.y;
      norm.y = dir.x;
      
      vec2 p1;
      p1.x = norm.x*sz + mid.x;
      p1.y = norm.y*sz + mid.y;
      
      sz = -sz;
      
      vec2 p2;
      p2.x = norm.x*sz + mid.x;
      p2.y = norm.y*sz + mid.y;
      
      cands.pb(p1);
      cands.pb(p2);
      
    }
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    ans = max(ans, sz[i]+1);
  }
  for(vec2 p : cands){
    for(int i=1; i<=n; i++){
      vis[i] = false;
    }
    int cur = 0;
    for(int i=1; i<=n; i++){
      if(vis[find(i)]) continue;
      if(dcmp(dist(v[i], p), 2) <= 0){
        cur += sz[find(i)];
        vis[find(i)] = true;
      }
    }
    ans = max(ans, cur+1);
  }
  cout << ans << endl;           
}
 
