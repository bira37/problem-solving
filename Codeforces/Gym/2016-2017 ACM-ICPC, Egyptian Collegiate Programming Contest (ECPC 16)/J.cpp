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
  fin.tie(0);                       \
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

ifstream fin("car.in");

vector<int> adj[512345];
vector<int> cst[512345];
int ans[512345];
int dp[512345];

struct LCA {
  int tempo;
  vector<int> st, ed, dad, cost, leafs, anc[20], L;
  vector<int> dist[20];
  vector<bool> vis;

  LCA() {}

  LCA(int n) {
    tempo = 0;
    st.resize(n + 1);
    ed.resize(n + 1);
    dad.resize(n + 1);
    cost.resize(n + 1);
    L.resize(n + 1);
    for (int i = 0; i < 20; i++) anc[i].resize(n + 1), dist[i].resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i <= n; i++) vis[i] = false;
  }

  void dfs(int u) {
    vis[u] = true;
    st[u] = tempo++;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (!vis[v]) {
        dad[v] = u;
        cost[v] = cst[u][i];
        L[v] = L[u] + 1;
        dfs(v);
      }
    }
    ed[u] = tempo++;
  }

  bool is_ancestor(int u, int v) { return st[u] <= st[v] && st[v] <= ed[u]; }

  int query(int u, int v) {
    if (is_ancestor(u, v)) return u;
    for (int i = 19; i >= 0; i--) {
      if (anc[i][u] == -1) continue;
      if (!is_ancestor(anc[i][u], v)) u = anc[i][u];
    }
    return dad[u];
  }

  int distance(int u, int v) { return L[u] + L[v] - 2 * L[query(u, v)]; }

  void precalculate() {
    dad[1] = -1;
    L[1] = 0;
    dfs(1);
    for (int i = 1; i < st.size(); i++) {
      anc[0][i] = dad[i];
      dist[0][i] = cost[i];
    }
    for (int i = 1; i < 20; i++) {
      for (int j = 1; j < st.size(); j++) {
        if (anc[i - 1][j] != -1) {
          anc[i][j] = anc[i - 1][anc[i - 1][j]];
          dist[i][j] = dist[i - 1][anc[i - 1][j]] + dist[i - 1][j];
        } else {
          anc[i][j] = -1;
          dist[i][j] = INF;
        }
      }
    }
  }
};

int calc(int u, int p) {
  int acc = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    acc += calc(v, u);
  }
  acc += dp[u];
  ans[u] = acc;
  return acc;
}
#define MULTIPLE_TEST_CASE
void solution() {
  int n;
  fin >> n;
  int gas[n + 1];

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    cst[i].clear();
    ans[i] = 0;
    dp[i] = 0;
    fin >> gas[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    fin >> a >> b >> c;
    adj[a].pb(b);
    adj[b].pb(a);
    cst[a].pb(c);
    cst[b].pb(c);
  }
  LCA lca = LCA(n);
  lca.precalculate();

  for (int u = 1; u <= n; u++) {
    // climb through i with gas[i]
    dp[u]++;
    int cur = u;
    int travel = 0;
    for (int i = 19; i >= 0; i--) {
      if (lca.anc[i][cur] == -1) continue;
      if (travel + lca.dist[i][cur] > gas[u]) continue;
      travel += lca.dist[i][cur];
      cur = lca.anc[i][cur];
    }
    if (lca.dad[cur] != -1) dp[lca.dad[cur]]--;
    // cout << u << " can climb up to " << cur << endl;
  }

  calc(1, -1);

  for (int i = 1; i <= n; i++) cout << ans[i] - 1 << " ";
  cout << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  fin >> t;
#endif
  while (t--) solution();
}
