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

set<int> adj[1123];
vector< vector<int> > comp;
bool vis[1123] = {0};

void dfs(int u){
  comp.back().pb(u);
  vis[u] = true;
  for(int v : adj[u]){
    if(vis[v]) continue;
    dfs(v);
  }
}

vector< ii > color[112];

int nxt = 1;
set<int> used;
int dg[112] = {0};

int next(){
  while(used.count(nxt)) nxt++;
  used.insert(nxt);
  return nxt;
}

bool go(int u){
  while(adj[u].size() > 0){
    int v = *adj[u].begin();
    adj[u].erase(adj[u].begin());
    int novo = next();
    color[u].pb(ii(u, novo));
    color[v].pb(ii(v, novo));
  }
}
        
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    dg[u]++;
    dg[v]++;
    if(u > v) swap(u,v);
    adj[u].insert(v);
  }
  for(int i=1; i<=n; i++){
    go(i);
  }
  for(int i=1; i<=n; i++){
    for(int j = 1; j<=adj[i].size(); j++){
      color[i].pb(ii(i, next()));
    }
    if(color[i].size() == 0) color[i].pb(ii(i, next()));
  }
  for(int i=1; i<=n; i++){
    cout << color[i].size() << endl;
    for(ii p : color[i]) cout << p.ff << " " << p.ss << endl;
  }           
}
         

