#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}


vector<int> adj[412345];

//Graph - Tarjan Bridges Algorithm

//calculate bridges, articulations and all connected components

struct Tarjan{
  int cont = 0;
  vector<int> st;
  vector<int> low;
  set< ii > bridges;
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
          bridges.insert(ii(u, adj[u][i]));
          bridges.insert(ii(adj[u][i], u));
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

int uf[412345];
int sz[412345];
bool vis[412345];

int find(int u){
  if(uf[u] == u) return u;
  else return uf[u] = find(uf[u]);
}

bool merge(int u, int v){
  int a = find(u);
  int b = find(v);
  if(a == b) return false;
  if(sz[b] > sz[a]) swap(a,b);
  uf[b] = a;
  sz[a] += sz[b];
  return true;
}

void go(int u, Tarjan & tarjan){
  vis[u] = true;
  for(int v : adj[u]){
    if(tarjan.bridges.count(ii(u,v))) continue;
    if(vis[v]) continue;
    merge(u,v);
    go(v, tarjan);
  }
}

void solve(int u, Tarjan & tarjan, set<ii> & s){
  //cout << "at " << u << endl;
  vis[u] = true;
  for(int v : adj[u]){
    if(!s.count(ii(u,v)) and !s.count(ii(v,u))){
      if(tarjan.bridges.count(ii(u,v))){
        //cout << "orienting to " << v << " " << u << endl;
        s.insert(ii(v,u));
      }
      else {
        //cout << "orienting to " << u << " " << v << endl;
        s.insert(ii(u,v));
      }
    }
    if(vis[v]) continue;
    solve(v, tarjan, s);
  }
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  ii ed[m];
  for(int i=1; i<=n; i++){
    uf[i] = i;
    sz[i] = 1;
  }
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    ed[i] = ii(u,v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  Tarjan tarjan(n);
  tarjan.calculate(1);
  int bst = -1;
  int st = -1;
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      go(i, tarjan);
      if(sz[find(i)] > bst){
        bst = sz[find(i)];
        st = find(i);
      }
    }
  }
  
  cout << bst << endl;
  
  set<ii> s;
  for(int i=1; i<=n; i++) vis[i] = false;
  solve(st, tarjan, s);
  
  for(int i=0; i<m; i++){
    if(s.count(ii(ed[i].ff, ed[i].ss))) cout << ed[i].ff << " " << ed[i].ss << endl;
    else cout << ed[i].ss << " " << ed[i].ff << endl;
  }
    
  
}
 
