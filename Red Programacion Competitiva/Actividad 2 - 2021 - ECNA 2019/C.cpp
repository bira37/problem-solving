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
/**
 * I'm not the author. Just adding for simple copy-paste
 * Source:  kth-competitive-programming / kactl
 * Link:
 * https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/Simplex.h
 * Simplex slightly modified
 */
namespace LinearProgramming {
/**
 * Author: Stanford
 * Source: Stanford Notebook
 * License: MIT
 * Description: Solves a general linear maximization problem: maximize $c^T x$
 * subject to $Ax \le b$, $x \ge 0$. Returns -inf if there is no solution, inf
 * if there are arbitrarily good solutions, or the maximum value of $c^T x$
 * otherwise. The input vector is set to an optimal $x$ (or in the unbounded
 * case, an arbitrary solution fulfilling the constraints). Numerical stability
 * is not guaranteed. For better performance, define variables such that $x = 0$
 * is viable. Usage: vvd A = {{1,-1}, {-1,1}, {-1,-2}}; vd b = {1,1,-4}, c =
 * {-1,-1}, x; T val = LPSolver(A, b, c).solve(x); Time: O(NM * \#pivots), where
 * a pivot may be e.g. an edge relaxation. O(2^n) in the general case. Status:
 * seems to work?
 */

typedef double T;        // long double, Rational, double + mod<P>...
typedef vector<T> vd;    // Vector
typedef vector<vd> vvd;  // Matrix

const T eps = 1e-8, inf = 1 / .0;
#define lpsolver_ltj(X) \
  if (s == -1 || mp(X[j], N[j]) < mp(X[s], N[s])) s = j

struct LPSolver {
  int m, n;
  vi N, B;
  vvd D;

  int sz(const vd& v) { return (int)(v.size()); }

  LPSolver(const vvd& A, const vd& b, const vd& c) : m(sz(b)), n(sz(c)), N(n + 1), B(m), D(m + 2, vd(n + 2)) {
    rep(i, 0, m, 1) rep(j, 0, n, 1) D[i][j] = A[i][j];
    rep(i, 0, m, 1) {
      B[i] = n + i;
      D[i][n] = -1;
      D[i][n + 1] = b[i];
    }
    rep(j, 0, n, 1) {
      N[j] = j;
      D[m][j] = -c[j];
    }
    N[n] = -1;
    D[m + 1][n] = 1;
  }

  void pivot(int r, int s) {
    T *a = D[r].data(), inv = 1 / a[s];
    rep(i, 0, m + 2, 1) if (i != r && abs(D[i][s]) > eps) {
      T *b = D[i].data(), inv2 = b[s] * inv;
      rep(j, 0, n + 2, 1) b[j] -= a[j] * inv2;
      b[s] = a[s] * inv2;
    }
    rep(j, 0, n + 2, 1) if (j != s) D[r][j] *= inv;
    rep(i, 0, m + 2, 1) if (i != r) D[i][s] *= -inv;
    D[r][s] = inv;
    swap(B[r], N[s]);
  }

  bool simplex(int phase) {
    int x = m + phase - 1;
    for (;;) {
      int s = -1;
      rep(j, 0, n + 1, 1) if (N[j] != -phase) lpsolver_ltj(D[x]);
      if (D[x][s] >= -eps) return true;
      int r = -1;
      rep(i, 0, m, 1) {
        if (D[i][s] <= eps) continue;
        if (r == -1 || mp(D[i][n + 1] / D[i][s], B[i]) < mp(D[r][n + 1] / D[r][s], B[r])) r = i;
      }
      if (r == -1) return false;
      pivot(r, s);
    }
  }

  T solve(vd& x) {
    int r = 0;
    rep(i, 1, m, 1) if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -eps) {
      pivot(r, n);
      if (!simplex(2) || D[m + 1][n + 1] < -eps) return -inf;
      rep(i, 0, m, 1) if (B[i] == -1) {
        int s = 0;
        rep(j, 1, n + 1, 1) lpsolver_ltj(D[i]);
        pivot(i, s);
      }
    }
    bool ok = simplex(1);
    x = vd(n);
    rep(i, 0, m, 1) if (B[i] < n) x[B[i]] = D[i][n + 1];
    return ok ? D[m][n + 1] : inf;
  }
};

}  // namespace LinearProgramming

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
  int n, m;
  cin >> n >> m;

  LinearProgramming::vd c(m);
  LinearProgramming::vd b(n);
  LinearProgramming::vvd A(n, LinearProgramming::vd(m));

  for (int i = 0; i < n; i++) cin >> b[i];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[j][i];
      A[j][i] /= 100.0;
    }
    cin >> c[i];
  }
  auto ans_arr = LinearProgramming::vd();
  auto ans = LinearProgramming::LPSolver(A, b, c).solve(ans_arr);

  cout << fixed << setprecision(2) << ans << endl;
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
