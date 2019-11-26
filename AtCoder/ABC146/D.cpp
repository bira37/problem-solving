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

vector<int> g[112345];
map< ii, int> e_to_id;
int ans[112345];
int mx = 0;
void go(int u, int p, int lst){
  set<int> s;
  int key = 1;
  s.insert(lst);
  while(s.count(key)) key++;
  for(int v : g[u]){
    if(p == v) continue;
    ans[e_to_id[ii(u,v)]] = key;
    s.insert(key);
    mx = max(mx, key);
    go(v, u, key);
    while(s.count(key)) key++;
  }
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    e_to_id[ii(u,v)] = i;
    e_to_id[ii(v,u)] = i;
    ans[i] = 0;
  }
  go(1, -1, -1);
  cout << mx << endl;
  for(int i=0; i<n-1; i++) cout << ans[i] << endl;
}



