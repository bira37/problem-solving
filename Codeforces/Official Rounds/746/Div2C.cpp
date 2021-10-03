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

//#define int long long
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
#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

vi g[112345];
int a[112345];
int sub[112345];

void go(int u, int p) {
  sub[u] = a[u];
  for (int v : g[u]) {
    if (v == p) continue;
    go(v, u);
    sub[u] ^= sub[v];
  }
}

int dfs1(int u, int p, int x) {
  for (int v : g[u]) {
    if (v == p) continue;
    int ans = dfs1(v, u, x);
    if (ans != -1) return ans;
  }
  if (sub[u] == x) {
    return u;
  } else {
    return -1;
  }
}

void go2(int u, int p, int r) {
  sub[u] = a[u];
  for (int v : g[u]) {
    if (v == p) continue;
    if (v == r) continue;
    go2(v, u, r);
    sub[u] ^= sub[v];
  }
}

int dfs2(int u, int p, int x, int r) {
  for (int v : g[u]) {
    if (v == p) continue;
    if (v == r) continue;
    int ans = dfs2(v, u, x, r);
    if (ans != -1) return ans;
  }
  if (sub[u] == x) {
    return u;
  } else {
    return -1;
  }
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  go(1, -1);
  if (sub[1] == 0) {
    cout << "YES" << endl;
    return;
  }

  if (k == 2) {
    cout << "NO" << endl;
    return;
  }

  int x = sub[1];

  int r1 = dfs1(1, -1, x);

  if (r1 != -1 && r1 != 1) {
    go2(1, -1, r1);
    int r2 = dfs2(1, -1, x, r1);
    if (r2 != -1) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
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
