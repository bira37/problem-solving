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

namespace SegmentTree{

  //val type example
  struct val_type{
    int val;
    val_type() {}
    val_type(int val) : val(val){}
  };
  
  //node type example
  struct node{
    int val = 0;
    int lazy = 0;
    node(){}
    node(int val, int lazy) : val(val), lazy(lazy) {}
    static node neutral(){ return node(0,0); };
    bool no_update() { return lazy == 0; }
    void update_lazy(val_type val) {lazy += val.val;}
    void apply(int l, int r) { val += (r-l+1)*lazy; }
    void reset_lazy() { lazy = 0; }
    node propagate(node b) { b.lazy += lazy; return b; }
    node combine(node b) { node ans; ans.val = b.val + val; return ans; }
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
      if(b < l || r < a) return node::neutral();
      if(a <= l && r <= b) return st[cur];
      int m = (l+r)/2;
      node_t left = query(2*cur, l, m, a, b);
      node_t right = query(2*cur+1, m+1, r, a, b);
      node_t ans = left.combine(right);
      return ans;
    }
  };
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n, q;
    cin >> n >> q;
    SegmentTree::Tree<SegmentTree::node, SegmentTree::val_type> st(n);
    while(q--){
      int op;
      cin >> op;
      if(op == 0){
        int l,r,v;
        cin >> l >> r >> v;
        l--,r--;
        st.update(1, 0, n-1, l, r, SegmentTree::val_type(v));
      }
      else {
        int l,r;
        cin >> l >> r;
        l--,r--;
        cout << st.query(1, 0, n-1, l, r).val << endl;
      }
    }
  }  
    
}


