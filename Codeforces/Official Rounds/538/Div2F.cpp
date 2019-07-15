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

int exp(int a, int k){
  if(k == 0) return 1;
  if(k == 1) return a;
  int aux = exp(a, k/2);
  aux = mod(aux*aux, M);
  if(k%2) aux = mod(aux*a, M);
  return aux;
}

namespace SegmentTree{

  //val type example
  struct val_type{
    int val;
    val_type() {}
    val_type(int val) : val(val){}
  };
  
  //node type example
  struct node1{
    int val = 1;
    int lazy = 1;
    node1(){}
    node1(int val, int lazy) : val(val), lazy(lazy) {}
    node1 neutral(){ return node1(1,1); };
    bool no_update() { return lazy == 1; }
    void update_lazy(val_type val) {lazy = mod(lazy*val.val, M);}
    void apply(int l, int r) { val = mod(val*exp(lazy, r-l+1), M); }
    void reset_lazy() { lazy = 1; }
    node1 propagate(node1 b) { b.lazy = mod(b.lazy*lazy, M); return b; }
    node1 combine(node1 b) { node1 ans; ans.val = mod(b.val * val, M); return ans; }
  };
  
  //node type example
  struct node2{
    int val = 0;
    int lazy = 0;
    node2(){}
    node2(int val, int lazy) : val(val), lazy(lazy) {}
    node2 neutral(){ return node2(0,0); };
    bool no_update() { return lazy == 0; }
    void update_lazy(val_type val) {lazy |= val.val;}
    void apply(int l, int r) { val |= lazy; }
    void reset_lazy() { lazy = 0; }
    node2 propagate(node2 b) { b.lazy |= lazy; return b; }
    node2 combine(node2 b) { node2 ans; ans.val = b.val | val; return ans; }
  };
  
  template<class node_t, class update_t>
  class Tree{
  public:
    vector<node_t> st;
    Tree(){}
    Tree(int n){
      st.resize(4*n);
    } 
    void propagate(int cur, int l , int r){
      if(st[cur].no_update()) return;
      st[cur].apply(l, r);
      if(l != r){
        st[2*cur] = st[cur].propagate(st[2*cur]);
        st[2*cur+1] = st[cur].propagate(st[2*cur+1]);
      }
      st[cur].reset_lazy();
    }
    void update(int cur, int l, int r, int a, int b, update_t val){
      propagate(cur, l, r);
      if(b < l || r < a) return;
      if(a <= l && r <= b){
        st[cur].update_lazy(val);
        propagate(cur, l, r);
        return;
      }
      int m = (l+r)/2;
      update(2*cur, l, m, a, b, val);
      update(2*cur+1, m+1, r, a, b, val);
      st[cur] = st[2*cur].combine(st[2*cur+1]);
    }
    node_t query(int cur, int l, int r, int a, int b){
      propagate(cur, l, r);
      if(b < l || r < a) return st[cur].neutral();
      if(a <= l && r <= b) return st[cur];
      int m = (l+r)/2;
      node_t left = query(2*cur, l, m, a, b);
      node_t right = query(2*cur+1, m+1, r, a, b);
      node_t ans = left.combine(right);
      return ans;
    }
  };
}

vector<int> primes;
int inv[300];

bool isPrime(int x){
  bool ok = true;
  for(int i = 2; i<=sqrt(x); i++){
    if(x%i == 0) ok = false;
  }
  return ok;
}

int32_t main(){
  DESYNC;
  inv[1] = 1;
  for(int i=2; i<300; i++){
    if(isPrime(i)) primes.pb(i);
    inv[i] = exp(i, M-2);
  }
  int n,q;
  cin >> n >> q;
  SegmentTree::Tree<SegmentTree::node1, SegmentTree::val_type> mul_st(n);
  SegmentTree::Tree<SegmentTree::node2, SegmentTree::val_type> or_st(n);
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    mul_st.update(1, 0, n-1, i, i, SegmentTree::val_type(x));
    int msk = 0;
    for(int j =0; j<primes.size(); j++){
      if(x%primes[j] == 0) msk |= (1LL<<j);
    }
    or_st.update(1, 0, n-1, i, i, SegmentTree::val_type(msk));
  }
  while(q--){
    string op;
    cin >> op;
    if(op == "MULTIPLY"){
      int l, r, x;
      cin >> l >> r >> x;
      l--,r--;
      mul_st.update(1, 0, n-1, l, r, SegmentTree::val_type(x));
      int msk = 0;
      for(int j =0; j<primes.size(); j++){
        if(x%primes[j] == 0) msk |= (1LL<<j);
      }
      or_st.update(1, 0, n-1, l, r, SegmentTree::val_type(msk));
    }
    else {
      int l,r;
      cin >> l >> r;
      l--, r--;
      int ans = mul_st.query(1, 0, n-1, l, r).val;
      int msk = or_st.query(1, 0, n-1, l, r).val;
     // cout << ans << " " << msk << endl;
      for(int i=0; i<primes.size(); i++){
        if((1LL<<i) & msk){
          ans = mod(ans*mod(1 - inv[primes[i]], M), M);
        }
      }
      cout << ans << endl;
    }
  }
}

