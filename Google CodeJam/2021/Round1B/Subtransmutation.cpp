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
#define PRINT_TEST_CASE
#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */
int mx = 0;
bool can(int n, vector<int>& c, int piece, int a, int b) {
  // cout << "simulating " << piece << endl;
  vector<int> metal(piece + 1, 0);
  metal[piece] = 1;

  bool ok = true;
  for (int i = piece; i >= 1; i--) {
    // cout << metal[i] << " " << (i <= n ? c[i] : -1) << endl;m
    metal[i] = min(metal[i], 500LL);
    if (i <= n) {
      if (metal[i] < c[i]) {
        ok = 0;
        break;
      }
      metal[i] -= c[i];
    }
    if (i - a > 0) metal[i - a] += metal[i];
    if (i - b > 0) metal[i - b] += metal[i];
    metal[i] = 0;
  }
  return ok;
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n;
  int a, b;
  cin >> n;
  cin >> a >> b;
  vector<int> c(n + 1);
  int mn = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (c[i] > 0) mn = max(mn, i);
  }

  for (int i = mn; i <= 40 * 12; i++) {
    if (can(n, c, i, a, b)) {
      cout << i << endl;
      return;
    }
  }

  cout << "IMPOSSIBLE" << endl;
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
