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

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n;
  cin >> n;
  int path[n + 1];
  for (int i = 0; i <= n; i++) path[i] = i;

  function<int(int)> nxt = [&](int x) {
    if (path[x] == x)
      return x;
    else
      return path[x] = nxt(path[x]);
  };

  int v[n + 1];
  for (int i = 0; i < n; i++) cin >> v[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > 1) {
      // cout << "at " << i << " " << v[i] << endl;
      // eliminate all 1-sized paths
      int biggest_valid = max(1LL, n - i - 1);
      if (v[i] >= biggest_valid) {
        ans += (v[i] - biggest_valid);
        v[i] = biggest_valid;
      }
      // cout << "new " << v[i] << endl;
      // run
      while (v[i] > 1) {
        // cout << "simulating " << endl;
        int cur = i;
        while (cur < n) {
          // cout << "at " << cur << endl;
          // skips ones
          cur = nxt(cur);
          if (cur >= n) break;
          // cout << "jumped to nxt = " << cur << " " << v[cur] << endl;
          int sz = v[cur];
          v[cur] = max(1LL, v[cur] - 1);
          if (v[cur] == 1) path[cur] = nxt(cur + 1);
          cur += sz;
        }
        ans++;
      }

      // cout << "dbg" << endl;
      // for (int i = 0; i < n; i++) cout << v[i] << " ";
      // cout << endl;
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

