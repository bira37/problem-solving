#include <bits/stdc++.h>
 
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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
vector<int> adj[1123456];
int st[1123456];
int ed[1123456];
int tempo = 1;
int v[2123456];
ii sg[8123456];
int lazy[8123456];
 
 
void dfs(int u){
  st[u] = tempo++;
  for(int v : adj[u]){
    dfs(v);
  }
  ed[u] = tempo++;
}
 
void build(int cur, int l, int r){
  lazy[cur] = 0;
  if(l == r){
    sg[cur] = ii(v[l], v[l]);
    return;
  }
  
  int m = (l+r)>>1;
  
  build(2*cur, l, m);
  build(2*cur+1, m+1, r);
  
  sg[cur].ff = min(sg[2*cur].ff, sg[2*cur+1].ff);
  sg[cur].ss = max(sg[2*cur].ss, sg[2*cur+1].ss);
}
 
void propagate(int cur, int l, int r){
  if(lazy[cur] == 0) return;
  sg[cur].ff += lazy[cur];
  sg[cur].ss += lazy[cur];
  if(l != r){
    lazy[2*cur] += lazy[cur];
    lazy[2*cur+1] += lazy[cur];
  }
  lazy[cur] = 0;
}
 
void update(int cur, int l, int r, int a, int b, int s){
  propagate(cur, l, r);
  if(b < l || r < a) return;
  
  if(a <= l && r <= b){
    lazy[cur] += s;
    propagate(cur, l, r);
    return;
  }
  
  int m = (l+r)>>1;
  update(2*cur, l, m, a, b, s);
  update(2*cur+1, m+1, r, a, b, s);
  
  sg[cur].ff = min(sg[2*cur].ff, sg[2*cur+1].ff);
  sg[cur].ss = max(sg[2*cur].ss, sg[2*cur+1].ss);
}
 
ii query(int cur, int l, int r, int a, int b){
  propagate(cur, l, r);
  if(b < l || r < a) return ii(INF, -INF);
  
  if(a <= l && r <= b) return sg[cur];
  int m = (l+r)>>1;
  
  ii lef = query(2*cur, l, m, a, b);
  ii rig = query(2*cur+1, m+1, r, a, b);
  
  return ii(min(lef.ff, rig.ff), max(lef.ss, rig.ss));
  
}
  
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    tempo = 1;
    for(int i=1; i<=n; i++){
      adj[i].clear();
    }
    for(int i=2; i<=n; i++){
      int p;
      cin >> p;
      adj[p].pb(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
      int x;
      cin >> x;
      v[st[i]] = x;
      v[ed[i]] = x;
    }
    build(1, 1, 2*n);
    int q;
    cin >> q;
    while(q--){
      char op;
      cin >> op;
      if(op == 'Q'){
        int x;
        cin >> x;
        ii qry = query(1, 1, 2*n, st[x], ed[x]);
        cout << qry.ss - qry.ff << endl;
      }
      else {
        int id, x;
        cin >> id >> x;
        update(1, 1, 2*n, st[id], ed[id], x);
      }
    }
  }
        
}
 
