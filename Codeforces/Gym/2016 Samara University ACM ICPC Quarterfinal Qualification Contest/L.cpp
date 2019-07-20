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
 
vector<int> adjt[212345], adj[212345];
int ans[212345] = {0};
int d[212345];
 
int32_t main(){
  DESYNC;
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adjt[v].pb(u);
  }
  for(int i=0; i<=n; i++) d[i] = INF;
  
  queue<int> q;
  d[0] = 0;
  q.push(0);
  
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    
    for(int v : adj[cur]){
      if(d[cur] + 1 < d[v]){
        d[v] = d[cur]+1;
        q.push(v);
      }
    }
  }
  
  for(int i=0; i<=n; i++){
    ans[i] += d[i];
    d[i] = INF;
  }
  
  
  d[a] = 0;
  q.push(a);
  
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    
    for(int v : adjt[cur]){
      if(d[cur] + 1 < d[v]){
        d[v] = d[cur]+1;
        q.push(v);
      }
    }
  }
  
  for(int i=0; i<=n; i++){
    ans[i] += d[i];
    d[i] = INF;
  }
  
  
  d[b] = 0;
  q.push(b);
  
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    
    for(int v : adjt[cur]){
      if(d[cur] + 1 < d[v]){
        d[v] = d[cur]+1;
        q.push(v);
      }
    }
  }
  
  for(int i=0; i<=n; i++){
    ans[i] += d[i];
  }
  
  int mx = INF;
  for(int i=0; i<=n; i++) mx = min(mx, ans[i]);
  cout << mx << endl; 
  
}
 
