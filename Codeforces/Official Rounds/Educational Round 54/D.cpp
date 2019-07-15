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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

vector< tuple<int,int,int> > g[312345];
int d[312345];
map< ii, int> id;

ii edge(int u, int v){
  if(u > v ) swap(u,v);
  return ii(u,v);
}

int32_t main(){
  DESYNC;
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0; i<=n; i++) d[i] = (int)1e16;
  for(int i=0; i<m; i++){
    int u,v,c;
    cin >> u >> v >> c;
    g[u].pb(mt(v,c, i+1));
    g[v].pb(mt(u,c, i+1));
    id[edge(u,v)] = i+1;
  }
  set<int> keep;
  set< tuple<int,int,int> > s;
  d[1] = 0;
  s.insert(mt(d[1], -1, 1));
  while(!s.empty() && keep.size() < k){
    int u,p,dst;
    tie(dst,p,u) = *s.  begin();
    s.erase(s.begin());
    if(d[u] != dst) continue;
    if(p != -1) keep.insert(id[edge(p,u)]);
    for(auto v : g[u]){
      int ad, id, dst;
      tie(ad, dst, id) = v;
      if(d[u] + dst < d[ad]){
        d[ad] = dst + d[u];
        s.insert(mt(d[ad], u, ad));
      }
    }
  }
  cout << keep.size() << endl;
  for(int x : keep) cout << x << " ";
  cout << endl;
}

