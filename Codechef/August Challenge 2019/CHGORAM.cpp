#include <bits/stdc++.h>

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

struct BIT {
  
  vector<int> bit;

  BIT() {}
  
  int n;
   
  BIT(int n) {
    this->n = n;
    bit.resize(n+1);
  }

  void update(int idx, int val){
    for(int i = idx; i <= n; i += i&-i){
      bit[i]+=val;
    }
  }

  int prefix_query(int idx){
    int ans = 0;
    for(int i=idx; i>0; i -= i&-i){
      ans += bit[i];
    }
    return ans;
  }
  
  int query(int l, int r){
    return prefix_query(r) - prefix_query(l-1);
  }
  
  //int bit 0-1 it finds the index of k-th element active
  int kth(int k) {
    int cur = 0;
    int acc = 0;
    for(int i = 19; i >= 0; i--) {
      if(cur + (1<<i) > n) continue;
      if(acc + bit[cur + (1<<i)] < k) {
        cur += (1<<i);
        acc += bit[cur];
      }
    }
    return ++cur;
  }
  
};

int p1, p2, p3;
vector<int> g[112345];
int low[112345], high[112345];
vector<ii> need[112345]; 
int st[112345];
int subsz[112345];
int tempo;
BIT bit;
long long ans;
int n;

void go(int u, int p){
  
  long long low_out = u-1;
  long long high_out = n-u;
  
  for(int v : g[u]){
    if(v == p) continue;
    
    go(v, u);
    
    long long low_in = low[v];
    long long high_in = high[v];
    
    low_out -= low_in;
    high_out -= high_in;
    
  }
  
  for(int v : g[u]){
    if(v == p) continue;
    
    long long low_in = low[v];
    long long high_in = high[v];
    
    //cases
    if(p1 == 1 && p2 == 2 && p3 == 3){
      ans += low_in*high_out + low_out*high_in;
    }
    else if(p1 == 1 && p2 == 3 && p3 == 2){
      ans += low_in*low_out;
    }
    else if(p1 == 2 && p2 == 1 && p3 == 3){
      ans += high_in*high_out;
    }
    else if(p1 == 2 && p2 == 3 && p3 == 1){
      ans += low_in*low_out;
    }
    else if(p1 == 3 && p2 == 2 && p3 == 1){
      ans += high_out*low_in + high_in*low_out;
    }
    else if(p1 == 3 && p2 == 1 && p3 == 2){
      ans += high_in*high_out;
    }
    
    low_out += low_in;
    high_out += high_in;
    
  }
}

void dfs(int u, int p){
  st[u] = tempo++;
  subsz[u] = 1;
  for(int v : g[u]){
    if(v == p) continue;
    dfs(v, u);
    subsz[u] += subsz[v];
  }
}

void precalc(int u, int p){
  if(p != -1){
    low[u] = (p > 1 ? -bit.query(1, p-1) : 0);
    high[u] = (p < n ? -bit.query(p+1, n) : 0);
    need[st[u] + subsz[u]-1].pb(ii(u, p));
  }
  bit.update(u, 1);
  for(ii qry : need[st[u]]){
    int v = qry.ff;
    int anc = qry.ss;
    low[v] += (anc > 1 ? bit.query(1, anc-1) : 0);
    high[v] += (anc < n ? bit.query(anc+1, n) : 0);
  }
  need[st[u]].clear();
  for(int v : g[u]){
    if(v == p) continue;
    precalc(v, u);
  }
}
      
void solve(){
  ans = 0;
  tempo = 1;
  cin >> n;
  cin >> p1 >> p2 >> p3;
  for(int i=0; i<=n; i++){
    g[i].clear();
  }
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  bit = BIT(n);
  dfs(1, -1);
  precalc(1, -1);
  go(1, -1);
  cout << ans << endl;
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--) solve();
}


