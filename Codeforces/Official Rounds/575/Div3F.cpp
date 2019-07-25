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
 
int32_t main(){
  DESYNC;
  int n,m,k;
  cin >> n >> m >> k;
  vector<ii> g[n+1];
  for(int i=0; i<m; i++){
    int u,v,a;
    cin >> u >> v >> a;
    g[u].pb(ii(v,a));
    g[v].pb(ii(u,a));
  }
  for(int i = 1; i <= n; i++){
    sort(g[i].begin(), g[i].end(), [](ii & a, ii & b){
      return a.ss < b.ss;
    });
    while(g[i].size() > k) g[i].pop_back();
  }
  vector<int> paths;
  set< tuple<int,int,int> > s;
  for(int i=1; i<=n; i++){
    s.insert(mt(0, i, i));
  }
  int cnt = 0;
  map<ii, int> d;
  set< ii > counted;
  while(cnt < k && s.size() > 0){
    int u = get<1>(*s.begin());
    int dst = get<0>(*s.begin());
    int ref = get<2>(*s.begin());
    s.erase(s.begin());
    if(d.count(ii(ref, u)) and d[ii(ref, u)] < dst) continue;
    if(u != ref && !counted.count(ii(min(u,ref), max(u,ref)))){
      cnt++;
      counted.insert(ii(min(u,ref), max(u,ref)));
    }
    if(cnt == k){
      cout << dst << endl;
      return 0;
    }
    for(int i=0; i<g[u].size(); i++){
      int v = g[u][i].ff;
      int cst = g[u][i].ss;
      int val;
      if(d.count(ii(ref, v))) val = d[ii(ref, v)];
      else val = INF;
      if(val > dst + cst){
        d[ii(ref, v)] = dst+cst;
        s.insert(mt(dst+cst, v, ref));
      }
    }
  }
}
