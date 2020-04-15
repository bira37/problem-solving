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
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
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

struct Dinic {
  struct FlowEdge {
    int v, rev, c, cap;
    FlowEdge() {}
    FlowEdge(int v, int c, int cap, int rev) : v(v), c(c), cap(cap), rev(rev) {}
  };

  vector<vector<FlowEdge> > adj;
  vector<int> level, used;
  int src, snk;
  int sz;
  int max_flow;
  Dinic() {}
  Dinic(int n) {
    src = 0;
    snk = n + 1;
    adj.resize(n + 2, vector<FlowEdge>());
    level.resize(n + 2);
    used.resize(n + 2);
    sz = n + 2;
    max_flow = 0;
  }

  void add_edge(int u, int v, int c) {
    int id1 = adj[u].size();
    int id2 = adj[v].size();
    adj[u].pb(FlowEdge(v, c, c, id2));
    adj[v].pb(FlowEdge(u, 0, 0, id1));
  }

  void add_to_src(int v, int c) { adj[src].pb(FlowEdge(v, c, c, -1)); }

  void add_to_snk(int u, int c) { adj[u].pb(FlowEdge(snk, c, c, -1)); }

  bool bfs() {
    for (int i = 0; i < sz; i++) {
      level[i] = -1;
    }

    level[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (FlowEdge e : adj[cur]) {
        if (level[e.v] == -1 && e.c > 0) {
          level[e.v] = level[cur] + 1;
          q.push(e.v);
        }
      }
    }

    return (level[snk] == -1 ? false : true);
  }

  int send_flow(int u, int flow) {
    if (u == snk) return flow;

    for (int &i = used[u]; i < adj[u].size(); i++) {
      FlowEdge &e = adj[u][i];

      if (level[u] + 1 != level[e.v] || e.c <= 0) continue;

      int new_flow = min(flow, e.c);
      int adjusted_flow = send_flow(e.v, new_flow);

      if (adjusted_flow > 0) {
        e.c -= adjusted_flow;
        if (e.rev != -1) adj[e.v][e.rev].c += adjusted_flow;
        return adjusted_flow;
      }
    }

    return 0;
  }

  void calculate() {
    if (src == snk) {
      max_flow = -1;
      return;
    }  // not sure if needed

    max_flow = 0;

    while (bfs()) {
      for (int i = 0; i < sz; i++) used[i] = 0;
      while (int inc = send_flow(src, INF)) max_flow += inc;
    }
  }
};

int A[51][51];

bool can_place(int elem, int r, int c, int n) {
  if (A[r][c] != 0 && A[r][c] == elem) return true;
  if (A[r][c] != 0 && A[r][c] != elem) return false;

  for (int i = 0; i < n; i++)
    if (A[i][c] == elem) return false;
  for (int i = 0; i < n; i++)
    if (A[r][i] == elem) return false;

  return true;
}

void solve(int testnum, int n, int k) {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) A[i][j] = 0;
  }
  cout << "Case #" << testnum << ": ";
  if (n == 2) {
    if (k == 2) {
      cout << "POSSIBLE" << endl;
      cout << "1 2" << endl;
      cout << "2 1" << endl;
    } else if (k == 4) {
      cout << "POSSIBLE" << endl;
      cout << "2 1" << endl;
      cout << "1 2" << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
    return;
  }
  int X, Y, Z;
  bool found = false;
  for (X = 1; X <= n && !found; X++) {
    for (Y = 1; Y <= n && !found; Y++) {
      if (X == Y) continue;
      for (Z = 1; Z <= n && !found; Z++) {
        if (Z == X) continue;
        if (X * (n - 2) + Y + Z == k) {
          found = true;
          break;
        }
      }
      if (found) break;
    }
    if (found) break;
  }
  if (!found) {
    for (int i = 1; i <= n; i++) {
      if (i * n == k) {
        found = true;
        X = Y = Z = i;
        break;
      }
    }
  }
  if (!found) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  for (int i = 0; i < n - 2; i++) {
    A[i][i] = X;
  }
  A[n - 2][n - 2] = Y;
  A[n - 1][n - 1] = Z;

  // build from bottom to top
  for (int r = n - 1; r >= 0; r--) {
    Dinic dinic(n + n);
    for (int i = 1; i <= n; i++) {
      dinic.add_to_src(i, 1);
      dinic.add_to_snk(i + n, 1);

      for (int j = 1; j <= n; j++) {
        if (can_place(i, r, j - 1, n)) {
          dinic.add_edge(i, j + n, 1);
        }
      }
    }

    dinic.calculate();
    if (dinic.max_flow != n) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }

    for (int i = 1; i <= n; i++) {
      for (auto e : dinic.adj[i]) {
        if (e.c == 0) {
          A[r][e.v - n - 1] = i;
        }
      }
    }
  }

  cout << "POSSIBLE" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (j > 0 ? " " : "") << A[i][j];
    }
    cout << endl;
  }
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, k;
    cin >> n >> k;
    solve(i, n, k);
  }
}

