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
 
vector<int> adj[112345];
int c[112345];
bool vis[112345] = {0};
bool xablau = false;
int sz;
int cnt[2];
 
void go(int u){
  vis[u] = true;
  sz++;
  for(int v : adj[u]){
    if(vis[v]) continue;
    go(v);
  }
}
 
void dfs(int u, int color){
  c[u] = color;
  vis[u] = true;
  cnt[c[u]]++;
  for(int v : adj[u]){
    if(c[v] == c[u]){
      xablau = true;
    }
    if(vis[v]) continue;
    dfs(v, color^1);
    if(xablau) return;
  }
}
 
int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  if(m == 0){
    cout << 3 << " " << (n*(n-1)*(n-2))/6 << endl;
    return 0;
  }
  
  for(int i=0; i<m; i++){
    int a,b;
    cin >>a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  
  vector<int> two, more;
  for(int i=1; i<=n; i++){
    if(vis[i]) continue;
    sz = 0;
    go(i);
    if(sz == 2) two.pb(i);
    else if(sz > 2) more.pb(i);
  }
  if(more.size() == 0){
    cout << 2 << " " << two.size()*(n-2) << endl;
    return 0;
  }
  
  for(int i=1; i<=n; i++){
    vis[i] = false;
    c[i] = -1;
  }
  int ans = 0;
  for(int u : more){
    cnt[0] = 0, cnt[1] = 0;
    dfs(u, 0);
    if(xablau){
      cout << 0 << " " << 1 << endl;
      return 0;
    }
    ans += (cnt[0]*(cnt[0]-1))/2 + (cnt[1]*(cnt[1]-1))/2;
  }
  cout << 1 << " " << ans << endl;   
}
 
