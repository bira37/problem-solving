#include <bits/stdc++.h>
 
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
  
  struct node{
	  int s;
	  int lazy;
	  int lazy_m;
	  node() {
	    s = 0;
	    lazy = 0;
	    lazy_m = 1;
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
	    res.s = a.s + b.s;
	    return res;
    }
    
    void push(int cur, int l, int r, int child) {
      st[child].lazy *= st[cur].lazy_m;
      st[child].lazy_m *= st[cur].lazy_m;
      st[child].lazy += st[cur].lazy;
    }
 
    void propagate(int cur, int l , int r){
	    if(st[cur].lazy == 0 && st[cur].lazy_m == 1) return;
	    st[cur].s = (r-l+1)*st[cur].lazy + st[cur].s * st[cur].lazy_m;
	    if(l != r){
	      push(cur, l, r, 2*cur);
	      push(cur, l, r, 2*cur+1);
	    }
	    
	    st[cur].lazy = 0;
	    st[cur].lazy_m = 1;
    }
 
    void update(int cur, int l, int r, int a, int b, long long val){
	    propagate(cur, l, r);
	    if(b < l || r < a) return;
	    if(a <= l && r <= b){
		    st[cur].lazy += val;
		    propagate(cur, l, r);
		    return;
	    }
	
	    int m = (l+r)/2;
 
		  update(2*cur, l, m, a, b, val);
		  update(2*cur+1, m+1, r, a, b, val);
	
	    st[cur] = combine(st[2*cur], st[2*cur+1]);
    }
    
    void zera(int cur, int l, int r, int a, int b){
	    propagate(cur, l, r);
	    if(b < l || r < a) return;
	    if(a <= l && r <= b){
		    st[cur].lazy_m = 0;
		    propagate(cur, l, r);
		    return;
	    }
	
	    int m = (l+r)/2;
	   
	    zera(2*cur, l, m, a, b);
	    zera(2*cur+1, m+1, r, a, b);
 
	    st[cur] = combine(st[2*cur], st[2*cur+1]);
    }
 
    node query(int cur, int l, int r, int a, int b){
	    propagate(cur, l, r);
	    if(b < l || r < a) return node();
	    if(a <= l && r <= b) return st[cur];
	
	    int m = (l+r)/2;
	    return combine(query(2*cur, l, m, a, b),
	                  query(2*cur+1, m+1, r, a, b));
    }
  };
  
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int q;
  cin >> q;
  string s;
  cin >> s;
  SegmentTree::Tree st[26];
  for(int i=0; i<26; i++) st[i] = SegmentTree::Tree(n);
  for(int i=0; i<n; i++){
    st[s[i]-'a'].update(1, 0, n-1, i, i, 1);
  }
  
  while(q--){
    int l, r, x;
    cin >> l >> r >> x;
    l--,r--;
    int cnt[26];
    for(int i=0; i<26; i++){
      cnt[i] = st[i].query(1, 0, n-1, l , r).s;
      st[i].zera(1, 0, n-1, l, r);
    }
    
    int start = l;
    
    if(x == 1){
      for(int i=0; i<26; i++){
        if(cnt[i] == 0) continue;
        st[i].update(1, 0, n-1, start, start + cnt[i]-1, 1);
        start += cnt[i];
      }
    }
    else {
      for(int i=25; i>=0; i--){
        if(cnt[i] == 0) continue;
        st[i].update(1, 0, n-1, start, start + cnt[i]-1, 1);
        start += cnt[i];
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<26; j++){
      if(st[j].query(1, 0, n-1, i, i).s == 1){
        cout << char('a' + j);
        break;
      }
    }
  }
  cout << endl;               
}
 
