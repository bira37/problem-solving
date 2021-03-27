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

int submit(vi& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << (i != 0 ? " " : "") << v[i];
  }
  cout << endl << flush;

  int verdict;
  cin >> verdict;
  return verdict;
}

map<vector<int>, int> cache;
int asks = 0;

int ask(int a, int b, int c) {
  vi v;
  asks++;
  v.pb(a);
  v.pb(b);
  v.pb(c);
  sort(all(v));
  if (cache.count(v)) return cache[v];
  cout << a << " " << b << " " << c;
  cout << endl << flush;

  int verdict;
  cin >> verdict;
  cache[v] = verdict;
  return verdict;
}

vi solve(vi v) {
  if (v.size() <= 2) return v;
  vi lef, rig, mid;

  // shufle every level
  // shuffle(all(v), rng);
  int n = v.size();
  // rig.pb(v[n - 1]);
  for (int i = 1; i < n - 1; i++) {
    int ans = ask(v[0], v[i], v[n - 1]);
    assert(ans != -1);

    if (ans == v[i]) {
      mid.pb(v[i]);
    } else if (ans == v[0]) {
      lef.pb(v[i]);
    } else
      rig.pb(v[i]);
  }

  // lef.pb(v[0]);

  lef = solve(lef);
  mid = solve(mid);
  rig = solve(rig);

  if (lef.size() >= 2) {
    int ans = ask(lef[0], lef[1], v[0]);
    if (ans == lef[0]) reverse(all(lef));
  }

  lef.pb(v[0]);

  if (rig.size() >= 2) {
    int ans = ask(v[n - 1], rig[0], rig[1]);
    if (ans == rig[1]) reverse(all(rig));
  }

  reverse(all(rig));
  rig.pb(v[n - 1]);
  reverse(all(rig));

  // fix mid using lef
  if (mid.size() >= 2 && lef.size() > 0) {
    int ans = ask(lef[0], mid[0], mid[1]);
    if (ans == mid[1]) reverse(all(mid));
  }

  // fix rig using lef
  // if (rig.size() >= 2) {
  //   int ans = ask(lef[0], rig[0], rig[1]);
  //   if (ans == rig[1]) reverse(all(rig));
  // }

  v.clear();
  for (int x : lef) v.pb(x);
  for (int x : mid) v.pb(x);
  for (int x : rig) v.pb(x);

  return v;
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int t, n, q;
  cin >> t >> n >> q;
  asks = 0;
  int tt = t;
  while (t--) {
    // start
    cache.clear();
    vi v(n);
    iota(all(v), 1);
    v = solve(v);
    assert(submit(v) == 1);
  }
  assert(asks <= q);
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
