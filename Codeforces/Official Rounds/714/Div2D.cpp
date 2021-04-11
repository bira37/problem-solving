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

int v[212345];

int uf[212345];
int sz[212345];

void init(int n) {
  for (int i = 0; i <= n; i++) uf[i] = i, sz[i] = 1;
}

int find(int x) {
  if (uf[x] == x)
    return x;
  else
    return uf[x] = find(uf[x]);
}

void unit(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (sz[x] < sz[y]) swap(x, y);
  uf[y] = x;
  sz[x] += sz[y];
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) cin >> v[i];
  init(n);
  int ans = 0;

  vii pool;
  for (int i = 0; i < n; i++) pool.pb(ii(v[i], i));
  sort(all(pool));

  for (ii cur : pool) {
    if (cur.ff > p) break;

    int min_val = v[cur.ss], gcd_val = v[cur.ss];
    for (int i = cur.ss + 1; i < n; i++) {
      if (find(cur.ss) == find(i)) break;
      min_val = min(min_val, v[i]);
      gcd_val = gcd(gcd_val, v[i]);
      if (min_val == cur.ff && min_val == gcd_val) {
        unit(cur.ss, i);
        ans += cur.ff;
      } else if (min_val < cur.ff || gcd_val < cur.ff)
        break;
    }

    min_val = v[cur.ss], gcd_val = v[cur.ss];
    for (int i = cur.ss - 1; i >= 0; i--) {
      if (find(cur.ss) == find(i)) break;
      min_val = min(min_val, v[i]);
      gcd_val = gcd(gcd_val, v[i]);
      if (min_val == cur.ff && min_val == gcd_val) {
        unit(cur.ss, i);
        ans += cur.ff;
      } else if (min_val < cur.ff || gcd_val < cur.ff)
        break;
    }
  }

  for (int i = 1; i < n; i++) {
    if (find(i) != find(i - 1)) {
      unit(i, i - 1);
      ans += p;
    }
  }

  cout << ans << endl;
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
