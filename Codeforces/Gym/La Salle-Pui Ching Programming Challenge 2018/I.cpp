#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define EPS 1e-9
#define INF (int)1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return n%1000000007; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
vector<int> adj[112345];
bool vis[112345];
 
int32_t main(){
  DESYNC;
  
  int n,m;
  cin >> n >> m;
  
  for(int i=0; i<112345; i++) vis[i] = false;
  
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  vector<int> pa(n);
  for(int i=0; i<n; i++){
    cin >> pa[i];
  }
  
  int valid[n+1];
  for(int i=0; i<=n; i++){
    valid[i] = -1;
    vis[i] = false;
  }
  
  set<int> cand;
  vector<int> perm;
  if(pa[0] < n){
    valid[0] = pa[0]+1;
  }
  vis[pa[0]] = true;
  for(int v : adj[pa[0]]) if(!vis[v]) cand.insert(v);
  
  //cout << "aq1" << endl;
  for(int i=1; i<n; i++){
    //cout << "at " << i << " " << pa[i] << endl;
    //for(int i=0; i<n; i++) cout << valid[i] << " ";
    //cout << endl;
    //for(int x : cand) cout << x << " ";
    //cout << endl;
    auto it = cand.upper_bound(pa[i]);
    if(it != cand.end()){
      valid[i] = *it;
    }
    if(cand.count(pa[i])){
      cand.erase(cand.find(pa[i]));
      vis[pa[i]] = true;
      for(int v : adj[pa[i]]) if(!vis[v]) cand.insert(v);
    }
  }
  int start = -1;
  int guy = -1;
  for(int i=n-1; i>=0; i--){
    if(valid[i] != -1){
      guy = valid[i];
      start = i;
      break;
    }
  }
  if(start == -1){
    cout << -1 << endl;
    return 0;
  }
  for(int i=0; i<=n; i++){
    vis[i] = false;
  }
  cand.clear();
  
  //for(int i=0; i<n; i++) cout << valid[i] << " ";
  //cout << endl;
  
  vis[guy] = true;
  
  for(int i=0; i<start; i++){
    perm.pb(pa[i]);
    vis[pa[i]] = true;
  }
  for(int i=0; i<start; i++){
    for(int v : adj[pa[i]]) if(!vis[v]) cand.insert(v);
  }
  perm.pb(guy);
  for(int v : adj[guy]) if(!vis[v]) cand.insert(v);
  //for(int x : cand) cout << x << " ";
  //cout << endl;
  for(int i=start; i<n; i++){
    int cur = *cand.begin();
    cand.erase(cur);
    perm.pb(cur);
    vis[cur] = true;
    for(int v : adj[cur]) if(!vis[v]) cand.insert(v);
  }
  
  if(pa >= perm) cout << -1 << endl;
  else {
    for(int i=0; i<n; i++){
      if(i) cout << " ";
      cout << perm[i];
    }
    cout << endl;
  }
}
