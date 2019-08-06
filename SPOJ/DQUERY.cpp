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

//Range Sum Persistent Segment Tree with Point Update
namespace PersistentSegmentTree {

  struct Node{
    Node * left, *right;
    int x;
    Node (){
      left = nullptr;
      right = nullptr;
      x = 0;
    }
    
    Node(Node * n){
      left = n->left;
      right = n->right;
      x = n->x;
    }
  };
  
  Node * update(Node * cur, int l, int r, int x, int val){
    assert(cur != nullptr);
    Node * new_cur = new Node(cur);
    if(l == r){
      new_cur->x += val;
      return new_cur;
    }
    
    int m = (l+r)>>1;
    if(x <= m){
      if(!new_cur->left) new_cur->left = new Node();
      new_cur->left = update(new_cur->left, l, m, x, val);
    }
    else {
      if(!new_cur->right) new_cur->right = new Node();
      new_cur->right = update(new_cur->right, m+1, r, x, val);
    }
    new_cur->x = (new_cur->left ? new_cur->left->x : 0) + (new_cur->right ? new_cur->right->x : 0);
    return new_cur;
  }
    
  int query(Node * cur, int l, int r, int a, int b){
    assert(cur != nullptr);
    if(r < a || b < l) return 0;
    if(a <= l and r <= b) return cur->x;
    int m = (l+r)>>1;
    int ansl = 0, ansr = 0;
    if(cur->left) ansl = query(cur->left, l, m, a ,b);
    if(cur->right) ansr = query(cur->right, m+1, r, a, b);
    return ansl + ansr;
  }
  
};

int lst[1123456];

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  memset(lst, -1, sizeof lst);
  vector< PersistentSegmentTree::Node* > persistent;
  persistent.pb(new PersistentSegmentTree::Node());
  for(int i=1; i<=n; i++){
    int x;
    cin >> x;
    PersistentSegmentTree::Node * cur = persistent.back();
    if(lst[x] != -1) cur = (PersistentSegmentTree::update(cur, 1, n, lst[x], -1));
    lst[x] = i;
    cur = (PersistentSegmentTree::update(cur, 1, n, lst[x], 1));
    persistent.pb(cur);
  }
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    cout << PersistentSegmentTree::query(persistent[r], 1, n, l, r) << endl;
  }
}


