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
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

vector<vector<int>> g;
vector<bool> vis;
vector<bool> mrk;

void dfs(int u) {
  vis[u] = true;
  // cout << "at " << u << endl;
  for (int v : g[u]) {
    if (vis[v]) continue;
    dfs(v);
  }
}

// #define MULTIPLE_TEST_CASE
void solution() {
  int n, m;
  cin >> n >> m;
  g.resize(n + m + 1, vector<int>());
  vis.resize(n + m + 1, false);
  mrk.resize(n + m + 1, true);
  vector<ii> edges;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      edges.pb(ii(i, n + x));
    }
  }
  set<ii> matching;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    matching.insert(ii(i, x + n));
  }
  for (ii e : edges) {
    if (matching.count(e)) {
      mrk[e.ff] = false;
      g[e.ss].pb(e.ff);
      // cout << e.ss << " -> " << e.ff << endl;
    } else {
      g[e.ff].pb(e.ss);
      // cout << e.ff << " -> " << e.ss << endl;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (mrk[i]) dfs(i);
  }
  vector<int> left, right;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) left.pb(i);
  }
  for (int i = n + 1; i <= n + m; i++) {
    if (vis[i]) right.pb(i);
  }
  cout << left.size() + right.size() << endl;
  cout << left.size();
  for (int x : left) cout << " " << x;
  cout << endl;
  cout << right.size();
  for (int x : right) cout << " " << x - n;
  cout << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

