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
 
namespace SegmentTree{
 
  //val type example
  struct val_type{
    ii val;
    val_type() {}
    val_type(ii val) : val(val){}
  };
  
  //node type example
  struct node{
    ii val = ii(0,0);
    ii lazy = ii(0,0);
    node(){}
    node(ii val, ii lazy) : val(val), lazy(lazy) {}
    node neutral(){ return node(ii(0,0), ii(0,0)); };
    bool no_update() { return lazy == ii(0,0); }
    void update_lazy(val_type val) {lazy = max(lazy, val.val);}
    void apply(int l, int r) { val = max(val, lazy); }
    void reset_lazy() { lazy = ii(0,0); }
    node propagate(node b) { b.lazy = max(b.lazy, lazy); return b; }
    node combine(node b) { node ans; ans.val = max(b.val, val); return ans; }
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
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n-1; i++){
    cin >> v[i];
    v[i]--;
  }
  v[n-1] = n-1;
  int dp[n];
  SegmentTree::Tree<SegmentTree::node, SegmentTree::val_type> st(n);
  for(int i=0; i<n; i++){
    st.update(1, 0, n-1, i, i, SegmentTree::val_type(ii(v[i], i)));
  }
  for(int i=0; i<n-1; i++) dp[i] = INF;
  dp[n-1] = 0;
  int sum = 0;
  for(int i=n-2; i>=0; i--){
    int x = st.query(1, 0, n-1, i+1, v[i]).val.ss;
    dp[i] = dp[x] - (v[i] - x) + n-i-1;
  }
  for(int i=0; i<n; i++) sum += dp[i];
  cout << sum << endl;
}
 
