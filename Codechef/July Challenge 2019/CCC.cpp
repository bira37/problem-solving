#include <bits/stdc++.h>

#define int long long
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

bool check(int z, int ans){
  if(z <= 0){
    cout << ans << endl;
    return true;
  }
  return false;
}

namespace Lichao{
  //min lichao tree
  
  struct line {
    int a, b;
    line() {
      a = 0;
      b = INF;
    }
    line(int a, int b) : a(a), b(b) {}
    int eval(int x){
      return a*x + b;
    }
  }; 
  
  struct node {
    node * left, * right;
    line ln;
    node(){
      left = NULL;
      right = NULL;
    }
  };
  
  struct Tree {
  
    node * root;
    
    Tree() {
      root = new node();
    }
  
    void add(node * root, int l, int r, line ln){
      if(!root->left) root->left = new node();
      if(!root->right) root->right = new node();
      int m = (l+r)>>1;
      bool left = ln.eval(l) < (root->ln).eval(l);
      bool mid = ln.eval(m) < (root->ln).eval(m);
      
      if(mid){
        swap(root->ln, ln);
      }
      
      if(l == r) return;
      else if(left != mid) add(root->left, l, m, ln);
      else add(root->right, m+1, r, ln);
    }
    
    int query(node * root, int l, int r, int x){
      if(!root->left) root->left = new node();
      if(!root->right) root->right = new node();
      int m = (l+r)>>1;
      if(l == r) return (root->ln).eval(x);
      else if(x < m) return min((root->ln).eval(x), query(root->left, l, m, x));
      else return min((root->ln).eval(x), query(root->right, m+1, r, x));
    }
  
  };
  
}

void solve(){
  
  int n, k;
  cin >> n >> k;
  vector<int> v(n+1);
  v[0] = 1e7;
  int p[n+1];
  for(int i=1; i<=n; i++) cin >> v[i];
  sort(v.begin()+1, v.end());
  p[0] = 0;
  for(int i=1; i<=n; i++) p[i] = p[i-1] + v[i];
  int dp[n+1][k+1];
  for(int i=0; i<=n; i++){
    for(int j=0; j<=k; j++) dp[i][j] = 1e15;
  }
  for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int j=1; j<=k; j++){
    Lichao::Tree lichao;
    lichao.add(lichao.root, 0, (int)1e3+10, Lichao::line(v[0], -0*v[0] + dp[0][j]));
    for(int i=1; i<=n; i++){
      if(j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + v[i]); 
      dp[i][j] = min(dp[i][j], lichao.query(lichao.root, 0, (int)1e3+10, i));
      lichao.add(lichao.root, 0, (int)1e3+10, Lichao::line(v[i], -i*v[i] + dp[i][j]));
      //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }
  cout << dp[n][k] << endl;
}

int32_t main(){
  int t;
  cin >> t;
  while(t--) solve();

}


