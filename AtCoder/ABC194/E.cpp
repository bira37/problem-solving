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
/* Author: Ubiratan Neto
 *
 */

struct BIT {
  vector<int> bit;

  BIT() {}

  int n;

  BIT(int n) {
    this->n = n;
    bit.resize(n + 1);
  }

  void update(int idx, int val) {
    for (int i = idx; i <= n; i += i & -i) {
      bit[i] += val;
    }
  }

  int prefix_query(int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += bit[i];
    }
    return ans;
  }

  int query(int l, int r) { return prefix_query(r) - prefix_query(l - 1); }

  // int bit 0-1 it finds the index of k-th element active
  int kth(int k) {
    int cur = 0;
    int acc = 0;
    for (int i = 19; i >= 0; i--) {
      if (cur + (1 << i) > n) continue;
      if (acc + bit[cur + (1 << i)] < k) {
        cur += (1 << i);
        acc += bit[cur];
      }
    }
    return ++cur;
  }
};
/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
// #define PRINT_TEST_CASE
//#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

int find_mex(BIT& bit, int n) {
  int l = 1, r = n;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (bit.prefix_query(m) != m) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ans - 1;
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, m;
  cin >> n >> m;
  int ans = INF;
  BIT bit(n + 10);
  int v[n];
  map<int, int> cnt;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    x++;
    v[i] = x;
    cnt[x]++;
    if (cnt[x] == 1) bit.update(x, 1);
  }
  ans = min(ans, find_mex(bit, n + 1));
  for (int i = m; i < n; i++) {
    cnt[v[i - m]]--;
    if (cnt[v[i - m]] == 0) bit.update(v[i - m], -1);
    int x;
    cin >> x;
    x++;
    v[i] = x;
    cnt[x]++;
    if (cnt[x] == 1) bit.update(x, 1);
    ans = min(ans, find_mex(bit, n + 1));
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

