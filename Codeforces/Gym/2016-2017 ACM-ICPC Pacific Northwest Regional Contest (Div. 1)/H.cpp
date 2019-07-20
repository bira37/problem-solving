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
    int val;
    node() {
      val = 0;
      left = NULL;
      right = NULL;
    }
  };
    
  void combine(node *ans, node *left, node *right){
    if(left && right){
      if(left->val > right->val){
        ans->val = left->val;
      }
      else {
        ans->val = right->val;
      }
    }
    else if(left){
      ans->val = left->val;
    }
    else if(right){
      ans->val = right->val;
    }
    else {
      ans->val = INF;
    }
  }
 
  void update(node *root, int l, int r, int x, int val){
    if(l == r){
      if(root->val < val){
        root->val = val;
      }
      return;
    }
    int m = (l+r) >> 1;
    if(x <= m){
      if(!root->left) root->left = new node();
      update(root->left, l, m, x, val);
    }
    else {
      if(!root->right) root->right = new node();
      update(root->right, m+1, r, x, val);
    }
    combine(root, root->left, root->right);
  }
 
  int query(node *root, int l, int r, int a, int b){
    if(l == a && r == b){
      return root->val;
    }
    int m = (l+r) >> 1;
    if(b <= m) {
      if(root->left) return query(root->left, l, m, a, b);
      else return 0;
    }
    else if(m < a){
      if(root->right) return query(root->right, m+1, r, a, b);
      else return 0;
    }
    int left = 0; 
    int right = 0;
    if(root->left) left = query(root->left, l,m,a,m);
    if(root->right) right = query(root->right, m+1, r, m+1, b);
    return max(left, right);
  }
  
}
 
int L = 0, R = (int)1e18;
DynamicSegmentTree::node* root = new DynamicSegmentTree::node();
 
int32_t main(){
  DESYNC;
  int n, k;
  cin >> n >> k;
  vector< ii > v(k);
  for(int i=0; i<k; i++){
    cin >> v[i].ff >> v[i].ss;
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for(int i=0; i<k; i++){
    int qry = DynamicSegmentTree::query(root, L, R, L, v[i].ff-1);
    ans = max(ans, qry + (v[i].ss - v[i].ff+1));
    DynamicSegmentTree::update(root, L, R, v[i].ss, qry + (v[i].ss - v[i].ff+1));
  }
  cout << n - ans << endl; 
}
 
