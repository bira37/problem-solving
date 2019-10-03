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

vector< ii > g[112345];
int ans, r1, r2;
int d[112345];

void go(int u, int p, int w, int & root){
  if(w >= ans){
    root = u;
    ans = w;
  }
  for(ii ed : g[u]){
    int v = ed.ff;
    int c = ed.ss;
    if(v == p) continue;
    go(v, u, w + c, root);
  }
}

void calc(int u, int p, int w){
  d[u] = max(d[u], w);
  for(ii ed : g[u]){
    int v = ed.ff;
    int c = ed.ss;
    if(v == p) continue;
    calc(v, u, w+c);
  }
}

int32_t main(){
  DESYNC;
  int q;
  cin >> q;
  while(q--){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
      g[i].clear();
      d[i] = 0;
    }
    for(int i=1; i<=n-1; i++){
      int u,v,c;
      cin >> u >> v >>c;
      g[u].pb(ii(v,c));
      g[v].pb(ii(u,c));
    }
    ans = 0; go(1, -1, 0, r1);
    ans = 0; go(r1, -1, 0, r2);
    calc(r1, -1, 0);
    calc(r2, -1, 0);
    for(int i=1; i<=n; i++){
      if(i > 1) cout << " ";
      cout <<d[i];
    }
    cout << endl;
  }
}


