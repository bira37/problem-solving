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

int v[112345];

namespace SegmentTree{
  
  struct node{
	  int b[20][2];
	  int lazy = 0;
	  node() {
	    for(int i=0; i<20; i++) b[i][0] = b[i][1] = 0;
	    lazy = 0;
	  }
  };

  struct Tree{
    vector<node> st;
    Tree(){}
    
    Tree(int n){
      st.resize(4*n);
    }
  
    node combine(node a, node b){
	    node res;
	    res.lazy = 0;
	    for(int i=0; i<20;i++){
	      res.b[i][0] = a.b[i][0] + b.b[i][0];
	      res.b[i][1] = a.b[i][1] + b.b[i][1];
	    }
	    return res;
    }

    void propagate(int cur, int l , int r){
	    if(st[cur].lazy == 0) return;
	    
	    for(int i=0; i<20; i++){
	      if((1<<i) & st[cur].lazy){
	        swap(st[cur].b[i][0], st[cur].b[i][1]);
	      }
	    }
	     
	    if(l != r){
		    st[2*cur].lazy = st[2*cur].lazy^st[cur].lazy;
		    st[2*cur+1].lazy = st[2*cur+1].lazy^st[cur].lazy;
	    }
	    
	    st[cur].lazy = 0;
    }
    
    void build(int cur, int l, int r){
      if(l == r){
        for(int i=0; i<20; i++){
          if((1<<i) & v[l]) st[cur].b[i][1]++;
          else st[cur].b[i][0]++;
        }
        return;
      }
      
      int m = (l+r)>>1;
      build(2*cur, l, m);
      build(2*cur + 1, m+1, r);
      st[cur] = combine(st[2*cur], st[2*cur+1]);
      
    }

    void update(int cur, int l, int r, int a, int b, int val){
	    propagate(cur, l, r);
	    if(l == a && r == b){
		    st[cur].lazy ^= val;
		    return;
	    }
	
	    int m = (l+r)/2;
	
	    if(b <= m) update(2*cur, l, m, a, b, val);
	    else if(m < a) update(2*cur+1, m+1, r, a, b, val);
	    else {
		    update(2*cur, l, m, a, m, val);
		    update(2*cur+1, m+1, r, m+1, b, val);
	    }
	
	    propagate(cur, l , r);
	    propagate(2*cur, l, m);
	    propagate(2*cur+1, m+1, r);
	    st[cur] = combine(st[2*cur], st[2*cur+1]);
    }

    node query(int cur, int l, int r, int a, int b){
	    propagate(cur, l, r);
	    if(l == a && r == b) return st[cur];
	
	    int m = (l+r)/2;
	    if(b <= m) return query(2*cur, l, m, a, b);
	    else if(m < a) return query(2*cur+1, m+1, r, a, b);
	    else {
		    node left = query(2*cur, l, m, a, m);
		    node right = query(2*cur+1, m+1, r, m+1, b);
		    node ans = combine(left, right);
		    return ans;
	    }
    }
  };
  
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  SegmentTree::Tree st(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  st.build(1, 0, n-1);
  int q;
  cin >> q;
  while(q--){
    int id,l,r;
    cin >> id >> l >> r;
    l--,r--;
    if(id == 2){
      int x;
      cin >> x;
      st.update(1, 0, n-1, l, r, x);
    }
    else {
      SegmentTree::node qry = st.query(1, 0, n-1, l, r);
      int ans = 0;
      for(int i=0; i<20; i++){
        ans += (1<<i)*qry.b[i][1];
      }
      cout << ans << endl;
    }
  }
}

