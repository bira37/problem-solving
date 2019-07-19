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
 
namespace DynamicSegmentTree{
 
  struct node {
	  node *left, *right;
	  int mx = 0;
	  int lazy = 0;
	  node() {
		  mx = 0;
		  lazy = 0;
		  left = NULL;
		  right = NULL;
	  }
  };
 
  struct Tree{
  
    node * root;
    
    Tree(){
      root = new node();
    }
    
    void combine(node *ans, node *left, node *right){
	    ans->mx = max(left->mx, right->mx);
    }
    
    void propagate(node * root, int l, int r){
      if(root->lazy == 0) return;
      //apply lazy on node
      root->mx += root->lazy;
      //propagate
      if(!root->left) root->left = new node();
	    if(!root->right) root->right = new node();
	    
	    if(l != r){
	      //propagate operation
	      root->left->lazy += root->lazy;
	      root->right->lazy += root->lazy;
	    }
	    
	    //reset lazy
	    root->lazy = 0;
	  } 
 
    void update(node *root, int l, int r, int a, int b, int val){
      propagate(root, l, r);
      
	    if(b < l || r < a) return;
	    if(a <= l && r <= b){
		    root->lazy+=val;
		    propagate(root, l, r);
		    return;
	    }
	    int m = (l+r) >> 1;
	    if(!root->left) root->left = new node();
	    if(!root->right) root->right = new node();
	    
	    update(root->left, l, m, a, b, val);
	    update(root->right, m+1, r, a ,b, val);
	    
	    combine(root, root->left, root->right);
    }
 
    node* query(node *root, int l, int r, int a, int b){
      propagate(root, l, r);
	    if(b < l || r < a) return new node();
	    
	    if(a <= l && r <= b){
		    return root;
	    }
	    
	    int m = (l+r) >> 1;
	    if(!root->left) root->left = new node();
	    if(!root->right) root->right = new node();
	    
	    node *left = query(root->left, l,m, a,b);
	    node *right = query(root->right, m+1, r, a, b);
	    node *ans = new node();
	    
	    combine(ans, left, right);
	    return ans;
    }
    
    int max_query(node * root, int l, int r, int a, int b, int q){
      propagate(root, l, r);
      
      if(b < l || r < a) return 0;
      if(l == r){
        if(root->mx == q) return l;
        else return 0;
      }
      
      int m = (l+r) >> 1;
	    if(!root->left) root->left = new node();
	    if(!root->right) root->right = new node();
	    propagate(root->left, l, m);
	    propagate(root->right, m+1, r);
      if(a <= l && r <= b){
        if(root->left->mx == q && root->right->mx == q) return -1;
        else if(root->left->mx == q) return max_query(root->left, l, m, a, b, q);
        else if(root->right->mx == q) return max_query(root->right, m+1, r, a, b, q);
        else return 0;
      }
      
      int lef = max_query(root->left, l, m, a, b, q);
      int rig = max_query(root->right, m+1, r, a, b, q);
      if(lef == -1 || rig == -1) return -1;
      else if(lef > 0 && rig > 0) return -1;
      else if(lef > 0) return lef;
      else if(rig > 0) return rig;
      else return 0;
    }
        
  };
  
}
 
struct _query{
  int l, r, val;
  _query() {}
  _query(int l, int r, int val) : l(l), r(r), val(val){}
};
 
struct Compresser{
  set<int> s;
  map<int,int> val;
  map<int,int> original;
  void add(int x){
    s.insert(x);
  }
  
  void compress(){
    int cnt = 1;
    for(int x : s){
      val[x] = cnt;
      original[cnt++] = x; 
    }
  }
  
  int get(int x){
    return val[x];
  }
  
  int real(int x){
    return original[x];
  }
 
};
 
 
int32_t main(){
  DESYNC;
  int h,q;
  cin >> h >> q;
  int nq = q;
  DynamicSegmentTree::Tree st;
  int ini = 1;
  int end = (1LL<<(h))-1;
  
  vector< _query > queries;
  Compresser compresser;
  compresser.add(ini);
  compresser.add(end);
  for(int nq = 0; nq < q; nq++){
    int hei, l, r, ans;
    cin >> hei >> l >> r >> ans;
    for(int i=hei; i<h; i++){
      l = 2*l;
      r = 2*r + 1;
    }
    if(ans){
      queries.pb(_query(l, r, 1));
      compresser.add(l); compresser.add(r);
    }
    else {
      if(ini != l){
        queries.pb(_query(ini, l-1, 1));
        compresser.add(ini); compresser.add(l-1);
      }
      if(r != end){
        queries.pb(_query(r+1, end, 1));
        compresser.add(r+1); compresser.add(end);
      }
    }
  }
  compresser.add((1LL<<(h-1)));
  compresser.compress();
    
  for(_query que : queries){
    st.update(st.root, compresser.get(ini), compresser.get(end), compresser.get(que.l), compresser.get(que.r), que.val);
  }
      
  int qry = st.max_query(st.root, compresser.get(ini), compresser.get(end), compresser.get((1LL<<(h-1))), compresser.get(end), q);
  if(qry == -1){
    cout << "Data not sufficient!" << endl;
  }
  else if(qry == 0){
    cout << "Game cheated!" << endl;
  }
  else cout << compresser.real(qry) << endl;   
}
 
