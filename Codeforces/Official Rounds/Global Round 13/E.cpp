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
#define vb vector<bool>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
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

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n;
  cin >> n;
  vii g[n + 1];
  vi active(n + 1, 1);
  vi subsz(n + 1, 0);

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(ii(v, i));
    g[v].pb(ii(u, i));
  }

  vi fib(30);
  fib[0] = fib[1] = 1;
  int k = 1;
  for (int i = 2; i < 30; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (n == fib[i]) k = i;
  }

  if (n == 1) {
    cout << "YES" << endl;
    return;
  }

  if (k <= 1) {
    cout << "NO" << endl;
    return;
  }

  function<void(int, int)> dfs = [&](int u, int p) {
    subsz[u] = 1;
    for (ii edge : g[u]) {
      int v = edge.ff;
      int id = edge.ss;
      if (!active[id]) continue;
      if (v == p) continue;
      dfs(v, u);
      subsz[u] += subsz[v];
    }
  };

  // <u, v, edge_id, kth>
  function<tuple<int, int, int, int>(int, int, int, int)> find_edge = [&](int u, int p, int tot, int k) {
    tuple<int, int, int, int> ans = mt(-1, -1, -1, -1);

    for (ii edge : g[u]) {
      int v = edge.ff;
      int id = edge.ss;

      if (!active[id]) continue;
      if (v == p) continue;

      // test (u,v)
      if (subsz[v] == fib[k - 1] && tot - subsz[v] == fib[k - 2]) {
        return mt(u, v, id, k - 2);
      }

      if (subsz[v] == fib[k - 2] && tot - subsz[v] == fib[k - 1]) {
        return mt(u, v, id, k - 1);
      }

      ans = find_edge(v, u, tot, k);

      if (get<0>(ans) != -1) return ans;
    }

    return ans;
  };

  function<bool(int, int)> go = [&](int u, int k) {
    if (k <= 1) return true;
    bool ok = true;
    dfs(u, -1);

    auto edge = find_edge(u, u, subsz[u], k);

    if (get<0>(edge) == -1) return false;

    active[get<2>(edge)] = 0;

    ok &= go(get<0>(edge), get<3>(edge));
    ok &= go(get<1>(edge), get<3>(edge) == k - 1 ? k - 2 : k - 1);
    return ok;
  };

  cout << (go(1, k) ? "YES" : "NO") << endl;
}

#ifdef FILE_INPUT
freopen("equal.in", "r", stdin);
freopen("equal.out", "w", stdout);
#endif

int32_t main() {
  DESYNC;
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++) solution(_testcase);
}

