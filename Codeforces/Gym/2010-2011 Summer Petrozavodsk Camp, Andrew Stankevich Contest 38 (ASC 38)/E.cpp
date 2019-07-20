#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
struct node {
	node *left, *right;
	int val = 0;
	node() {
		val = 0;
		left = NULL;
		right = NULL;
	}
};
 
int ans = 0;
 
struct DynamicSegmentTree{
  node * root;
  
  DynamicSegmentTree(){
    root = new node();
  }
 
  void update(node *root, int l, int r, int a, int b){
	  if(l == a && r == b){
		  root->val++;
		  return;
	  }
	  int m = (l+r) >> 1;
	  if(!root->left) root->left = new node();
	  if(!root->right) root->right = new node();
	  
	  if(b <= m){
		  update(root->left, l, m, a, b);
	  }
	  else if(m < a){
		  update(root->right, m+1, r, a, b);
	  }
	  else {
	    update(root->left, l,m, a, m);
	    update(root->right, m+1, r, m+1, b);
	  }
  }
 
  void query(node *root, int l, int r, int idx){
    ans += root->val;
	  if(l == idx && r == idx){
		  return;
	  }
	  int m = (l+r) >> 1;
	  if(!root->left) root->left = new node();
	  if(!root->right) root->right = new node();
	  if(idx <= m) query(root->left, l, m, idx);
	  else query(root->right, m+1, r, idx);
  }
  
}dst;
 
int32_t main(){
  ifstream cin("environment.in");
  ofstream cout("environment.out");
	int q;
	cin >> q;
	int d = 0;
	while(q--){
	  int op;
	  cin >> op;
	  if(op == 1){
	    int l,r;
	    cin >> l >> r;
	    l += d;
	    r += d;
	    dst.update(dst.root, 0, (int)1e10, l, r);
	  }
	  else {
	    int x;
	    cin >> x;
	    ans = 0;
	    dst.query(dst.root, 0, (int)(1e10), x);
	    cout << ans << endl;
	    d = ans;
	  }
	}
}
 
 
