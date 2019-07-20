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
 
vector<int> adj[212345];
int dg[212345];
int cnt[212345];
bool vis[212345];
 
void dfs(int u){
  vis[u] = true;
  for(int v : adj[u]){
    if(vis[v]) continue;
    cnt[v]++;
    if(2*cnt[v] >= dg[v]) dfs(v);
  }
}
 
int32_t main(){
  DESYNC;
  int n,m,x,s;
  cin >> n >> m >> x >> s;
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    dg[u]++, dg[v]++;
  }
  dfs(s);
  if(vis[x]) cout << "leave" << endl;
  else cout << "stay" << endl;    
}
 
