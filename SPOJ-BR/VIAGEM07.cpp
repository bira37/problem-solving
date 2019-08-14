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

vector<int> g[1123];
vector< ii > c[1123];
tuple<int,int,int> dist[1123];

int32_t main(){
  DESYNC;
  int n,m;
  char l;
  bool change = false;
  cin >> n >> m >> l;
  if(l == 'E') change = true;
  int ini, fim;
  cin >> ini >> fim;
  for(int i=0; i<m; i++){
    int u,v,c1,c2;
    cin >> u >> v >> c1 >> c2;
    if(change) swap(c1,c2);
    g[u].pb(v);
    c[u].pb(ii(c1,c2));
  }
  
  for(int i=0; i<=n; i++) dist[i] = make_tuple(INF,INF,INF);
  
  set< tuple<int,int,int,int> > s;
  dist[ini] = make_tuple(0, 0, 0);
  s.insert(make_tuple(0, 0, 0, ini));
  while(!s.empty()){
    int c1,c2,ed, cur;
    tie(c1, c2, ed, cur) = *s.begin();
    s.erase(s.begin());
    tuple<int,int,int> cst(c1,c2, ed);
    if(cst != dist[cur]) continue;
    for(int i=0; i<g[cur].size(); i++){
      int nc1 = c1 +  c[cur][i].ff;
      int nc2 = c2 + c[cur][i].ss;
      int nc3 = ed+1;
      int v = g[cur][i];
      if(tie(nc1, nc2, nc3) < dist[v]){
        dist[v] = make_tuple(nc1, nc2, nc3);
        s.insert(make_tuple(nc1, nc2, nc3, v));
      }
    }
  }
  if(dist[fim] < make_tuple(INF,INF,INF)){
    int c1, c2, c3;
    tie(c1,c2,c3) = dist[fim];
    if(change) swap(c1, c2);
    cout << c1 << " " << c2 << " " << c3-1 << endl;
  }
  else cout << -1 << endl;
  
}


