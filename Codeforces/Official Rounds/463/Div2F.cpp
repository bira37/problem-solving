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
#define INF (int)1e15
#define ROOT 1

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

struct Lichao{
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
    bool operator<(const line & l) const{
    	return a < l.a || (a == l.a && b < l.b);
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
   
  node * root;
  
  Lichao(){
    root = new node();
  }
  Lichao(int sz){
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

int a[112345], b[112345];
vector<int> adj[112345];
int subsz[112345];
int heavy[112345];
int dp[112345];

void preprocess(int u, int p){
	subsz[u] = 1;
	heavy[u] = -1;
	for(int v : adj[u]){
		if(v == p) continue;
		preprocess(v, u);
		subsz[u] += subsz[v];
		if(heavy[u] == -1 || subsz[heavy[u]] < subsz[v]){
			heavy[u] = v;
		}
	}
}

void dfs(int u, int p, Lichao & cur, set<Lichao::line> & nodes){
	bool leaf = true;
	if(heavy[u] != -1){
		dfs(heavy[u], u, cur, nodes);
		leaf = false;
	}
	
	for(int v : adj[u]){
		if(v == p || v == heavy[u]) continue;
		Lichao subcur;
		set<Lichao::line> subnodes;
		dfs(v, u, subcur, subnodes);
		for(Lichao::line l : subnodes){
			nodes.insert(l);
			cur.add(cur.root, -100000, 100000, l);
		}
	}
	
	if(!leaf) dp[u] = cur.query(cur.root, -100000, 100000, a[u]);
	else dp[u] = 0;
	cur.add(cur.root, -100000, 100000, Lichao::line(b[u], dp[u]));
	nodes.insert(Lichao::line(b[u], dp[u]));
}

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	preprocess(1, -1);
	Lichao cur;
	set<Lichao::line> nodes;
	dfs(1, -1, cur, nodes);
	for(int i=1; i<=n; i++){
		if(i > 1) cout << " ";
		cout << dp[i];
	}
	cout << endl;
}
	