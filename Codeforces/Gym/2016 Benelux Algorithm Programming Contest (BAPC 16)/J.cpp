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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
ii t[112], s[112];
bool vis[112];
int n;
 
int dist(ii a, ii b){
  return abs(a.ff - b.ff) + abs(a.ss - b.ss);
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
  
};
 
bool check(int d){
  Dinic dinic(2*n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(dist(s[i], t[j]) <= d) dinic.add_edge(i+1, j+1+n, 1);
    }
  }
  for(int i=1; i<=n; i++) dinic.add_to_src(i, 1);
  for(int j=1; j<=n; j++) dinic.add_to_snk(j+n, 1);
  dinic.calculate();
  return dinic.max_flow == n;
}
 
int32_t main(){
  DESYNC;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s[i].ff >> s[i].ss;
  }
  for(int i=0; i<n; i++){
    cin >> t[i].ff >> t[i].ss;
  }
  int l = 0, r = (int)1e9;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m)){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  cout << ans << endl;
}
 
