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

  auto ask = [&](vi a, vi b) {
    cout << "? " << a.size() << " " << b.size() << endl;
    for (int x : a) cout << x + 1 << (x != a.back() ? " " : "");
    cout << endl;
    for (int x : b) cout << x + 1 << (x != b.back() ? " " : "");
    cout << endl;
    cout.flush();
    int k;
    cin >> k;
    return k;
  };

  auto build = [](int x, int y) {
    vi v;
    for (int i = x; i <= y; i++) v.pb(i);
    return v;
  };

  int n;
  cin >> n;

  int mag = -1;
  for (int i = 1; i < n; i++) {
    int f = ask(build(0, i - 1), build(i, i));
    if (f != 0) {
      mag = i;
      break;
    }
  }

  // construct ans
  vi ans;

  // find all non magnetized from mag+1 to n
  for (int i = mag + 1; i < n; i++) {
    int f = ask(build(i, i), build(mag, mag));
    if (!f) ans.pb(i);
  }

  // find the magnetized on the [0, mag]
  int l = 0, r = mag - 1;
  int id = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int f = ask(build(0, m), build(mag, mag));
    if (f != 0) {
      r = m - 1;
      id = m;
    } else {
      l = m + 1;
    }
  }

  for (int i = 0; i < mag; i++) {
    if (i != id) ans.pb(i);
  }

  sort(all(ans));
  cout << "! " << ans.size() << endl;
  for (int x : ans) cout << x + 1 << (x != ans.back() ? " " : "");
  cout << endl << flush;
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

