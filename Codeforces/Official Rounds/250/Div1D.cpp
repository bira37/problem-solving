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

int v[112345], st[4*112345], color[4*112345];

void build(int cur, int l, int r){
  if(l == r){
    st[cur] = v[l];
    color[cur] = v[l];
    return;
  }
  int m = (l+r)>>1;
  build(2*cur, l, m);
  build(2*cur+1, m+1, r);
  st[cur] = st[2*cur] + st[2*cur+1];
  color[cur] = max(color[2*cur], color[2*cur+1]);
}

void update(int cur, int l, int r, int a, int b, int x){
  if(b < l || r < a) return;
  if(color[cur] < x) return;
  if(l == r){
    st[cur] = st[cur]%x;
    color[cur] = color[cur]%x;
    return;
  }
  int m = (l+r)>>1;
  
  update(2*cur, l, m, a, b, x);
  update(2*cur+1, m+1, r, a, b, x);
  
  st[cur] = st[2*cur] + st[2*cur+1];
  color[cur] = max(color[2*cur], color[2*cur+1]);
}

void assign(int cur, int l, int r, int a, int x){
  if(l == r){
    st[cur] = x;
    color[cur] = x;
    return;
  }
  int m = (l+r)>>1;
  if(a <= m) assign(2*cur, l, m, a, x);
  else if(m < a) assign(2*cur + 1, m +1 ,r , a, x);
  
  st[cur] = st[2*cur] + st[2*cur+1];
  color[cur] = max(color[2*cur], color[2*cur+1]);
} 

int query(int cur, int l, int r, int a, int b){
  if(b < l || r < a) return 0;
  if(a <= l && r <= b) return st[cur];
  int m = (l+r)>>1;
  return query(2*cur, l, m, a, b) + query(2*cur +1, m+1, r, a, b);
}
  
int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  for(int i=1; i<=n; i++) cin >> v[i];
  build(1, 1, n);
  while(q--){
    int t;
    cin >> t;
    if(t == 2){
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x);
    }
    else if(t == 1){
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl;
    }
    else {
      int l,x;
      cin >> l >> x;
      assign(1, 1, n, l, x);
    }
  } 
}