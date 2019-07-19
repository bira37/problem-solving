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

using namespace std;

inline int mod(int n){ return (n%1000000007); }

vector<int> adj[112345];
int val[112345];
int cnt[112345];
int v[112345];
bitset<112345> vis;
int n,q;

struct LCA {
  
  int tempo;
  vector<int> st, ed, dad, anc[20];
  vector<bool> vis;
  
  void init(int n){
    tempo = 0;
    st.resize(n+1);
    ed.resize(n+1);
    dad.resize(n+1);
    for(int i=0; i<20; i++) anc[i].resize(n+1);
    vis.resize(n+1);
    for(int i=0; i<=n; i++) vis[i] = false;
  }

  void dfs(int u){
	  vis[u] = true;
	  st[u] = tempo++;
	  for(int i=0; i<adj[u].size(); i++){
		  int v = adj[u][i];
		  if(!vis[v]){
			  dad[v] = u;
			  dfs(v);
		  }
	  } 
	  ed[u] = tempo++;
  }

  bool is_ancestor(int u, int v){
	  return st[u] <= st[v] && st[v] <= ed[u];
  }

  int query(int u, int v){
	  if(is_ancestor(u,v)) return u;
	  for(int i=19; i>=0; i--){
		  if(anc[i][u] == -1) continue;
		  if(!is_ancestor(anc[i][u],v)) u = anc[i][u];
	  }
	  return dad[u];
  }

  void precalculate(){
	  dad[1] = -1;
	  dfs(1);
	  for(int i=1; i<st.size(); i++){
		  anc[0][i] = dad[i];
	  }
	  for(int i=1; i<20; i++){
		  for(int j=1; j<st.size(); j++){
				  if(anc[i-1][j] != -1){
					  anc[i][j] = anc[i-1][anc[i-1][j]];
				  }
				  else {
					  anc[i][j] = -1;
				  }
		  }
	  }
  }
  
} lca;

struct query{
	int id, l, r, ans, u, v, extra;
	bool operator<(const query & b) const {
	  return l/(int)sqrt(n) < b.l/(int)sqrt(n) || l/(int)sqrt(n) == b.l/(int)sqrt(n) && r < b.r;
	}
};

struct SqrtDecomposition {

  vector<query> q;
  
  int cur;
  
  void init(int sz){
    q.resize(sz);
  }
  
  void add(int idx){
    if(vis[v[idx]]){
      vis[v[idx]] = false;
      if(cnt[val[v[idx]]] == 1) cur--;
      cnt[val[v[idx]]]--;
    }
    else {
      vis[v[idx]] = true;
      if(cnt[val[v[idx]]] == 0) cur++;
      cnt[val[v[idx]]]++;
    }
  }
  
  void remove(int idx){
    if(vis[v[idx]]){
      vis[v[idx]] = false;
      if(cnt[val[v[idx]]] == 1) cur--;
      cnt[val[v[idx]]]--;
    }
    else {
      vis[v[idx]] = true;
      if(cnt[val[v[idx]]] == 0) cur++;
      cnt[val[v[idx]]]++;
    }
  }
  
  int answer_query(){
    return cur;
  }

  void calculate(){
	  sort(q.begin(), q.end());
	  int l = 0, r = -1;
	  cur = 0;
	  for(int i=0; i<q.size(); i++){
		  while(q[i].l < l) add(--l);
		  while(r < q[i].r) add(++r);
		  while(q[i].l > l) remove(l++);
		  while(r > q[i].r) remove(r--);
		  
		  if(q[i].extra != -1) add(q[i].extra);
		  
		  q[i].ans = answer_query();
		  
		  if(q[i].extra != -1) remove(q[i].extra);
	  }
  }
  
  void print_ans(){
    sort(q.begin(), q.end(), [](const query & a, const query & b){
      return a.id < b.id;
    });
    
    for(query x : q){
      printf("%lld\n", x.ans);
    }
  }
} mos;

int32_t main(){
	DESYNC;
	cin >> n >> q;
	lca.init(n);
	mos.init(q);
	
	int aux[n+1];
	for(int i=1; i<=n; i++){
	  cin >> val[i];
	  aux[i] = val[i];
	}
	
	sort(aux+1, aux+n+1);
	
	for(int i=1; i<=n; i++){
	  val[i] = lower_bound(aux+1, aux+1+n, val[i]) - (aux+1);
	}
	
	vis.reset();
	
	for(int i=0; i<n-1; i++){
	  int u,v;
	  cin >> u >> v;
	  adj[u].pb(v);
	  adj[v].pb(u);
	}
	
	lca.precalculate();
	
	for(int i=1; i<=n; i++){
	  v[lca.st[i]] = i;
	  v[lca.ed[i]] = i;
	}
	
	for(int i=0; i<q; i++){
	  cin >> mos.q[i].u >> mos.q[i].v;
	  mos.q[i].id = i;
	  if(lca.st[mos.q[i].u] > lca.st[mos.q[i].v]) swap(mos.q[i].u, mos.q[i].v);
	  if(lca.query(mos.q[i].u, mos.q[i].v) != mos.q[i].u){
	    mos.q[i].extra = lca.st[lca.query(mos.q[i].u, mos.q[i].v)];
	    mos.q[i].l = lca.ed[mos.q[i].u];
	    mos.q[i].r = lca.st[mos.q[i].v];
	  }
	  else {
	    mos.q[i].extra = -1;
	    mos.q[i].l = lca.st[mos.q[i].u];
	    mos.q[i].r = lca.st[mos.q[i].v];
	  }
	}
	
	mos.calculate();
	
	mos.print_ans();
}


