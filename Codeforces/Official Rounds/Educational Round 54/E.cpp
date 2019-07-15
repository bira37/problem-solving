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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

struct BIT {
  
  vector<int> bit;

  BIT() {}
  
  int n;
   
  BIT(int n) {
    this->n = n;
    bit.resize(n+1);
  }

  void update(int idx, int val){
    for(int i = idx; i <= n; i += i&-i){
      bit[i]+=val;
    }
  }

  int prefix_query(int idx){
    int ans = 0;
    for(int i=idx; i>0; i -= i&-i){
      ans += bit[i];
    }
    return ans;
  }
  
  int query(int l, int r){
    return prefix_query(r) - prefix_query(l-1);
  }
  
  //int bit 0-1 it finds the index of k-th element active
  int kth(int k) {
    int cur = 0;
    int acc = 0;
    for(int i = 19; i >= 0; i--) {
      if(cur + (1<<i) > n) continue;
      if(acc + bit[cur + (1<<i)] < k) {
        cur += (1<<i);
        acc += bit[cur];
      }
    }
    return ++cur;
  }
  
};

BIT bit(412345);
int n;

int ans[312345];
vector<int> g[312345];
vector< ii > ups[312345];

void go(int u, int p, int offset){
  for(ii q : ups[u]){
    bit.update(min(n+10, offset + q.ff), q.ss);
  }
  ans[u] = bit.query(offset, 412345);
  for(int v : g[u]){
    if(v == p) continue;
    go(v, u, offset+1);
  }
  for(ii q : ups[u]){
    bit.update(min(n+10, offset + q.ff), -q.ss);
  }
}

int32_t main(){
  DESYNC;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >>v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int q;
  cin>> q;
  while(q--){
    int u, d, x;
    cin >> u >> d >> x;
    ups[u].pb(ii(d,x));
  }
  go(1, -1, 1);  
  for(int i=1; i<=n; i++) cout << ans[i] << " ";
  cout << endl;
}

