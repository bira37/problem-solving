#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
vector<int> love[112345];
vector<int> hate[112345];
int comp[112345];
bool vis[112345];
int c[112345];
 
void dfs(int u, int k){
  comp[u] = k;
  vis[u] = true;
  for(int v : love[u]){
    if(vis[v]) continue;
    dfs(v, k);
  }
}
 
bool go(int u, int color){
  c[u] = color;
  bool ans = true;
  for(int v : hate[u]){
    if(c[v] == color) return false;
    if(c[v] != -1) continue;
    ans &= go(v, color^1);
  }
  return ans;
}
 
int32_t main(){
	DESYNC;
	int n,m;
	cin >> n >> m;
	vector< ii > to_add;
	for(int i=0; i<m; i++){
	  int u,v,c;
	  cin >> u >> v >> c;
	  if(c == 1) love[u].pb(v), love[v].pb(u);
	  else to_add.pb(ii(u,v));
	}
	for(int i=0; i<=n; i++){
	  vis[i] = false;
	}
	int k = 1;
	for(int i=1; i<=n; i++){
	  if(!vis[i]){
	    dfs(i, k);
	    k++;
	  }
	}
	for(ii p : to_add){
	  int u = p.ff;
	  int v = p.ss;
	  hate[comp[u]].pb(comp[v]);
	  hate[comp[v]].pb(comp[u]);
	}
	for(int i=0; i<k; i++){
	  c[i] = -1;
	}
	int ans = 0;
	for(int i=1; i<k; i++){
	  if(c[i] == -1){
	    if(!go(i, 0)){
	     cout << 0 << endl;
	     return 0;
	    }
	    ans++;
	  }
	}
	int ret = 1;
	for(int i=0; i<ans-1; i++) ret = mod(ret*2LL);
	cout << ret << endl;
}
 
