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

vector<int> adj[212345];
int subsz[212345];
int dad[212345];
int L[212345];

void go(int u){
  subsz[u] = 1;
  int mx = -1;
  for(int i=0; i<adj[u].size(); i++){
    int v = adj[u][i];
    if(v == dad[u]) continue;
    go(v);
    subsz[u] += subsz[v];
    if(subsz[v] > mx){
      mx = subsz[v];
      swap(adj[u][0], adj[u][i]);
    }
  }
}

int get_heavy(int u){
  if(adj[u][0] != dad[u]) return get_heavy(adj[u][0]);
  else return u;
}

int get_node(int u, int val){
  if(L[u] == val) return u;
  else return get_node(adj[u][0], val);
}

void precalc(int u, int p){
  if(p != -1) L[u] = L[p]+1;
  dad[u] = p;
  for(int v : adj[u]){
    if(v == p) continue;
    precalc(v, u);
  }
}

int32_t main(){
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  L[1] = 0;
  precalc(1, -1);
  int root = 1;
  cout << "d " << 1 << endl;
  cout.flush();
  int du;
  cin >> du;
  int lst = 1;
  int dist = du;
  while(true){
    go(root);
    int v = get_heavy(root);
    int dv = L[v];
    cout << "d " << v << endl;
    cout.flush();
    int duv;
    cin >> duv;
    int dw = (dv + du - duv)/2;
    int w = get_node(root, dw);
    if(L[w] == du){
      cout << "! " << w << endl;
      return 0;
    }
    cout << "s " << w << endl;
    cout.flush();
    cin >> root;
    dist -= abs(L[root] - L[lst]);
    lst = root;
    if(dist == 0){
      cout << "! " << root << endl;
      cout.flush();
      return 0;
    }
  }
}