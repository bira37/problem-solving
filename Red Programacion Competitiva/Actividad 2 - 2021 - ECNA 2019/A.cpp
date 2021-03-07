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
// #define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

int dist(ii x, ii y) { return abs(x.ff - y.ff) * abs(x.ff - y.ff) + abs(x.ss - y.ss) * abs(x.ss - y.ss); }

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, m, p;
  cin >> n >> m >> p;
  vector<bool> vjudge(n, 0);
  vector<bool> vtar(m, 0);
  vector<bool> vstore(p, 0);
  vii judge(n);
  vii tar(m);
  vii store(p);
  for (ii& p : judge) cin >> p.ff >> p.ss;
  for (ii& p : tar) cin >> p.ff >> p.ss;
  for (ii& p : store) cin >> p.ff >> p.ss;

  vii pairs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pairs.pb(ii(i, j));
    }
  }

  sort(all(pairs), [&](const ii a, const ii b) {
    int da = dist(judge[a.ff], tar[a.ss]);
    int db = dist(judge[b.ff], tar[b.ss]);
    if (da != db) return da < db;
    return a.ff < b.ff;
  });

  double ans = 0;
  for (ii x : pairs) {
    if (vjudge[x.ff] || vtar[x.ss]) continue;
    ans += sqrt(dist(judge[x.ff], tar[x.ss]));
    vjudge[x.ff] = 1;
    vtar[x.ss] = 1;
  }

  pairs.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      pairs.pb(ii(i, j));
    }
  }

  vjudge = vector<bool>(n, 0);

  sort(all(pairs), [&](const ii a, const ii b) {
    int da = dist(judge[a.ff], store[a.ss]);
    int db = dist(judge[b.ff], store[b.ss]);
    if (da != db) return da < db;
    return a.ff < b.ff;
  });

  for (ii x : pairs) {
    if (vjudge[x.ff] || vstore[x.ss]) continue;
    ans += sqrt(dist(judge[x.ff], store[x.ss]));
    vjudge[x.ff] = 1;
    vstore[x.ss] = 1;
  }

  cout << fixed << setprecision(9) << ans << endl;
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
