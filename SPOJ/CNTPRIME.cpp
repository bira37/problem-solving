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

namespace NT {
  
  const int MAX_N = 1123456;
  bitset<MAX_N> prime;
  vector<int> primes;
  vector<int> seg_primes;

  void Sieve(int n){
    prime.set();
    prime[0] = false;
    prime[1] = false;
    for(int p = 2; p*p <= n; p++){
      if(prime[p]){
        for(int i=p*p; i<=n; i+=p){
          prime[i] = false;
        }
      }
    }
    for(int i=2; i<=n; i++) if(prime[i]) primes.pb(i);
  }
}

int v[1123456];

int st[4*1123456];
int lz[4*1123456];

void build(int cur, int l, int r){
  lz[cur] = -1;
  if(l == r){
    st[cur] = NT::prime[v[l]];
    return;
  }
  int m = (l+r)>>1;
  
  build(2*cur, l, m);
  build(2*cur + 1, m+1, r);
  
  st[cur] = st[2*cur] + st[2*cur+1];
  
}

void propagate(int cur, int l, int r){
  if(lz[cur] == -1) return;
  
  st[cur] = (r-l+1)*lz[cur];
  
  if(l != r){
    lz[2*cur] = lz[cur];
    lz[2*cur+1] = lz[cur];
  }
  
  lz[cur] = -1;
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
  
  int lef = query(2*cur, l, m, a , b);
  int rig = query(2*cur+1, m+1, r, a, b);
  
  return lef + rig;
}

int32_t main(){
  DESYNC;
  NT::Sieve(1000000);
  int t;
  cin >> t;
  for(int test = 1; test <= t; test++){
    cout << "Case " << test << ":" << endl;
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> v[i];
    build(1, 0, n-1);
    
    while(q--){
      int op;
      cin >> op;
      if(op == 1){
        int l, r;
        cin >> l >> r;
        l--,r--;
        cout << query(1, 0, n-1, l, r) << endl;
      }
      else {
        int l,r,x;
        cin >> l >> r >> x;
        l--,r--;
        update(1, 0, n-1, l, r, NT::prime[x]);
      }
    }
  }   
}


