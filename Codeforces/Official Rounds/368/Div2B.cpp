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
 
int32_t main(){
  DESYNC;
  int n,m, k;
  cin >> n >> m >> k;
  queue< ii > q;
  vector<int> dist(n+1, INF);
  vector< ii > g[n+1];
  for(int i=0; i<m; i++){
    int u,v, c;
    cin >> u >> v >> c;
    g[u].pb(ii(v, c));
    g[v].pb(ii(u, c));
  }
  for(int i=0; i<k; i++){
    int x;
    cin >> x;
    dist[x] = 0;
    q.push(ii(x, dist[x]));
  }
  while(!q.empty()){
    int u = q.front().ff;
    int d = q.front().ss;
    q.pop();
    if(d != dist[u]) continue;
    for(ii ad : g[u]){
      int v = ad.ff;
      int c = ad.ss;
      if(d+c < dist[v]){
        dist[v] = d+c;
        q.push(ii(v, dist[v]));
      }
    }
  }
  int ans = INF;
  for(int i=1; i<=n; i++) if(dist[i] != 0) ans = min(ans, dist[i]);
  if(ans == INF) ans = -1;
  cout << ans << endl;
}
 
