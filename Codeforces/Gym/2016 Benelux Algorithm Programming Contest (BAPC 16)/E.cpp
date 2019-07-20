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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int n,m,x;
 
vector<ii> adj[11234];
int dist[11234];
int sp;
 
bool check(int k){
  for(int i=0; i<=n; i++) dist[i] = INF;
  set< ii > s;
  s.insert(ii(0, 1));
  dist[1] = 0;
  while(!s.empty()){
    int u = s.begin()->second;
    int d = s.begin()->first;
    s.erase(s.begin());
    if(dist[u] < d) continue;
    for(ii ad : adj[u]){
      int v = ad.ff;
      int c = ad.ss;
      if(c <= k && d + c < dist[v]){
        dist[v] = d+c;
        s.insert(ii(dist[v], v));
      }
    }
  }
  if((dist[n] - sp)*100 <= x*sp) return true;
  else return false;
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m >> x;
  for(int i=0; i<m; i++){
    int u,v,c;
    cin >> u >> v >> c;
    adj[u].pb(ii(v,c));
    adj[v].pb(ii(u,c));
  }
  int l = 1, r = (int)1e10;
  check(1e10);
  sp = dist[n];
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m)){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  cout << ans << endl;
}
 
 
