#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

vector<int> g[512345];
vector<ii> need;
vector<int> ans(512345);
vector<int> order;

void solution() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    need.pb(ii(x, i));
  }
  sort(all(need));
  for (ii p : need) {
    int u = p.ss;
    int t = p.ff;
    int mx = 1;
    set<int> s;
    for (int v : g[u]) {
      s.insert(ans[v]);
    }
    while (s.count(mx)) mx++;
    if (t == mx) {
      ans[u] = mx;
      order.pb(u);
    } else {
      cout << -1 << endl;
      return;
    }
  }
  for (int x : order) cout << x << " ";
  cout << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
  // cin >> t;
  while (t--) solution();
}

