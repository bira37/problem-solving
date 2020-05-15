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
    int v, rev, c;
    FlowEdge() {}
    FlowEdge(int v, int c, int rev) : v(v), c(c), rev(rev) {}
  };
  
  vector< vector<FlowEdge> >  adj;
  vector<int> level;
  int src, snk;
  int sz;
  int max_flow;
  Dinic(){}
  Dinic(int n){
    src = 0;
    snk = n+1;
    adj.resize(n+2, vector< FlowEdge >());
    level.resize(n+2);
    sz = n+2;
    max_flow = 0;
  }
  
  void add_edge(int u, int v, int c){
    int id1 = adj[u].size();
    int id2 = adj[v].size();
    adj[u].pb(FlowEdge(v, c, id2));
    adj[v].pb(FlowEdge(u, 0, id1));
  }
  
  void add_to_src(int v, int c){
    adj[src].pb(FlowEdge(v, c, -1));
  }
  
  void add_to_snk(int u, int c){
    adj[u].pb(FlowEdge(snk, c, -1));
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
    
    for(FlowEdge &e : adj[u]){
      
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
      while(int inc = send_flow(src, INF)) max_flow += inc;
    }
    
  }
  
};

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	ii v[n+1];
	for(int i=1; i<=n; i++){
	  cin >> v[i].ff >> v[i].ss;
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++){
	  //do for i
	  Dinic dinic(n+n+2);
	  int cnt = 0;
	  for(int j = 1; j<=n; j++){
	    if(i == j) continue;
	    if(v[j].ff == i || v[j].ss == i) cnt++;
	  }
	  
	  for(int j=1; j<=n; j++){
	    if(i == j) continue;
	    dinic.add_to_src(j, 1);
	    if(v[i].ff == j || v[i].ss == j) dinic.add_to_snk(j+n, cnt-2);
	    else dinic.add_to_snk(j+n, cnt-1);
	  }
	  
	  for(int j=1; j<=n; j++){
	    if(i == j) continue;
	    if(v[j].ff == i || v[j].ss == i) continue;
	    dinic.add_edge(j, v[j].ff+n, 1);
	    dinic.add_edge(j, v[j].ss+n, 1);
	  }
	  
	  dinic.calculate();
	  if(dinic.max_flow < n-1-cnt) ans++;
	}

	cout << ans <<endl;
}


