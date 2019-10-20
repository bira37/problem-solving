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

vector<int> g[350];
vector<int> cst[350];
ii d[350][350];

int32_t main(){
  DESYNC;
  int n,m,l;
  cin >> n >> m >> l;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    g[a].pb(b);
    g[b].pb(a);
    cst[a].pb(c);
    cst[b].pb(c);
  }

  //for each vertex do dijkstra
  for(int vertex=1; vertex<=n; vertex++){
    set< pair< ii, int> > s;
    for(int i=1; i<=n; i++) d[vertex][i] = ii(INF, -l);
    d[vertex][vertex] = ii(0, -l);
    s.insert(pair< ii, int>(ii(0, -l), vertex));
    while(s.size() > 0){
      int u = s.begin()->second;
      ii cur = s.begin()->first;
      s.erase(s.begin());
      if(d[vertex][u] != cur) continue;

      //break into cases
      for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        int c = cst[u][i];

        //just consume fuel
        if(c <= abs(cur.ss) and d[vertex][v] > ii(cur.ff, cur.ss + c)){
          d[vertex][v] = ii(cur.ff, cur.ss + c);
          s.insert(pair< ii, int>(d[vertex][v], v));
        }

        //put fuel and go
        if(c <= l and d[vertex][v] > ii(cur.ff +1, -l + c)){
          d[vertex][v] = ii(cur.ff +1, -l + c);
          s.insert(pair< ii, int>(d[vertex][v], v));
        }
      }
    }
  }
  int q;
  cin >> q;
  while(q--){
    int s,t;
    cin >> s >> t;
    if(d[s][t].ff == INF) cout << -1 << endl;
    else cout << d[s][t].ff << endl;
  }
}



