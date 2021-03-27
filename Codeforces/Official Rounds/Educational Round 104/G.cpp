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
// const int M = 1000000007;
const int M = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int mod(int n, int m = M) {
  int ret = n;
  while (ret >= m) ret -= m;
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
int cnt[404][26][26];
int one[404][404][2][2];     // [0 - neq | 1 - eq]
int two[2][404][404][3][3];  // [0 - neq | 1 - eq1 | 2 - eq2]

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n;
  cin >> n;
  int c[26];
  for (int i = 0; i < 26; i++) {
    cin >> c[i];
  }

  // calculate without violation
  memset(cnt, 0, sizeof cnt);
  cnt[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int a = 0; a < 26; a++) {
      for (int b = 0; b < 26; b++) {
        for (int c = 0; c < 26; c++) {
          if (i >= 2 && c == a) continue;
          cnt[i + 1][b][c] = mod(cnt[i + 1][b][c] + cnt[i][a][b]);
        }
      }
    }
  }

  // calculate violation of one
  memset(one, 0, sizeof one);
  one[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          if (a == 0) {
            one[i + 1][j + 1][b][1] = mod(one[i + 1][j + 1][b][1] + one[i][j][a][b]);
            one[i + 1][j][b][0] = mod(one[i + 1][j][b][0] + one[i][j][a][b] * (24 + (i < 2)));
          } else {
            one[i + 1][j][b][0] = mod(one[i + 1][j][b][0] + 25 * one[i][j][a][b]);
          }
        }
      }
    }
  }

  memset(two, 0, sizeof two);
  two[0][0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int idx = i % 2;
    memset(two[1 - idx], 0, sizeof two[1 - idx]);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int a = 0; a < 3; a++) {
          for (int b = 0; b < 3; b++) {
            if (a == 0) {
              two[1 - idx][j][k][b][0] = mod(two[1 - idx][j][k][b][0] + two[idx][j][k][a][b] * (23 + (i < 2)));
              two[1 - idx][j + 1][k][b][1] = mod(two[1 - idx][j + 1][k][b][1] + two[idx][j][k][a][b]);
              two[1 - idx][j][k + 1][b][2] = mod(two[1 - idx][j][k + 1][b][2] + two[idx][j][k][a][b]);
            } else if (a == 1) {
              two[1 - idx][j][k][b][0] = mod(two[1 - idx][j][k][b][0] + two[idx][j][k][a][b] * 24);
              two[1 - idx][j][k + 1][b][2] = mod(two[1 - idx][j][k + 1][b][2] + two[idx][j][k][a][b]);
            } else if (a == 2) {
              two[1 - idx][j][k][b][0] = mod(two[1 - idx][j][k][b][0] + two[idx][j][k][a][b] * 24);
              two[1 - idx][j + 1][k][b][1] = mod(two[1 - idx][j + 1][k][b][1] + two[idx][j][k][a][b]);
            }
          }
        }
      }
    }
  }

  // accumulate
  int ans = 0;
  for (int a = 0; a < 26; a++) {
    // add all
    for (int b = 0; b < 26; b++) {
      ans = mod(ans + cnt[n][a][b]);
    }

    // subtract from one
    for (int k = c[a] + 1; k <= n; k++) {
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          ans = mod(ans - one[n][k][x][y]);
        }
      }
    }

    // add from two
    for (int b = a + 1; b < 26; b++) {
      for (int ca = c[a] + 1; ca <= n; ca++) {
        for (int cb = c[b] + 1; cb <= n; cb++) {
          for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
              ans = mod(ans + two[n % 2][ca][cb][x][y]);
            }
          }
        }
      }
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
