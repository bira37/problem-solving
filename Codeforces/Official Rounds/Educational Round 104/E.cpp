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
#define INF 1e15
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
  int n[4];
  for (int i = 0; i < 4; i++) cin >> n[i];
  vi a[4];
  vi ans[4];
  set<ii> s[4];
  vector<vi> conn[4];
  for (int i = 0; i < 4; i++) {
    a[i].resize(n[i]);
    ans[i].resize(n[i], INF);
    conn[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
      if (i == 0) ans[i][j] = a[i][j], s[i].insert(ii(ans[i][j], j));
    }
  }

  for (int i = 1; i < 4; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      conn[i][b].pb(a);
    }
  }

  for (int i = 1; i < 4; i++) {
    // get best ans from i using i-1

    for (int j = 0; j < n[i]; j++) {
      // remove from s[i-1]
      for (int x : conn[i][j]) {
        s[i - 1].erase(ii(ans[i - 1][x], x));
      }

      // pick min
      if (s[i - 1].size() > 0)
        ans[i][j] = a[i][j] + s[i - 1].begin()->ff;
      else
        ans[i][j] = INF;

      // insert again
      for (int x : conn[i][j]) {
        s[i - 1].insert(ii(ans[i - 1][x], x));
      }
    }

    for (int j = 0; j < n[i]; j++) {
      s[i].insert(ii(ans[i][j], j));
    }
  }

  int res = INF;
  for (int i = 0; i < n[3]; i++) res = min(res, ans[3][i]);
  cout << (res >= INF ? -1 : res) << endl;
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

