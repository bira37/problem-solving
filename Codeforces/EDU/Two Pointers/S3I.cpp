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

// #define int long long
// #define double long double
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
#define INF 1e9
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
// #define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

using barr = bitset<1001>;

barr reverse_barr(barr& b, int sz) {
  barr newbs;
  newbs.reset();
  for (int i = 0, j = sz; i <= sz; i++, j--) {
    newbs[i] = b[j];
  }
  return newbs;
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  stack<pair<barr, int>> L, R;
  barr zerobs;
  zerobs.reset();
  zerobs[0] = 1;
  int n, s;
  cin >> n >> s;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = INF;
  for (int i = 0; i < n; i++) {
    // cout << "index " << i << endl;
    // push to r

    if (R.empty())
      R.emplace(zerobs | (zerobs << v[i]), i);
    else
      R.emplace(R.top().ff | (R.top().ff << v[i]), i);

    if (R.top().ff[s]) ans = min(ans, (int)R.size());

    // cout << "lets try" << endl;
    auto reshape = [&](stack<pair<barr, int>>& L, stack<pair<barr, int>>& R) {
      barr newbs;
      newbs.reset();
      newbs[0] = 1;
      while (!R.empty()) {
        newbs = newbs | (newbs << v[R.top().ss]);
        L.emplace(reverse_barr(newbs, s), R.top().ss);
        R.pop();
        // verify ans
        if (newbs[s]) ans = min(ans, (int)L.size());
      }
    };

    auto ok = [&](stack<pair<barr, int>>& L, stack<pair<barr, int>>& R) {
      // cout << "at ok" << endl;
      // cout << "checking " << (L.empty() ? -1 : L.top().ss) << " "
      //      << (R.empty() ? -1 : R.top().ss) << endl;

      if (L.empty()) reshape(L, R);

      if (R.empty()) {
        return false;
      } else {
        auto merge = L.top().ff & R.top().ff;
        if (merge.count()) {
          ans = min(ans, R.top().ss - L.top().ss + 1);
          return true;
        }
      }

      return false;
    };

    // pop while you can
    while (ok(L, R)) {
      // cout << "went well" << endl;
      // cout << "popping" << endl;
      if (L.size() + R.size() <= 2) break;
      if (L.empty()) reshape(L, R);
      if (!L.empty()) L.pop();
    }
  }

  for (int i = 0; i < n; i++)
    if (v[i] == s) ans = 1;

  cout << (ans == INF ? -1 : ans) << endl;
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

