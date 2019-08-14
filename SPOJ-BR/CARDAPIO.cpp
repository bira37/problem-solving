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

set<string> food;
map<string, int> str_to_id;

string l[1123],r[1123];

vector<int> adj[112345];

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
  DESYNC;
  int m;
  int test = 1;
  while(cin >> m){
    str_to_id.clear();
    food.clear();
    for(int i=0; i<10000; i++) adj[i].clear();
    for(int i=0; i<m; i++){
      cin >> l[i] >> r[i];
      if(l[i][0] == '!'){
        string aux = l[i].substr(1, l[i].size()-1);
        food.insert(aux);
      }
      else food.insert(l[i]);
      if(r[i][0] == '!'){
        string aux = r[i].substr(1, r[i].size()-1);
        food.insert(aux);
      }
      else food.insert(r[i]);
    }
    int n = food.size();
    SCC kos(2*n);
    int ids = 1;
    for(string s : food){
      if(!str_to_id.count(s)) str_to_id[s] = ids;
      if(!str_to_id.count("!" + s)) str_to_id["!" + s] = ids + n;
      ids++;
    }
    
    for(int i=0; i<m; i++){
      
      //add clause ~x -> y
      int u, v;
      if(l[i][0] == '!') u = str_to_id[l[i]] - n;
      else u = str_to_id[l[i]] + n;
      v = str_to_id[r[i]];
      
      adj[u].pb(v);
      
      //add clause ~y -> v
      if(r[i][0] == '!') u = str_to_id[r[i]] - n;
      else u = str_to_id[r[i]] + n;
      v = str_to_id[l[i]];
      
      adj[u].pb(v);
      
    }
    
    kos.calculate();
    
    bool ok = true;
    
    for(int i=0; i<n; i++){
      int a, b;
      a = str_to_id[l[i]];
      
      if(l[i][0] == '!') b = str_to_id[l[i]] - n;
      else b = str_to_id[l[i]] + n;
      
      if(kos.scc[a] == kos.scc[b]){
        ok= false;
      } 
      
      a = str_to_id[r[i]];
      
      if(r[i][0] == '!') b = str_to_id[r[i]] - n;
      else b = str_to_id[r[i]] + n;
      
      if(kos.scc[a] == kos.scc[b]){
        ok= false;
      }
    }
    cout << "Instancia " << test++ << endl;
    if(ok) cout << "sim" <<endl;
    else cout << "nao" << endl;
    cout << endl;
  } 
}


