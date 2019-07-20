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
  
};
 
int n=0,m=0;
vector<string> A;
 
int conv(int x, int y){
  return x*m + y + 1;
}
 
int dx[] = {0,1,0,-1};
int dy[] = {1, 0, -1, 0};
 
bool valid(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m;
}
 
int32_t main(){
  DESYNC;
  string s;
  while(getline(cin, s)){
    A.clear();
    if(s.size() > 0){
      m = s.size();
      A.pb(s);
      while(getline(cin, s), s.size() > 0){
        n++;
        A.pb(s);
      }
    }
    n = A.size();
    
    Dinic dinic(n*m + n*m);
    
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(A[i][j] == 'W'){
          dinic.add_to_src(conv(i,j), 1);
          for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(!valid(x,y)) continue;
            if(A[x][y] == 'I') dinic.add_edge(conv(i,j), conv(x,y), 1);
          }
        }
        else if(A[i][j] == 'I'){
          dinic.add_edge(conv(i,j), conv(i,j) + n*m, 1);
          for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(!valid(x,y)) continue;
            if(A[x][y] == 'N') dinic.add_edge(conv(i,j) + n*m, conv(x,y) + n*m, 1);
          }
        }
        else if(A[i][j] == 'N'){
          dinic.add_to_snk(conv(i,j) + n*m, 1);
        }
      }
    }
    dinic.calculate();
    cout << dinic.max_flow << endl;
  }
}
