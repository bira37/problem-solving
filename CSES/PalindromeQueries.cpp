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

int B1, B2, M1, M2;
vector<ii> base;

pair<ii, ii> st[4 * 212345];
string s, rs;

pair<ii, ii> combine(pair<ii, ii> a, pair<ii, ii> b, int lena) {
  ii hash, rev;

  hash.ff = mod(a.ff.ff + b.ff.ff * base[lena].ff, M1);
  hash.ss = mod(a.ff.ss + b.ff.ss * base[lena].ss, M2);

  rev.ff = mod(a.ss.ff + b.ss.ff * base[lena].ff, M1);
  rev.ss = mod(a.ss.ss + b.ss.ss * base[lena].ss, M2);

  return pair<ii, ii>(hash, rev);
}

pair<ii, ii> get(int cur, int l, int r, int a, int b) {
  if (l == a && r == b) {
    return st[cur];
  }
  int m = (l + r) >> 1;
  if (b <= m)
    return get(2 * cur, l, m, a, b);
  else if (m < a)
    return get(2 * cur + 1, m + 1, r, a, b);
  else {
    auto lef = get(2 * cur, l, m, a, m);
    auto rig = get(2 * cur + 1, m + 1, r, m + 1, b);
    return combine(lef, rig, m - a + 1);
  }
}

void update(int cur, int l, int r, int x, char c, int t) {
  if (l == r) {
    if (t == 0) {
      st[cur].ff = ii(c - 'a', c - 'a');
    } else {
      st[cur].ss = ii(c - 'a', c - 'a');
    }
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m)
    update(2 * cur, l, m, x, c, t);
  else
    update(2 * cur + 1, m + 1, r, x, c, t);
  st[cur] = combine(st[2 * cur], st[2 * cur + 1], m - l + 1);
}

void build(int cur, int l, int r) {
  if (l == r) {
    int v = s[l] - 'a';
    int rv = rs[l] - 'a';
    st[cur] = pair<ii, ii>(ii(v, v), ii(rv, rv));
    return;
  }
  int m = (l + r) >> 1;
  build(2 * cur, l, m);
  build(2 * cur + 1, m + 1, r);
  st[cur] = combine(st[2 * cur], st[2 * cur + 1], m - l + 1);
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  B1 = rng() % 65535;
  B2 = rng() % 65535;
  M1 = 1000000007;
  M2 = 1000000009;
  int n, q;
  cin >> n >> q;
  cin >> s;
  rs = s;
  reverse(all(rs));
  base.resize(n + 1);
  base[0] = ii(1, 1);
  for (int i = 1; i <= n; i++)
    base[i] = ii(mod(base[i - 1].ff * B1, M1), mod(base[i - 1].ss * B2, M2));

  build(1, 0, n - 1);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      update(1, 0, n - 1, x, c, 0);
      update(1, 0, n - 1, n - 1 - x, c, 1);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int rr = n - 1 - l;
      int rl = n - 1 - r;
      if (get(1, 0, n - 1, l, r).ff == get(1, 0, n - 1, rl, rr).ss) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
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
