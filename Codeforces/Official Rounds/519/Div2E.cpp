#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
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
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;
using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int iter = 0;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

vector<int> adj[312345];

int32_t main(){
  DESYNC;
  int n, m;
  cin >> n >> m;
  int x[n], y[n];
  int ans[n];
  vector< ii > v;
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
    v.pb(ii(x[i] - y[i], i));
  }
  sort(v.begin(), v.end());
  int px[n], py[n];
  px[0] = x[v[0].ss];
  py[0] = y[v[0].ss];
  for(int i=1; i<n; i++){
    px[i] = px[i-1] + x[v[i].ss];
    py[i] = py[i-1] + y[v[i].ss];
  }
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for(int i=0; i<n; i++){
    int id = v[i].ss;
    ///cout << id << endl;
    ans[id] = ((n-1) - i)*x[id] + (py[n-1] - py[i]) + (i)*y[id] + (i-1 >= 0 ? px[i-1] : 0);
  }
  for(int i=0; i<n; i++){
    for(int j : adj[i]) ans[i] -= min(x[i] + y[j], x[j] + y[i]);
  }
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  cout << endl;
}

