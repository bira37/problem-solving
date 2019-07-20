#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_tuple
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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

template<typename T = int>
struct LinkDsu{
  vector<int> r;
  vector<T> best;
  LinkDsu(int n = 0){
    r = vector<int>(n); iota(r.begin(), r.end(), 0);
    best = vector<T>(n);
  }

  int find(int u) {
    if (r[u] == u)
      return u;
    else {
      int v = find(r[u]);
      if (best[r[u]] < best[u]) best[u] = best[r[u]];
      return r[u] = v;
    }
  }

  T eval(int u){ find(u); return best[u]; }
  void link(int p, int u) { r[u] = p; }
  void set(int u, T x) { best[u] = x; }
};

struct DominatorTree{
  typedef vector<vector<int>> Graph;
  vector<int> semi, dom, parent, st, from;
  Graph succ, pred, bucket;
  int r, n, tempo;

  void dfs(int u, int p){
    semi[u] = u;
    from[st[u] = tempo++] = u;
    parent[u] = p;
    for (int v : succ[u]) {
      pred[v].push_back(u);
      if (semi[v] == -1) { dfs(v, u); }
    }
  }

  void build(){
    n = succ.size();
    dom.assign(n, -1);
    semi.assign(n, -1);
    parent.assign(n, -1);
    st.assign(n, 0);
    from.assign(n, -1);
    pred = Graph(n, vector<int>());
    bucket = Graph(n, vector<int>());
    LinkDsu<pair<int,int>> dsu(n);
    tempo = 0;

    dfs(r, r);
    for(int i = 0; i < n; i++) dsu.set(i, make_pair(st[i],  i));

    for (int i = tempo - 1; i; i--) {
      int u = from[i];
      for (int v : pred[u]) {
        int w = dsu.eval(v).second;
        if (st[semi[w]] < st[semi[u]]) { semi[u] = semi[w]; }
      }
      dsu.set(u, make_pair(st[semi[u]], u));
      bucket[semi[u]].push_back(u);
      dsu.link(parent[u], u);
      for(int v : bucket[parent[u]]) {
        int w = dsu.eval(v).second;
        dom[v] = semi[w] == parent[u] ? parent[u] : w;
      }
      bucket[parent[u]].clear();
    }
    for (int i = 1; i < tempo; i++) {
      int u = from[i];
      if (dom[u] != semi[u]) dom[u] = dom[dom[u]];
    }
  }

  DominatorTree(const Graph & g, int s) : succ(g), r(s) {
    build();
  }
};

bool vis[112345] = {0};

vector< vector<int> > g(112345, vector<int>());
int go(int u, int p){
  int sub = 1;
  for(int v : g[u]){
    if(v == p) continue;
    int got = go(v, u);
    sub += got;
  }
  return sub;
}
 
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  g.resize(n+1, vector<int>());
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    g[u].pb(v);
  }
  DominatorTree dt(g, 1);
  for(int i=0; i<=n; i++) g[i].clear();
  for(int i=1; i<=n; i++) if(dt.dom[i] != -1) g[dt.dom[i]].pb(i);
  int ans = 0;
  int tot = 1;
  for(int v : g[1]){
    int sub = go(v, -1);
    ans += tot*sub;
    tot += sub;
  }    
  cout << ans << endl;
}


