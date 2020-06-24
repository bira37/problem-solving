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

struct Dinic {

  struct FlowEdge{
    int v, rev, c, cap;
    FlowEdge() {}
    FlowEdge(int v, int c, int cap, int rev) : v(v), c(c), cap(cap), rev(rev) {}
  };
  
  vector< vector<FlowEdge> >  adj;
  vector<int> level, used;
  int src, snk;
  int sz;
  int max_flow;
  Dinic(){}
  Dinic(int n){
    src = 0;
    snk = n+1;
    adj.resize(n+2, vector< FlowEdge >());
    level.resize(n+2);
    used.resize(n+2);
    sz = n+2;
    max_flow = 0;
  }
  
  void add_edge(int u, int v, int c){
    int id1 = adj[u].size();
    int id2 = adj[v].size();
    adj[u].pb(FlowEdge(v, c, c, id2));
    adj[v].pb(FlowEdge(u, 0, 0, id1));
  }
  
  void add_to_src(int v, int c){
    adj[src].pb(FlowEdge(v, c, c, -1));
  }
  
  void add_to_snk(int u, int c){
    adj[u].pb(FlowEdge(snk, c, c, -1));
  }
  
  bool bfs(){
    for(int i=0; i<sz; i++){
      level[i] = -1;
    }
    
    level[src] = 0;
    queue<int> q; q.push(src);
    
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(FlowEdge e : adj[cur]){
        if(level[e.v] == -1 && e.c > 0){
          level[e.v] = level[cur]+1;
          q.push(e.v);
        }
      }
    }
    
    return (level[snk] == -1 ? false : true);
  }
  
  int send_flow(int u, int flow){
    if(u == snk) return flow;
    
    for(int &i = used[u]; i<adj[u].size(); i++){
      FlowEdge &e = adj[u][i];
      
      if(level[u]+1 != level[e.v] || e.c <= 0) continue;
      
      int new_flow = min(flow, e.c);
      int adjusted_flow = send_flow(e.v, new_flow);
      
      if(adjusted_flow > 0){
        e.c -= adjusted_flow;
        if(e.rev != -1) adj[e.v][e.rev].c += adjusted_flow;
        return adjusted_flow;
      }
    }
    
    return 0;
  }
  
  void calculate(){
    if(src == snk){max_flow = -1; return;} //not sure if needed
    
    max_flow = 0;
    
    while(bfs()){
      for(int i=0; i<sz; i++) used[i] = 0;
      while(int inc = send_flow(src, INF)) max_flow += inc;
    }
    
  }
  
  vector< ii > mincut(){
    bool vis[sz];
    for(int i=0; i<sz; i++) vis[i] = false;
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(FlowEdge e : adj[cur]){
        if(e.c > 0 && !vis[e.v]){
          q.push(e.v);
          vis[e.v] = true;
        }
      }
    }
    vector< ii > cut;
    for(int i=1; i<=sz-2; i++){
      if(!vis[i]) continue;
      for(FlowEdge e : adj[i]){
        if(1 <= e.v && e.v <= sz-2 && !vis[e.v] && e.cap > 0 && e.c == 0) cut.pb(ii(i, e.v));
      }
    }
    return cut;
  }
  
};

vector<int> adj[112];
int dg[112] = {0};
vector< vector<int> > paths;

void go(int u, int id){
  paths[id].pb(u);
  for(int v : adj[u]){
    go(v, id);
  }
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  Dinic dinic(n+n);
  for(int i=1; i<=n; i++){
    dinic.add_to_src(i, 1);
    dinic.add_to_snk(i+n, 1);
  }
  
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >>v;
    dinic.add_edge(u,v+n,1);
  }
  
  dinic.calculate();
  for(int i=1; i<=n; i++){
    for(Dinic::FlowEdge e : dinic.adj[i]){
      if(e.cap == 1 && e.c == 0 && 1 <= e.v && e.v-n <= n){
        adj[i].pb(e.v-n);
        dg[e.v-n]++;
      }
    }
  }
  
  for(int i=1; i<=n; i++){
    if(dg[i] == 0){
      paths.pb(vector<int>());
      go(i, paths.size()-1);
    }
  }
  
  cout << paths.size() <<endl;
  for(int i=0; i<paths.size(); i++){
    for(int v : paths[i]) cout << v << " ";
    cout << endl;
  }       
    
}


