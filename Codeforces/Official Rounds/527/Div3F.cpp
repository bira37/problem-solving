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

int c[212345];
vector<int> adj[212345];
int sub[212345];
int ans = 0;
int cur = 0;

void calc(int u, int p, int h){
  cur += c[u]*h;
  sub[u] = c[u];
  for(int v : adj[u]){
    if(v == p) continue;
    calc(v,u,h+1);
    sub[u] += sub[v];
  }
}

void go(int u, int p, int val){
  ans = max(ans, val);
  for(int v : adj[u]){
    if(v == p) continue;
    go(v, u, val - sub[v] + (sub[1] - sub[v]));
  }
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) cin >> c[i];
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  calc(1, -1, 0);
  ans = max(ans, cur);
  go(1, -1, cur);
  
  cout << ans << endl;  
}

