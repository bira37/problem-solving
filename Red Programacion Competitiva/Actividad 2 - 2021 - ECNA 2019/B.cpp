#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

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
#define INF 1e12
#define ROOT 1
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
using ll = long long;
using namespace std;
const double PI = acos(-1);
const int M = 1000000007;
// const int M = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k, int m = M) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2, m);
  ax = mod(ax * ax, m);
  if (k % 2) ax = mod(ax * n, m);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

/* LIBRARY INCLUDES */

/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
// #define PRINT_TEST_CASE
//#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

struct edge {
  int v, t, a;
  edge() {}
  edge(int v, int t, int a) : v(v), t(t), a(a) {}
};

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, d, ccw, cw;
  cin >> n >> d >> ccw >> cw;
  vector<edge> g[n + 1];
  vector<vi> mat(n + 1, vi(n + 1));
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int d, t, a;
      cin >> d >> t >> a;
      a %= 360;
      g[i].pb(edge(d, t, a));
      mat[i][d] = a;
    }
  }

  auto can = [&](int cur, int dest) {
    if (cur == 360) return true;
    if (cur == dest) return true;
    if (cur < dest && dest - cur <= ccw) return true;
    if (cur < dest && cur + (360 - dest) <= cw) return true;

    if (dest < cur && cur - dest <= cw) return true;
    if (dest < cur && (360 - cur) + dest <= ccw) return true;

    return false;
  };

  auto dijkstra = [&](int start, int sang, int t) {
    vector<vi> dist(n + 1, vi(361, INF));

    // <dist, vertex, angle>
    set<tuple<int, int, int>> s;
    dist[start][sang] = 0;
    s.insert(mt(0, start, sang));
    while (!s.empty()) {
      auto cur = *s.begin();
      s.erase(s.begin());
      if (dist[get<1>(cur)][get<2>(cur)] != get<0>(cur)) continue;
      // cout << "at " << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << endl;
      // if (get<1>(cur) == t) return ii(get<0>(cur), get<2>(cur));

      for (edge e : g[get<1>(cur)]) {
        int vou = mod(mat[e.v][get<1>(cur)] + 180, 360);
        if (can(get<2>(cur), e.a) && dist[e.v][vou] > get<0>(cur) + e.t) {
          dist[e.v][vou] = get<0>(cur) + e.t;
          s.insert(mt(dist[e.v][vou], e.v, vou));
        }
      }
    }
    vii results;
    for (int i = 0; i < 360; i++) {
      if (dist[t][i] < INF) results.pb(ii(dist[t][i], i));
    }
    return results;
  };

  vii go = dijkstra(1, 360, d);

  if (go.size() == 0) {
    cout << "impossible" << endl;
    return;
  }

  int ans = INF;
  for (ii x : go) {
    vii go2 = dijkstra(d, x.ss, 1);
    // cout << "i can go to " << d << " with dist " << x.ff << " and angle " << x.ss << endl;
    for (ii y : go2) {
      // cout << "i can go back to " << 1 << " with dist " << y.ff << " and angle " << y.ss << endl;
      ans = min(ans, x.ff + y.ff);
    }
  }

  if (ans >= INF) {
    cout << "impossible" << endl;
    return;
  }

  cout << ans << endl;
}

#ifdef FILE_INPUT
freopen("equal.in", "r", stdin);
freopen("equal.out", "w", stdout);
#endif

int32_t main() {
  // DESYNC;
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++) solution(_testcase);
}
