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

vector<int> adj[112345];
vector<int> adjc[112345];

int dist[50][112345];

vector< tuple<int,int,int> > extra;

int uf[112345];

void init(int n){
  for(int i=0; i<=n; i++){
    uf[i] = i;
  }
}

int find(int u){
  if(u == uf[u]) return u;
  else return uf[u] = find(uf[u]);
}

bool merge(int a, int b){
  int x = find(a), y = find(b);
  if(x == y) return false;
  if(rand()%2) swap(x,y);
  uf[y] =x;
  return true;
}


struct LCA {
  
  int tempo;
  vector<int> st, ed, dad, anc[20], L;
  vector<bool> vis;
  LCA() {}
  
  LCA(int n){
    tempo = 0;
    st.resize(n+1);
    ed.resize(n+1);
    dad.resize(n+1);
    L.resize(n+1);
    for(int i=0; i<20; i++) anc[i].resize(n+1);
    vis.resize(n+1);
    for(int i=0; i<=n; i++) vis[i] = false;
  }

  void dfs(int u){
    vis[u] = true;
    st[u] = tempo++;
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i];
      int c = adjc[u][i];
      if(!vis[v]){
        dad[v] = u;
        L[v] = L[u] + c;
        dfs(v);
      }
    } 
    ed[u] = tempo++;
  }

  bool is_ancestor(int u, int v){
    return st[u] <= st[v] && st[v] <= ed[u];
  }

  int query(int u, int v){
    if(is_ancestor(u,v)) return u;
    for(int i=19; i>=0; i--){
      if(anc[i][u] == -1) continue;
      if(!is_ancestor(anc[i][u],v)) u = anc[i][u];
    }
    return dad[u];
  }
  
  int distance(int u, int v){
    return L[u] + L[v] - 2*L[query(u,v)];
  }

  void precalculate(){
    dad[1] = -1;
    L[1] = 0;
    dfs(1);
    for(int i=1; i<st.size(); i++){
      anc[0][i] = dad[i];
    }
    for(int i=1; i<20; i++){
      for(int j=1; j<st.size(); j++){
          if(anc[i-1][j] != -1){
            anc[i][j] = anc[i-1][anc[i-1][j]];
          }
          else {
            anc[i][j] = -1;
          }
      }
    }
  }
  
} lca;

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  init(n);
  LCA lca(n);
  for(int i=0; i<m; i++){
    int u,v,c;
    cin >> u >> v >> c;
    if(merge(u,v)){
      adj[u].pb(v);
      adj[v].pb(u);
      adjc[u].pb(c);
      adjc[v].pb(c);
    }
    else extra.pb(make_tuple(u,v,c));
  }
  lca.precalculate();
  set<int> s;
  vector<int> flags;
  for(auto t : extra){
    int u,v,c;
    tie(u,v,c) = t;
    s.insert(u); s.insert(v);
    adj[u].pb(v);
    adj[v].pb(u);
    adjc[u].pb(c);
    adjc[v].pb(c);
  }
  for(int x : s) flags.pb(x);
  for(int i=0; i<flags.size(); i++){
    for(int j=0; j<=n; j++) dist[i][j] = INF;
    int vertex = flags[i];
    dist[i][vertex] = 0;
    set< ii > s;
    s.insert(ii(dist[i][vertex], vertex));
    while(!s.empty()){
      int u = s.begin()->ss;
      int d = s.begin()->ff;
      s.erase(s.begin());
      if(d > dist[i][u]) continue;
      for(int j=0; j<adj[u].size(); j++){
        int v = adj[u][j];
        int c = adjc[u][j];
        if(d + c < dist[i][v]){
          dist[i][v] = d+c;
          s.insert(ii(dist[i][v], v));
        }
      }
    }
  }
  
  int q;
  cin >> q;
  while(q--){
    int u,v;
    cin >> u >> v;
    int ans = lca.distance(u,v);
    for(int i=0; i<flags.size(); i++){
      ans = min(ans, dist[i][u] + dist[i][v]);
    }
    cout << ans << endl;
  }
}

