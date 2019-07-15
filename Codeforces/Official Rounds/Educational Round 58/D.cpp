#include <bits/stdc++.h>

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
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

vector<int> g[212345];
map<int, int> m[212345];
int ans = 0;
int a[212345];

void go(int u, int p){
  if(a[u] > 1) m[u][a[u]] = 1;
  for(int v : g[u]){
    if(v == p) continue;
    go(v,u);
    for(auto p : m[v]){
      for(auto q : m[u]){
        if(gcd(q.ff, p.ff)> 1){
          ans = max(ans, q.ss + p.ss);
        }
      }
    }
    for(auto p : m[v]){
      int g = gcd(p.ff, a[u]);
      if(g > 1) m[u][g] = max(m[u][g], p.ss+1);
    }
  }
  for(auto p : m[u]){
    ans = max(ans, p.ss);
  }
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) cin >> a[i];
  for(int i=1; i<=n-1; i++){
    int u,v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  go(1, -1);
  cout << ans << endl;
}

