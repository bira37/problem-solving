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
 
int subsz[212345];
bool val[212345];
vector<int> g[212345];
int ans= 0;
int n,k;
 
 
void go(int u, int p){
  subsz[u] = val[u];
  for(int v : g[u]){
    if(v == p) continue;
    go(v, u);
    subsz[u] += subsz[v];
  }
  
  for(int v : g[u]){
    if(v == p) continue;
    ans += min(subsz[v], 2*k - subsz[v]);
  }
}
 
int32_t main(){
  DESYNC;
  cin >> n >> k;
  for(int i=0; i<2*k; i++){
    int x;
    cin >> x;
    val[x] = true;
  }
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  go(1, -1);
  cout << ans << endl;
}
 
