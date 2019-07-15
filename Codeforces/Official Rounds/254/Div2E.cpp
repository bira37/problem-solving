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

int st[4*112345], lz[4*112345], color[4*112345], lzc[4*112345];

void propagate(int cur, int l, int r){
  if(lz[cur] == 0) return;
  
  st[cur] += (r-l+1)*lz[cur];
  color[cur] = lzc[cur];
  
  if(l != r){
    lzc[2*cur] = lzc[2*cur+1] = lzc[cur];
    lz[2*cur] += lz[cur];
    lz[2*cur+1] += lz[cur];
  }
  
  lzc[cur] = lz[cur] = 0;
}

void build(int cur, int l, int r){
  lz[cur] = 0;
  lzc[cur] = 0;
  if(l == r){
    st[cur] = 0;
    color[cur] = l;
    return;
  }
  int m = (l+r)>>1;
  build(2*cur, l, m);
  build(2*cur+1, m+1, r);
  if(color[2*cur] != color[2*cur+1]) color[cur] = -1;
  else color[cur] = color[2*cur];
}

void update(int cur, int l, int r, int a, int b, int x){
  propagate(cur, l, r);
  if(b < l || r < a) return;
  if(a <= l && r <= b && color[cur] != -1){
    int val = abs(color[cur] - x);
    lz[cur] += val;
    lzc[cur] = x;
    propagate(cur, l, r);
    return;
  }
  int m = (l+r)>>1;
  
  update(2*cur, l, m, a, b, x);
  update(2*cur+1, m+1, r, a, b, x);
  
  st[cur] = st[2*cur] + st[2*cur+1];
  if(color[2*cur] != color[2*cur+1]) color[cur] = -1;
  else color[cur] = color[2*cur];
}

int query(int cur, int l, int r, int a, int b){
  propagate(cur, l, r);
  if(b < l || r < a) return 0;
  if(a <= l && r <= b) return st[cur];
  int m = (l+r)>>1;
  return query(2*cur, l, m, a, b) + query(2*cur +1, m+1, r, a, b);
}
  
int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  build(1, 1, n);
  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl;
    }
  } 
}

