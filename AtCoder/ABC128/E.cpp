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

struct node {
  node *left, *right;
  int val = INF;
  int lazy = INF;
  node() {
    //initialize attributes
    val = INF;
    lazy = INF;
    left = NULL;
    right = NULL;
  }
};
  
void combine(node *ans, node *left, node *right){
  //combine operation
  ans->val = min(left->val, right->val);
}

void propagate(node * root, int l, int r){
  //check if exists lazy
  if(root->lazy == INF) return;
  //apply lazy on node
  root->val = min(root->lazy, root->val);
  //propagate
  if(!root->left) root->left = new node();
  if(!root->right) root->right = new node();
  
  if(l != r){
    //propagate operation
    root->left->lazy = min(root->lazy,root->left->lazy);
    root->right->lazy = min(root->right->lazy, root->lazy);
  }
  
  //reset lazy
  root->lazy = INF;
} 

void update(node *root, int l, int r, int a, int b, int val){
  propagate(root, l, r);
  //cout << l << " " << r << " " << root->val <<endl;
  if(l == a && r == b){
    //do lazy operation
    root->lazy = min(root->lazy, val);
    propagate(root, l, r);
    return;
  }
  int m = (l+r) >> 1;
  if(!root->left) root->left = new node();
  if(!root->right) root->right = new node();
  if(b <= m) update(root->left, l, m, a, b, val);
  else if(m < a) update(root->right, m+1, r, a, b, val);
  else {
    update(root->left, l, m, a, m, val);
    update(root->right, m+1, r, m+1, b, val);
  }
  propagate(root, l, r);
  propagate(root->left, l, m);
  propagate(root->right, m+1, r);
  combine(root, root->left, root->right);
}

node* query(node *root, int l, int r, int x){
  propagate(root, l, r);
  if(l == r){
    return root;
  }
  int m = (l+r) >> 1;
  if(!root->left) root->left = new node();
  if(!root->right) root->right = new node();
  if(x <= m) return query(root->left, l, m, x);
  else return query(root->right, m+1, r, x);
}


int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  node * root = new node();
  for(int i=0; i<n; i++){
    int l,r,x;
    cin >> l >> r >> x;
    int ta = max(0LL, l-x), tb = max(0LL, r-x-1);
    //cout << "up " << ta << " " << tb << " " << x << endl;
    update(root, 0, 1000000000, ta, tb, x);
  }
  while(q--){
    int x;
    cin >> x;
    int ans = query(root, 0, 1000000000, x)->val;
    if(ans == INF) ans = -1;
    cout << ans << endl;
  }
}


