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

struct Dinic {
  struct FlowEdge {
    int v, rev, c, cap;
    FlowEdge() {}
    FlowEdge(int v, int c, int cap, int rev) : v(v), c(c), cap(cap), rev(rev) {}
  };

  vector<vector<FlowEdge>> adj;
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

  vector<ii> mincut() {
    bool vis[sz];
    for (int i = 0; i < sz; i++) vis[i] = false;
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (FlowEdge e : adj[cur]) {
        if (e.c > 0 && !vis[e.v]) {
          q.push(e.v);
          vis[e.v] = true;
        }
      }
    }
    vector<ii> cut;
    for (int i = 1; i <= sz - 2; i++) {
      if (!vis[i]) continue;
      for (FlowEdge e : adj[i]) {
        if (1 <= e.v && e.v <= sz - 2 && !vis[e.v] && e.cap > 0 && e.c == 0)
          cut.pb(ii(i, e.v));
      }
    }
    return cut;
  }

  vector<ii> min_edge_cover() {
    bool covered[sz];
    for (int i = 0; i < sz; i++) covered[i] = false;
    vector<ii> edge_cover;
    for (int i = 1; i < sz - 1; i++) {
      for (FlowEdge e : adj[i]) {
        if (e.cap == 0 || e.v > sz - 2) continue;
        if (e.c == 0) {
          edge_cover.pb(ii(i, e.v));
          covered[i] = true;
          covered[e.v] = true;
          break;
        }
      }
    }
    for (int i = 1; i < sz - 1; i++) {
      for (FlowEdge e : adj[i]) {
        if (e.cap == 0 || e.v > sz - 2) continue;
        if (e.c == 0) continue;
        if (!covered[i] || !covered[e.v]) {
          edge_cover.pb(ii(i, e.v));
          covered[i] = true;
          covered[e.v] = true;
        }
      }
    }
    return edge_cover;
  }

  /* Vertex Cover */

  vector<vector<int>> vc_g;
  vector<bool> vc_vis;
  vector<bool> vc_mrk;

  void vc_dfs(int u) {
    vc_vis[u] = true;
    for (int v : vc_g[u]) {
      if (vc_vis[v]) continue;
      vc_dfs(v);
    }
  }

  vector<int> min_vertex_cover(int left_sz) {
    int g_sz = adj.size() - 2;
    vc_g.resize(g_sz + 1, vector<int>());
    vc_vis.resize(g_sz + 1, false);
    vc_mrk.resize(g_sz + 1, true);
    for (int i = 1; i <= left_sz; i++) {
      for (auto e : adj[i]) {
        if (e.v != src && e.v != snk) {
          if (e.c != e.cap) {
            // satured goes to right
            vc_g[e.v].pb(i);
            vc_mrk[i] = false;
          } else {
            // non saturated goes to left
            vc_g[i].pb(e.v);
          }
        }
      }
    }
    for (int i = 1; i <= left_sz; i++) {
      if (vc_mrk[i]) vc_dfs(i);
    }
    vector<int> cover;
    for (int i = 1; i <= g_sz; i++) {
      if (!vc_vis[i] && i <= left_sz)
        cover.pb(i);
      else if (vc_vis[i] && i > left_sz)
        cover.pb(i);
    }
    return cover;
  }

  /* End of Vertex Cover */
};

// #define MULTIPLE_TEST_CASE
void solution() {
  int n, m;
  cin >> n >> m;
  map<ii, int> id;
  int lul = 1;
  char A[n + 1][m + 1];
  Dinic dinic = Dinic(n * m);
  int desired_odd = 0;
  int desired_even = 0;
  rep(i, 1, n + 1, 1) {
    rep(j, 1, m + 1, 1) {
      id[ii(i, j)] = lul++;
      cin >> A[i][j];
      int cst;
      if (A[i][j] == 'H')
        cst = 1;
      else if (A[i][j] == 'O')
        cst = 2;
      else if (A[i][j] == 'N')
        cst = 3;
      else if (A[i][j] == 'C')
        cst = 4;
      else
        cst = 0;
      if ((i + j) % 2 == 0) {
        dinic.add_to_src(id[ii(i, j)], cst);
        desired_even += cst;
      } else {
        dinic.add_to_snk(id[ii(i, j)], cst);
        desired_odd += cst;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i + j) % 2 != 0) continue;
      int dx[] = {0, 1, 0, -1};
      int dy[] = {-1, 0, 1, 0};
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x <= 0 || y <= 0 || x > n || y > m) continue;
        dinic.add_edge(id[ii(i, j)], id[ii(x, y)], 1);
      }
    }
  }
  dinic.calculate();
  // cout << dinic.max_flow << " " << desired_even << " " << desired_odd <<
  // endl;
  if (dinic.max_flow > 0 && dinic.max_flow == desired_even &&
      desired_odd == desired_even)
    cout << "Valid" << endl;
  else
    cout << "Invalid" << endl;
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

