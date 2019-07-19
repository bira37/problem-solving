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

vector<int> adj[1123456];
set<int> indexes[1123456];
struct SCC {

  vector< vector<int> > adj_t;
  vector< vector<int> > scc_adj;
  vector<int> ed;
  int tempo,comp;
  vector<bool> vis;
  vector<int> scc;
  
  SCC() {}
  
  SCC(int n){
    tempo = 0;
    adj_t.resize(n+1, vector<int>());
    scc_adj.resize(n+1, vector<int>());
    ed.resize(n+1);
    comp = 0;
    vis.resize(n+1);
    scc.resize(n+1);
  }

  void dfs(int u){
    vis[u] = true;
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i];
      if(!vis[v]) dfs(v);
    }
    ed[u] = ++tempo;
  }

  void dfst(int u, int comp){
    scc[u] = comp;
    vis[u] = true;
    for(int i=0; i<adj_t[u].size(); i++){
      int v = adj_t[u][i];
      if(!vis[v]) dfst(v,comp);
    }
  }

  void calculate(){
    int n = vis.size()-1;
    
    for(int i=0; i<=n; i++){
      vis[i] = false;
    }
    
    for(int i=1; i<=n; i++){
      if(!vis[i]){
        dfs(i);
      }
    }
    
    for(int i=1; i<=n; i++){
      for(int v : adj[i]){
        adj_t[v].pb(i);
      }
    }
    
    vector< ii > vertex(n);
    
    for(int i=0; i<n; i++){
      vis[i+1] = false;
      vertex[i] = ii(i+1, ed[i+1]);
    }
    
    sort(vertex.begin(), vertex.end(), [](const ii & a, const ii & b) { return a.ss > b.ss; });
    
    for(int i=0; i<vertex.size(); i++){
      if(!vis[vertex[i].ff]){
        comp++;
        dfst(vertex[i].ff,comp);
      }
    }
    for(int i=1; i<=n; i++){
      for(int j=0; j<adj[i].size(); j++){
        int v = adj[i][j];
        scc_adj[scc[i]].push_back(scc[v]);
      }
    }
  }
  
};

int32_t main(){
  int n,m;
  cin >> n >> m;
  SCC kos(n);
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    u++, v++;
    adj[u].pb(v);
  }
  kos.calculate();
  for(int i=1; i<=n; i++){
    indexes[kos.scc[i]].insert(i);
  }
  for(int i=1; i<=n; i++) cout << *indexes[kos.scc[i]].begin() -1 << endl;  
}


