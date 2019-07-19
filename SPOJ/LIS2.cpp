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
    int mx = (int)1e9+1;
    node() {
      mx = (int)1e9+1;
      left = NULL;
      right = NULL;
    }
  };
    
  void combine(node *ans, node *left, node *right){
    if(left && right) ans->mx = min(left->mx, right->mx);
    else if(left) ans->mx = left->mx;
    else if(right) ans->mx = right->mx;
    else ans->mx = (int)1e9+1;
  }

  void update(node *root, int l, int r, int idx, int val){
    if(l == r){
      root->mx = min(root->mx, val);
      return;
    }
    int m = (l+r) >> 1;
    if(idx <= m){
      if(!root->left) root->left = new node();
      update(root->left, l, m, idx, val);
    }
    else{
      if(!root->right) root->right = new node();
      update(root->right, m+1, r, idx, val);
    }
    combine(root, root->left, root->right);
  }

  int query(node *root, int l, int r, int a, int b){
    if(l == a && r == b){
      return root->mx;
    }
    int m = (l+r) >> 1;
    if(b <= m){
      if(!root->left) return (int)1e9+1;
      else return query(root->left, l, m, a, b);
    }
    else if(m < a){
      if(!root->right) return (int)1e9+1;
      else return query(root->right, m+1, r, a, b);
    }
    int left = (int)1e9+1;
    int right = (int)1e9+1;
    if(root->left) left = query(root->left, l,m,a,m);
    if(root->right) right = query(root->right, m+1, r, m+1, b);
    return min(left, right);
  }
  
}

DynamicSegmentTree::node * lis[112345];
int L = (int)-2e9, R = (int)2e9;

bool check(int id, int x, int y){
  int val = DynamicSegmentTree::query(lis[id], L, R, L, x-1);
  return val < y;
} 

int32_t main(){
  int n;
  scanf("%d",  &n);
  vector< ii > v(n);
  set<int> sx;
  vector<int> aux;
  for(int i=0; i<n; i++){
    scanf("%d%d", &v[i].ff, &v[i].ss);
    sx.insert(v[i].ff);
  }
  for(int x : sx) aux.pb(x);
  L = -1, R = sx.size();
  for(int i=0; i<n; i++){
    v[i].ff = lower_bound(aux.begin(), aux.end(), v[i].ff) - aux.begin();
  }
  for(int i=0; i<=n; i++){
    lis[i] = new DynamicSegmentTree::node();
  }
  DynamicSegmentTree::update(lis[0], L, R, L, -(int)1e9-1);
  int sz = 0;
  for(ii par : v){
    int x = par.ff, y = par.ss;
    int l = 0, r = n-1;
    int ans = 0;
    while(l <= r){
      int m = (l+r)>>1;
      if(check(m, x, y)){
        ans = m;
        l = m+1;
      }
      else r = m-1;
    }
    sz = max(sz, ans+1);
    DynamicSegmentTree::update(lis[ans+1], L, R, x, y);
  }
  printf("%d\n", sz);  
}


