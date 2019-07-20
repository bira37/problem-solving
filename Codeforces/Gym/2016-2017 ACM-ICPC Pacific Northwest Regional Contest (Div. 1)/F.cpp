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
 
int m, r, n;
 
vector<int> adj[61234];
 
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
 
  void calculate(int n){
    for(int i=0; i<=n; i++){
      vis[i] = false;
    }
    
    for(int u=0; u<=n; u++){
      for(int v : adj[u]){
        adj_t[v].pb(u);
      }
    }
    
    for(int i=1; i<=n; i++){
      if(!vis[i]){
        dfs(i);
      }
    }
    
    vector< ii > vertex(n);
    
    for(int i=0; i<n; i++){
      vis[i] = false;
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
 
int hor(int x){
  return 2*x-1;
}
 
int ver(int x){
  return 2*x;
}
 
int neg_hor(int x){
  return 2*x-1 + 2*n;
}
 
int neg_ver(int x){
  return 2*x + 2*n;
}
 
int32_t main(){
  DESYNC;
  cin >> m >> r >> n;
  ii v[n+1];
  for(int i=1; i<=n; i++){
    cin >> v[i].ff >> v[i].ss;
  }
  
  SCC kosaraju(4*n+10);
  
  for(int i=1; i<=n; i++){
    adj[neg_ver(i)].pb(hor(i));
    adj[neg_hor(i)].pb(ver(i));
    
    adj[ver(i)].pb(neg_hor(i));
    adj[hor(i)].pb(neg_ver(i));
  }
  
  for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++){
      ii vvi(max(v[i].ff-r, 1LL), min(m, v[i].ff+r));
      ii vhi(max(v[i].ss-r, 1LL), min(m, v[i].ss+r));
      
      ii vvj(max(v[j].ff-r, 1LL), min(m, v[j].ff+r));
      ii vhj(max(v[j].ss-r, 1LL), min(m, v[j].ss+r));
      
      //check horizontal vs horizontal
//      if(vhi.ff <= vhj.ff && vhj.ff <= vhi.ss && v[i].ff == v[j].ff){
      if(min(vhi.ss, vhj.ss) >= max(vhi.ff, vhj.ff) && v[i].ff == v[j].ff) {
        //cout << "horizontal collision with " << i << " " << j << endl;
        //cout << neg_ver(i) << " -> " << ver(j) << endl;
        //cout << neg_ver(j) << " -> " << ver(i) << endl;
        adj[neg_ver(i)].pb(ver(j));
        adj[neg_ver(j)].pb(ver(i));
        
        adj[hor(i)].pb(neg_hor(j));
        adj[hor(j)].pb(neg_hor(i));
      }
      
      //check vertical vs vertical
      if(min(vvi.ss, vvj.ss) >= max(vvi.ff, vvj.ff) && v[i].ss == v[j].ss) {
      //if(vvi.ff <= vvj.ff && vvj.ff <= vvi.ss && v[i].ss == v[j].ss){
        //cout << "vertical collision with " << i << " " << j << endl;
        //cout << neg_hor(i) << " -> " << hor(j) << endl;
        //cout << neg_hor(j) << " -> " << hor(i) << endl;
        adj[neg_hor(i)].pb(hor(j));
        adj[neg_hor(j)].pb(hor(i));
        
        adj[ver(i)].pb(neg_ver(j));
        adj[ver(j)].pb(neg_ver(i));  
      }
    }
  }
  
  kosaraju.calculate(4*n+10);
  
  for(int i=1; i<=n; i++){
    //cout << i << " " << hor(i) << " " << ver(i) << " " << neg_hor(i) << " " << neg_ver(i) << endl;
    //cout << i << " " << kosaraju.scc[hor(i)] << " " << kosaraju.scc[ver(i)] << " " << kosaraju.scc[neg_hor(i)] << " " << kosaraju.scc[neg_ver(i)] << endl;
    if(kosaraju.scc[hor(i)] == kosaraju.scc[neg_hor(i)]){
      cout << "NO" << endl;
      return 0;
    }
    if(kosaraju.scc[ver(i)] == kosaraju.scc[neg_ver(i)]){
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
 
}
 
