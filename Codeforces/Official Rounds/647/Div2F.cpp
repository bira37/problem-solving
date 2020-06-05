#include <bits/stdc++.h>

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

/* Author: Ubiratan Correia Barbosa Neto
 * Eulerian Path
 */

struct EulerianCircuit {
  vector<vector<int>> g;
  vector<vector<int>> back_ref;
  vector<int> walk;
  vector<int> deg, indeg, outdeg;
  bool directed;

  EulerianCircuit(int n, bool directed) : directed(directed) {
    if (directed) {
      indeg.resize(n + 1, 0);
      outdeg.resize(n + 1, 0);
    } else {
      deg.resize(n + 1, 0);
      back_ref.resize(n + 1);
    }
    g.resize(n + 1);
  }

  void add_directed_edge(int u, int v) {
    outdeg[u]++;
    indeg[v]++;
    g[u].pb(v);
  }

  void add_undirected_edge(int u, int v) {
    deg[u]++;
    deg[v]++;
    g[u].pb(v);
    g[v].pb(u);
    if (u != v) {
      int ref_u = g[v].size() - 1;
      int ref_v = g[u].size() - 1;
      back_ref[u].pb(ref_u);
      back_ref[v].pb(ref_v);
    } else {
      int cur = back_ref[u].size();
      back_ref[u].pb(cur + 1);
      back_ref[u].pb(cur);
    }
  }

  void add_edge(int u, int v) {
    if (directed)
      add_directed_edge(u, v);
    else
      add_undirected_edge(u, v);
  }

  void undirected_euler(int u) {
    while (g[u].size() > 0) {
      if (g[u].back() < 0) {
        g[u].pop_back();
        back_ref[u].pop_back();
        continue;
      }
      int v = g[u].back();
      int ref = back_ref[u].back();
      g[u].pop_back();
      back_ref[u].pop_back();

      if (g[v].size() > ref) g[v][ref] = -1;

      undirected_euler(v);
    }
    walk.push_back(u);
  }

  void directed_euler(int u) {
    while (g[u].size() > 0) {
      int v = g[u].back();

      g[u].pop_back();

      directed_euler(v);
    }

    walk.push_back(u);
  }
  bool process_directed_euler(bool path = false, int root = 1) {
    int inp = -1, out = -1;
    if (path) {
      for (int i = 1; i < g.size(); i++) {
        if (outdeg[i] - indeg[i] == 1) {
          if (out != -1) return false;
          out = i;
        }
        if (indeg[i] - outdeg[i] == 1) {
          if (inp != -1) return false;
          inp = i;
        }
      }
      if (inp == -1 || out == -1) return false;
      add_directed_edge(inp, out);
      directed_euler(inp);
      walk.pop_back();
      return true;
    } else {
      for (int i = 1; i < g.size(); i++) {
        if (indeg[i] != outdeg[i]) return false;
      }
      directed_euler(root);
      return true;
    }
  }

  bool process_undirected_euler(bool path = false, int root = 1) {
    vector<int> odds;
    if (path) {
      for (int i = 1; i < g.size(); i++) {
        if (deg[i] % 2) odds.push_back(i);
      }
      if (odds.size() != 2) return false;
      add_undirected_edge(odds[0], odds[1]);
      undirected_euler(odds[0]);
      walk.pop_back();
      return true;
    } else {
      for (int i = 1; i < g.size(); i++) {
        if (deg[i] % 2) return false;
      }
      undirected_euler(root);
      return true;
    }
  }

  bool calculate(bool path = false, int root = 1) {
    if (directed) {
      return process_directed_euler(path, root);
    } else {
      return process_undirected_euler(path, root);
    }
  }
};

void solution() {
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  int lo = 1, hi = 20;
  int ans = -1;
  vector<int> walk;
  while (lo <= hi) {
    int i = (lo + hi) >> 1;
    EulerianCircuit euler = EulerianCircuit((1 << i), false);
    int root = 1;
    for (int j = 0; j < 2 * n; j += 2) {
      int u = a[j] & ((1 << i) - 1);
      int v = a[j + 1] & ((1 << i) - 1);
      root = u;
      euler.add_edge(u, v);
    }
    if (euler.calculate(false, root) && euler.walk.size() == n + 1) {
      lo = i + 1;
      ans = i;
      walk.swap(euler.walk);
    } else {
      hi = i - 1;
    }
  }
  if (ans == -1) {
    cout << 0 << endl;
    for (int i = 1; i <= 2 * n; i++) cout << i << " ";
    cout << endl;
  } else {
    int i = ans;
    vector<int> play;
    vector<bool> vis(2 * n, false);
    map<ii, vector<int>> edges;
    for (int j = 0; j < 2 * n; j += 2) {
      int u = a[j] & ((1 << i) - 1);
      int v = a[j + 1] & ((1 << i) - 1);
      edges[ii(u, v)].pb(j);
      edges[ii(v, u)].pb(j + 1);
    }
    for (int j = 1; j < walk.size(); j++) {
      int u = walk[j - 1];
      int v = walk[j];
      while (vis[edges[ii(u, v)].back()]) edges[ii(u, v)].pop_back();
      int ed = edges[ii(u, v)].back();
      edges[ii(u, v)].pop_back();
      vis[ed] = true;
      vis[(ed ^ 1)] = true;
      play.pb(ed);
      play.pb((ed ^ 1));
    }
    cout << i << endl;
    for (int x : play) cout << x + 1 << " ";
    cout << endl;
    return;
  }
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  solution();
}

