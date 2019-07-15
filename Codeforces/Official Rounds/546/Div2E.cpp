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

int st[4*112345];
int lz[4*112345];
int a[112345];
int k[112345];
int p[112345];

void build(int cur, int l, int r){
  lz[cur] = -INF;
  if(l == r){
    st[cur] = a[l];
    return;
  }
  int m = (l+r)>>1;
  build(2*cur, l, m);
  build(2*cur+1, m+1, r);
  st[cur] = st[2*cur] + st[2*cur+1];
}

void propagate(int cur, int l, int r){
  if(lz[cur] == -INF) return;
  st[cur] = (r-l+1)*lz[cur] + p[r] - p[l-1];
  if(l != r){
    lz[2*cur] = lz[cur];
    lz[2*cur+1] = lz[cur];
  }
  lz[cur] = -INF;
}

void update(int cur, int l, int r, int a, int b, int x){
  propagate(cur, l, r);
  if(b < l || r < a) return;
  if(a <= l && r <= b){
    lz[cur] = x;
    propagate(cur, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(2*cur, l, m, a, b, x);
  update(2*cur+1, m+1, r, a, b, x);
  st[cur] = st[2*cur] + st[2*cur+1];
}

int query(int cur, int l, int r, int a, int b){
  propagate(cur, l, r);
  if(b < l || r < a) return 0;
  if(a <= l && r <= b) return st[cur];
  int m = (l+r)>>1;
  return query(2*cur, l, m, a, b) + query(2*cur+1, m+1, r, a, b);
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) cin >> a[i];
  build(1, 1, n);
  k[0] = 0;
  for(int i=1; i<=n-1; i++){
    cin >> k[i];
    k[i] += k[i-1];
  }
  p[0] = 0;
  for(int i=1; i<=n; i++) p[i] = p[i-1] + k[i-1];
  int q;
  cin >> q;
  while(q--){
    char op;
    cin >> op;
    if(op == 's'){
      int l,r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl;
    }
    else {
      int id, x;
      cin >> id >> x;
      int val = query(1, 1, n, id, id);
      int l = id, r = n;
      int ans = -1;
      while(l <= r){
        int m = (l+r)>>1;
        if(val + x + k[m-1] - k[id-1] > query(1, 1, n, m, m)){
          ans = m;
          l = m +1;
        }
        else r = m-1;
      }
      update(1, 1, n, id, ans, val + x - k[id-1]);
    }
  } 
}

