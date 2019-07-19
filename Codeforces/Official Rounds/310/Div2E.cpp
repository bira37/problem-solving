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
 
namespace DynamicSegmentTree{
 
  struct node {
	  node *left, *right;
	  int mx;
	  node() {
	    mx = 0;
		  left = NULL;
		  right = NULL;
	  }
  };
 
  struct Tree{
  
    node * root;
    
    Tree(){
      root = new node();
    } 
 
    void update(node *root, int l, int r, int a, int b, int val){
      //cout << "at " << l << " " << r << endl;
	    if(l == a && r == b){
		    root->mx = max(root->mx, val);
		    return;
	    }
	    int m = (l+r) >> 1;
	    if(!root->left) root->left = new node();
	    if(!root->right) root->right = new node();
	    if(b <= m){
	      update(root->left, l, m, a, b, val);
	    }
	    else if(m < a){
	      update(root->right, m+1, r, a, b, val);
	    }
	    else {
	      update(root->left, l, m, a, m, val);
	      update(root->right, m+1, r, m+1, b, val);
	    }
    }
 
    int query(node *root, int l, int r, int y){  
      //cout << "query " << l << " " << r << endl;
	    if(l == r){
		    return root->mx;
	    }
	    int m = (l+r) >> 1;
	    if(!root->left) root->left = new node();
	    if(!root->right) root->right = new node();
	    if(y <= m){
	      return max(root->mx, query(root->left, l, m, y));
	    }
	    else {
	      return max(root->mx, query(root->right, m+1, r, y));
	    }
    }
  };
  
}
 
int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  DynamicSegmentTree::Tree v, h;
  while(q--){
    int x,y;
    cin >> y >> x;
    char c;
    cin >> c;
    if(c == 'U'){
      auto p = h.query(h.root, 1, 1000000000, y);
      int mx = 1;
      //cout << p << endl;
      mx = max(mx, p+1);
      cout << x - mx +1 << endl;
      if(x - mx + 1 == 0) continue;
      //cout << mx << " " << x << endl;
      h.update(h.root, 1, 1000000000, y,y, x);
      v.update(v.root, 1, 1000000000, mx, x, y);
    }
    else {
      auto p = v.query(v.root, 1, 1000000000, x);
      int my = 1;
      my = max(my, p+1);
      //cout << p << endl;
      cout << y - my + 1 << endl;
      if(y - my + 1 == 0) continue;
      //cout << my << " " << y << endl;
      v.update(v.root, 1, 1000000000, x, x, y);
      h.update(h.root, 1, 1000000000, my, y, x);
    }
  }         
}
 
