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
#define INF 1e15
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
  
  vector< ii > min_edge_cover(){
    bool covered[sz];
    for(int i=0; i<sz; i++) covered[i] = false;
    vector< ii > edge_cover;
    for(int i=1; i<sz-1; i++){
      for(FlowEdge e : adj[i]){
        if(e.cap == 0 || e.v > sz-2) continue;
        if(e.c == 0){
          edge_cover.pb(ii(i, e.v));
          covered[i] = true;
          covered[e.v] = true;
          break;
        }
      }
    }
    for(int i=1; i<sz-1; i++){
      for(FlowEdge e : adj[i]){
        if(e.cap == 0 || e.v > sz-2) continue;
        if(e.c == 0) continue;
        if(!covered[i] || !covered[e.v]){
          edge_cover.pb(ii(i, e.v));
          covered[i] = true;
          covered[e.v] = true;
        }
      }
    }
    return edge_cover;
  }
  
};
 
 
 
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  int p[n+1];
  int t[n+1][n+1], dist[n+1][n+1];
  for(int i=1; i<=n; i++) cin >> p[i];
  for(int i=1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin >> t[i][j];
      t[i][j] = t[i][j] + p[j];
      dist[i][j] = (i == j ? 0 : t[i][j]);
    }
  }
  
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j = 1; j<=n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  
  Dinic dinic(2*m);
  
  tuple<int,int,int> v[m+1];
  
  for(int i=1; i<=m; i++){
    int s,t,f;
    cin >> s >> f >> t;
    v[i] = make_tuple(s,t,f);
    dinic.add_to_src(i, 1);
    dinic.add_to_snk(i+m, 1);
  }
  
  for(int i=1; i<=m; i++){
    for(int j=1; j<=m; j++){
      if(i == j) continue;
      int s1,t1,f1,s2,t2,f2;
      tie(s1,t1,f1) = v[i];
      tie(s2,t2,f2) = v[j];
      //cout << i << " " << j << endl;
      //cout << t1 << " " << t[s1][f1] << " " << dist[f1][s2] << endl;
      if(t1 + t[s1][f1] + dist[f1][s2] <= t2){
        //cout << i << " " << j << endl;
        dinic.add_edge(i, j+m, 1);
      }
      
    }
  }
  dinic.calculate();
  //cout << "mf = " << dinic.max_flow << endl;
  cout << m - dinic.max_flow << endl; 
}
 
