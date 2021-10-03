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
// #define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */
int pos[2][3123456];
void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n;
  cin >> n;
  int v[n + 1];
  vi vx(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> v[i];

  int ans = 0;
  for (int b = 22; b >= 0; b--) {
    // cout << "b = " << b << endl;
    for (int i = 0; i < 3123456; i++) {
      pos[0][i] = pos[1][i] = -1;
    }

    // cout << "solving for " << b << endl;
    int px[n + 1];
    px[0] = 0;
    pos[0][0] = 0;
    int minl = 0;
    for (int r = 1; r <= n; r++) {
      px[r] = px[r - 1] ^ vx[r];
      if (((1 << b) & v[r]) == 0) {
        minl = r;
        pos[r % 2][px[r]] = r;
        continue;
      }
      // cout << "r = " << r << " " << px[r] << endl;
      if (pos[r % 2][px[r]] >= minl) {
        // cout << pos[r % 2][px[r]] << "-----" << r << endl;
        ans = max(ans, r - pos[r % 2][px[r]]);
      }
      if (pos[r % 2][px[r]] < minl) pos[r % 2][px[r]] = r;
    }
    for (int i = 1; i <= n; i++) {
      vx[i] |= ((1 << b) & v[i]);
    }
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
