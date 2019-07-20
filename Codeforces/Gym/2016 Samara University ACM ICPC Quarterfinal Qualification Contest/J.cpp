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
 
int st_sum[812345] = {0};
ii st_min[812345];
int lazy[812345] = {0};
 
void build(int cur, int l, int r){
  if(l == r){
    st_min[cur] = ii(0LL, l);
    return;
  }
  
  int m = (l+r)>>1;
  build(2*cur, l, m);
  build(2*cur+1, m+1, r);
  st_sum[cur] = st_sum[2*cur] + st_sum[2*cur+1];
  if(st_min[2*cur].ff < st_min[2*cur+1].ff) st_min[cur] = st_min[2*cur];
  else st_min[cur] = st_min[2*cur+1];
}
 
void propagate(int cur, int l, int r){
  if(lazy[cur] == 0) return;
  
  st_sum[cur] += (r-l+1)*lazy[cur];
  
  st_min[cur].ff += lazy[cur];
  
  if(l != r){
    lazy[2*cur] += lazy[cur];
    lazy[2*cur+1] += lazy[cur];
  }
  
  lazy[cur] = 0;
}
 
void update(int cur, int l, int r, int a, int b, int x){
  propagate(cur, l, r);
  if(b < l || r < a) return;
  if(a <= l && r <= b){
    lazy[cur] += x;
    propagate(cur, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(2*cur, l, m, a, b, x);
  update(2*cur+1, m+1, r, a, b, x);
  st_sum[cur] = st_sum[2*cur] + st_sum[2*cur+1];
  if(st_min[2*cur].ff < st_min[2*cur+1].ff) st_min[cur] = st_min[2*cur];
  else st_min[cur] = st_min[2*cur+1];
}
 
ii query(int cur, int l, int r, int a ,int b){
  propagate(cur, l, r);
  
  if(b < l || r < a) return ii(INF, -1);
  
  if(a <= l && r <= b){
    return st_min[cur];
  }
  
  int m = (l+r)>>1;
  
  ii lef = query(2*cur, l, m, a, b);
  ii rig = query(2*cur+1, m+1, r, a, b);
  if(lef.ff < rig.ff) return lef;
  else return rig;
}
 
vector< ii > seg;
int n;
void solve(int l, int r){
  if(r < l) return;
  seg.pb(ii(l,r));
  if(l == r) return;
  
  ii x = query(1, 0, n-1, l, r);
  
  solve(l, x.ss-1);
  solve(x.ss+1, r);
}
  
 
int32_t main(){
  DESYNC;
  cin >> n;
  ii v[n];
  build(1, 0, n-1);
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    update(1, 0, n-1, i, i, x);
  }
  solve(0, n-1);
  int ans = 0;
  for(ii x : seg){
    ii qry = query(1, 0, n-1, x.ff, x.ss);
    ans += qry.ff;
    update(1, 0, n-1, x.ff, x.ss, -qry.ff);
  }
  cout << ans << endl;
}
 
