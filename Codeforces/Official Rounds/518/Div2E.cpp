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

vector<int> adj[112345];
int dg[112345] = {0};
int deg[112345] = {0};
bool ok = true;
int parameter = -1;

void go(int u, int p = -1, int level = 0){
  int visited = 0;
  for(int v : adj[u]){
    if(v == p) continue;
    visited++;
    go(v, u, level+1);
  }
  if(visited != 0 && visited < 3) ok = false;
  else if(visited == 0){
    if(parameter == -1) parameter = level;
    else if(parameter != level) ok = false;
  }
}

int32_t main(){
  DESYNC;
  int n, k;
  cin >> n >> k;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    dg[u]++; dg[v]++;
    deg[u]++; deg[v]++;
  }
  int level = 1;
  vector<int> cur;
  for(int i=1; i<=n; i++){
    if(dg[i] <= 1) cur.pb(i);
  }
  while(cur.size() > 2){
    vector<int> new_cur;
    for(int u :cur){
      for(int v : adj[u]){
        dg[v]--;
        if(dg[v] == 1) new_cur.pb(v);
      }
    }
    cur.clear();
    for(int x : new_cur) cur.pb(x);
  }
  if(deg[cur.front()] >= 3) {
    go(cur.front());
    if(ok && k == parameter){
      cout << "Yes" << endl;
      return 0;
    }
  } 
  if(deg[cur.back()] >= 3) {
    go(cur.back());
    parameter = -1;
    ok = true;
    if(ok && k == parameter){
      cout << "Yes" << endl;
      return 0;
    }
  }
    cout << "No" << endl;
}