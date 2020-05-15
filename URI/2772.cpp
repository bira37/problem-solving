#include <bits/stdc++.h>

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

using namespace std;

inline int mod(int n){ return (n%1000000007); }

bitset<112345> deads;
struct node {
  //node info
  int max_val, lazy_sum, id_max;
  bool lazy_reset;
  node() {}
};

struct SegmentTree {
  vector<node> st;
  
  void init(int n){
    st.resize(4*n);
  }
  
  node combine(node a, node b){
    node ans;
    ans.max_val = max(a.max_val, b.max_val);
    if(ans.max_val == a.max_val) ans.id_max = a.id_max;
    else ans.id_max = b.id_max;
    ans.lazy_reset = false;
    ans.lazy_sum = 0;
    return ans;
  }
  
  void build(int cur, int l, int r){
    if(l == r){
      st[cur].max_val = 0;
      st[cur].lazy_sum = 0;
      st[cur].lazy_reset = false;
      st[cur].id_max = l;
      return;
    }
    
    int m = (l+r)>>1;
    build(2*cur, l, m);
    build(2*cur+1, m+1, r);
    st[cur] = combine(st[2*cur], st[2*cur+1]);
  }
  
  void propagate(int cur, int l, int r){
    if(st[cur].lazy_reset){
      st[cur].max_val = 0;

      if(l != r){
        st[2*cur].lazy_sum = 0;
        st[2*cur+1].lazy_sum = 0;
        st[2*cur].lazy_reset = true;
        st[2*cur+1].lazy_reset = true;
      }
      st[cur].lazy_reset = false;
    }
    if(st[cur].lazy_sum > 0){
      st[cur].max_val += st[cur].lazy_sum;
      
      if(l != r){
        st[2*cur].lazy_sum += st[cur].lazy_sum;
        st[2*cur+1].lazy_sum += st[cur].lazy_sum;
      }
      st[cur].lazy_sum = 0;
    }
  }
  
  void point_update(int cur, int l, int r, int idx, int val){
    propagate(cur, l, r);
    if(l == r){
      st[cur].max_val = val;
      return;
    }
    
    int m = (l+r)>>1;
    if(idx <= m) point_update(2*cur, l, m, idx, val);
    else point_update(2*cur+1, m+1, r, idx, val);
    propagate(2*cur, l, m);
    propagate(2*cur+1, m+1, r);
    st[cur] = combine(st[2*cur], st[2*cur+1]);
  }
  
  node point_query(int cur, int l, int r, int idx){
    propagate(cur, l, r);
    if(l == r){
      return st[cur];
    }
    
    int m = (l+r)>>1;
    if(idx <= m) return point_query(2*cur, l, m, idx);
    else return point_query(2*cur+1, m+1, r, idx);
  }
  
  node range_query(int cur, int l, int r, int a, int b){
    propagate(cur, l, r);
    if(l == a && r == b) return st[cur];
    
    int m = (l+r)>>1;
    if(b <= m) return range_query(2*cur, l, m, a, b);
    else if(m < a) return range_query(2*cur+1, m+1, r, a, b);
    else {
      node left = range_query(2*cur, l, m, a, m);
      node right = range_query(2*cur+1, m+1, r, m+1, b);
      return combine(left, right);
    }
  }
  
  void range_update_reset(int cur, int l, int r, int a, int b){
    if(st[cur].max_val < 0) return;
    propagate(cur, l, r);
    if(l == a && r == b){
      st[cur].lazy_reset = true;
      return;
    }
    
    int m = (l+r)>>1;
    if(b <= m) range_update_reset(2*cur, l, m, a, b);
    else if(m < a) range_update_reset(2*cur+1, m+1, r, a, b);
    else {
      range_update_reset(2*cur, l, m, a, m);
      range_update_reset(2*cur+1, m+1, r, m+1, b);
    }
    propagate(2*cur, l, m);
    propagate(2*cur+1, m+1, r);
    st[cur] = combine(st[2*cur], st[2*cur+1]);
  }
  
  void range_update_sum(int cur, int l, int r, int a, int b){
    if(st[cur].max_val < 0) return;
    propagate(cur, l, r);
    if(l == a && r == b){
      st[cur].lazy_sum++;
      return;
    }
    
    int m = (l+r)>>1;
    if(b <= m) range_update_sum(2*cur, l, m, a, b);
    else if(m < a) range_update_sum(2*cur+1, m+1, r, a, b);
    else {
      range_update_sum(2*cur, l, m, a, m);
      range_update_sum(2*cur+1, m+1, r, m+1, b);
    }
    propagate(2*cur, l, m);
    propagate(2*cur+1, m+1, r);
    st[cur] = combine(st[2*cur], st[2*cur+1]);
  }
} st;   

int32_t main(){
	DESYNC;
	int n, k, t;
	while(scanf("%d%d%d", &n, &k, &t) == 3){
	  st.init(n);
	  st.build(1, 0, n-1);
	  deads.reset();
	  while(k--){
	    int l, r;
	    scanf("%d%d", &l, &r);
	    l--, r--;
	    if(l-1 >= 0){
	      st.range_update_sum(ROOT, 0, n-1, 0, l-1);
	    }
	    if(r+1 <= n-1){
	      st.range_update_sum(ROOT, 0, n-1, r+1, n-1);
	    }
	    st.range_update_reset(ROOT, 0, n-1, l, r);
	    
	    node ans;
	    while(ans = st.range_query(ROOT, 0, n-1, 0, n-1), ans.max_val >= t){
	      deads[ans.id_max+1] = true;
	      st.point_update(ROOT, 0, n-1, ans.id_max, -INF);
	    }
	  }
	  vector<int> ans;
	  for(int i=1; i<=n; i++) if(!deads[i]) ans.pb(i);
	  printf("%d", (int)ans.size());
	  for(int i=0; i<ans.size(); i++){
	    printf(" %d", ans[i]);
	  }
	  putchar('\n');
	}
}
