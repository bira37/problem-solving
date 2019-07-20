#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
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
 
bool vis[1123];
 
void dfs_de_doente(Dinic & dinic, int v){
  vis[v] = true;
  for(Dinic::FlowEdge e : dinic.adj[v]){
    if(!vis[e.v] && e.cap - e.c < e.cap) dfs_de_doente(dinic, e.v);
  }
}
 
int32_t main(){
	//DESYNC;
	ifstream cin("high.in");
	ofstream cout("high.out");
	int n;
	cin >> n;
	int w[n+1];
	int a[n+1][n+1];
	map<string, int> name_to_id;
	map<int, string> id_to_name;
	for(int i=1; i<=n; i++){
	  string s;
	  cin >> s >> w[i];
	  name_to_id[s] = i;
	  id_to_name[i] = s;
	}
	for(int i=1; i<=n; i++){
	  for(int j=1; j<=n; j++){
	    cin >> a[i][j];
	  }
	}
	for(int i=1; i<=n; i++){
	  int k = 0;
	  for(int j=0; j<=n*n+n+2; j++) vis[j] = false; 
	  for(int j=1; j<=n; j++) k += a[i][j];
	  k += w[i];
	  int cnt = 0;
	  Dinic dinic(n*n+n);
	  for(int t1 = 1; t1 <= n; t1++){
	    for(int t2 = t1+1; t2 <= n; t2++){
	      if(t1 == i || t2 == i) continue;
	      dinic.add_edge(n + t1*n + (t2-1), t1, INF);
	      dinic.add_edge(n + t1*n + (t2-1), t2, INF);
	      dinic.add_to_src(n + t1*n + (t2-1), a[t1][t2]);
	      cnt += a[t1][t2];
	    }
	  }
	  bool ok = true;
	  for(int j=1; j<=n && ok; j++){
	    if(j == i) continue;
	    dinic.add_to_snk(j, k - w[j]);
	    if(k - w[j] < 0){
	      cout << id_to_name[i] << " cannot win because of the following teams:" << endl;
	      cout << "    " << id_to_name[j] << endl;
	      ok = false;
	    }
	  }
	  if(!ok) continue;
	  dinic.calculate();
	  if(dinic.max_flow == cnt){
	    cout << id_to_name[i] << " can win" << endl;
	  }
	  else {
	    vector<string> ans;
	    dfs_de_doente(dinic, dinic.src);
	    for(int j=1; j<=n; j++){
	      if(i == j) continue;
	      if(vis[j]) ans.push_back(id_to_name[j]);
	    }
	    cout << id_to_name[i] << " cannot win because of the following teams:" << endl;
	    cout << "   ";
	    for(string t : ans){
	      if(t == ans[0]) cout << " " << t;
	      else cout << ", " << t;
	    }
	    cout << endl;
	  }
	}
}
