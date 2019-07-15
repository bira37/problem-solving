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

//Graph - Tarjan Bridges Algorithm

//calculate bridges, articulations and all connected components

vector<int> adj[312345], adj2[312345];
int bcc[312345];
vector< ii > g[312345];
map< ii, int> cost;
int cnt = 0;
bool vis[312345] = {0};
set<int> has_art;

struct Tarjan{
  int cont = 0;
  vector<int> st;
  vector<int> low;
  vector< ii > bridges;
  vector<bool> isArticulation;
  
  Tarjan() {}
  
  Tarjan(int n){
    st.resize(n+1);
    low.resize(n+1);
    isArticulation.resize(n+1);
    cont = 0;
    bridges.clear();
  }
  
  void calculate(int u, int p = -1){
    st[u] = low[u] = ++cont;
    int son = 0;
    for(int i=0; i<adj[u].size(); i++){
      if(adj[u][i]==p){
        p = 0;
        continue;
      }
      if(!st[adj[u][i]]){
        calculate(adj[u][i], u);
        low[u] = min(low[u], low[adj[u][i]]);
        if(low[adj[u][i]] >= st[u]) isArticulation[u] = true; //check articulation

        if(low[adj[u][i]] > st[u]){ //check if its a bridge
          bridges.push_back(ii(u, adj[u][i]));
        }

        son++;
      }
      else low[u] = min(low[u], st[adj[u][i]]);
    }

    if(p == -1){
      if(son > 1) isArticulation[u] = true;
      else isArticulation[u] = false;
    }
  }
};

void go(int u){
  vis[u] = true;
  bcc[u] = cnt;
  for(int v : adj2[u]){
    if(cost[ii(u,v)] == 1) has_art.insert(cnt);
    if(vis[v]) continue;
    go(v);
  }
}

bool dfs(int u, int p, bool f, int t){
  bool ret = false;
  if(has_art.count(u)) f |= true;
  //cout << "at " << u << endl;
  if(u == t) return f;
  for(ii v : g[u]){
    if(v.ff == p) continue;
    ret |= dfs(v.ff, u, f | v.ss, t);
  }
  return ret;
} 
     
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v,c;
    cin >> u >> v >> c;
    adj[u].pb(v);
    adj[v].pb(u);
    cost[ii(u,v)] = c;
    cost[ii(v,u)] = c;
  }
  
  set< ii > edges;
  Tarjan tj(n);
  for(int i=1; i<=n; i++){
    if(tj.st[i]) continue;
    tj.calculate(i);
  }
  
  for(ii p : tj.bridges){
    edges.insert(p);
    swap(p.ff, p.ss);
    edges.insert(p);
  }
  
  for(int u=1; u<=n; u++){
    for(int v : adj[u]){
      if(edges.count(ii(u,v))) continue;
      adj2[u].pb(v);
      adj2[v].pb(u);
    }
  }
  
  for(int i=1; i<=n; i++){
    if(vis[i]) continue;
    cnt++;
    go(i);
  }
  
  for(ii e : edges){
    int u = e.ff;
    int v = e.ss;
    int c = cost[ii(u,v)];
    g[bcc[u]].pb(ii(bcc[v], c));
  }
  
  //for(int i=1; i<=n; i++) cout << i << " " << bcc[i] << endl;
  
  //for(int i=1; i<=n; i++){
    //for(ii v : g[i]) cout << i << " -> " << v.ff << ", " << v.ss << endl;
  //}
  
  int s,t;
  cin >> s >> t;
  s = bcc[s];
  t = bcc[t];
  //cout << "starting at " << s << " going to " << t << endl;
  if(dfs(s, -1, false, t)) cout << "YES" << endl;
  else cout << "NO" << endl;

}

