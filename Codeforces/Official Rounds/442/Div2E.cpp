#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_tuple
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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

vector<int> adj[212345];
int v[212345];

struct HLD {

  struct node{
    //node values
    int val = 0; //sets neutral value for the operation
    int lazy = 0;
    node() {}
    node(int val) : val(val){
      lazy = 0;
    }
    
    node merge(node b){
      node ret;
      ret = val + b.val;
      return ret;
    }
  };
  

  struct SegmentTree{
  
    vector<node> st;
    
    SegmentTree() {}
    
    void construct(int n){
      st.resize(4*n);
    }
    
    void propagate(int cur, int l, int r){
      if(st[cur].lazy == 0) return;
      
      st[cur].val = (r-l+1) - st[cur].val;
      
      if(l != r){
        st[2*cur].lazy ^= 1;
        st[2*cur+1].lazy ^= 1;
      }
      
      st[cur].lazy = 0;
    }
    
    void build(int cur, int l, int r){
      if(l == r){
        st[cur] = node(v[l]);
        return;
      }
      
      int m = (l+r)>>1;
      
      build(2*cur, l, m);
      build(2*cur+1, m+1, r);
      st[cur] = st[2*cur].merge(st[2*cur+1]);
    }
      
    
    void update(int cur, int l, int r, int a, int b, int val){
      propagate(cur, l, r);
      if(b < l || r < a) return;
      if(a <= l && r <= b){
        st[cur].lazy ^= val;
        propagate(cur, l, r);
        return;
      }
      int m = (l+r)>>1;
      update(2*cur, l, m, a, b, val);
      update(2*cur+1, m+1, r, a, b, val);
      st[cur] = st[2*cur].merge(st[2*cur+1]);
    }
    
    node query(int cur, int l, int r, int a, int b){
      propagate(cur, l, r);
      if(b < l || r < a) return node();  
      if(a <= l && r <= b) return st[cur];
      int m = (l+r)>>1;
      node lef = query(2*cur, l, m, a, b);
      node rig = query(2*cur+1, m+1, r, a, b);
      return lef.merge(rig);
    }
    
  } st;
      

  vector<int> L, P, ch, subsz, in, out;
  int t;
  
  HLD () {}
  
  HLD(int n){
    L.resize(n+1);
    P.resize(n+1);
    ch.resize(n+1);
    subsz.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    st.construct(n+1);
    t = 0;
    for(int i=0; i<=n; i++){
      ch[i] = i;
      P[i] = -1;
      L[i] = 0;
    }
  }

  void precalculate(int u, int p = -1){
    subsz[u] = 1;
    for(int &v : adj[u]){
      if(v == p) continue;
      P[v] = u;
      L[v] = L[u]+1;
      precalculate(v, u);
      if(subsz[adj[u][0]] < subsz[v]) swap(adj[u][0], v);
      subsz[u] += subsz[v];
    }
  }

  void build(int u, int p = -1){
    in[u] = ++t;
    for(int v : adj[u]){
      if(v == p) continue;
      if(adj[u][0] == v){
        ch[v] = ch[u];
      }
      build(v, u);
    }
    out[u] = t;
  }
  
  void calculate(int root = 1){
    precalculate(root);
    build(root);
  }
  
  void build_ds(){
    st.build(1, 1, t);
  }

  void path_update(int a, int b, int val, bool edge_update = false){
    while(ch[a] != ch[b]){
      if(L[ch[b]] > L[ch[a]]) swap(a,b);
      if(in[ch[a]] + edge_update <= in[a]) st.update(1, 1, t, in[ch[a]] + edge_update, in[a], val);
      a = P[ch[a]];
    }
    if(L[b] < L[a]) swap(a,b);
    if(in[a]+edge_update <= in[b]) st.update(1, 1, t, in[a]+edge_update, in[b], val);
  }
  
  void node_update(int u, int val){
    st.update(1, 1, t, in[u], in[u], val);
  }
  
  void edge_update(int u, int v, int val){
    if(L[u] > L[v]) swap(u, v);
    st.update(1, 1, t, in[v], in[v], val);
  }
  
  void subtree_update(int u, int val, bool edge_update = false){
    if(in[u] + edge_update <= out[u]) st.update(1, 1, t, in[u] + edge_update, out[u], val);
  }      

  node path_query(int a, int b, bool edge_query = false){
    node ans;
    while(ch[a] != ch[b]){
      if(L[ch[b]] > L[ch[a]]) swap(a,b);
      if(in[ch[a]] + edge_query <= in[a]) ans.merge(st.query(1, 1, t, in[ch[a]] + edge_query, in[a]));
      a = P[ch[a]];
    }
    if(L[b] < L[a]) swap(a,b);
    if(in[a]+edge_query <= in[b]) ans.merge(st.query(1, 1, t, in[a]+edge_query, in[b]));
    return ans;
  }
  
  node node_query(int u){
    return st.query(1, 1, t, in[u], in[u]);
  }
  
  node edge_query(int u, int v){
    if(L[u] > L[v]) swap(u,v);
    return st.query(1, 1, t, in[v], in[v]);
  }
  
  node subtree_query(int u, bool edge_query = false){
    if(in[u] + edge_query <= out[u]) return st.query(1, 1, t, in[u] + edge_query, out[u]);
    else return node();
  } 
  
};

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=2; i<=n; i++){
    int v;
    cin >> v;
    adj[v].pb(i);
  }
  HLD hld(n);
  hld.calculate();
  for(int i=1; i<=n; i++){
    cin >> v[hld.in[i]];
  }
  hld.build_ds();
  int q;
  cin >> q;
  while(q--){
    string op;
    int u;
    cin >> op >> u;
    if(op == "get") cout << hld.subtree_query(u).val << endl;
    else hld.subtree_update(u, 1);
  }  
}

