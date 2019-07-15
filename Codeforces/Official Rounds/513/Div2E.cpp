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

vector<int> adj[212345];
int cnt[2];
int subsz[212345];
int ans = 0;
int n;

void dfs(int u, int p, int l){
  subsz[u] = 1;
  if(l%2) cnt[1]++;
  else cnt[0]++;
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u, l+1);
    subsz[u] += subsz[v];
  }
  for(int v : adj[u]){
    if(v == p) continue;
    ans += subsz[v]*(n - subsz[v]);
  }
}

int32_t main(){
  DESYNC;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin>> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cnt[0] = 0, cnt[1] = 0;
  dfs(1, -1, 0);
  ans += cnt[0]*cnt[1];
  cout << ans/2 << endl;
}

