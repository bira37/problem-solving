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
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v) cin >> x;

  vector<vi> buc;
  vector<ii> idx;
  vi current;
  int ini = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      if (current.size() > 0) {
        buc.push_back(current);
        idx.pb(ii(ini, (n - 1) - (i - 1)));
      }
      current.clear();
      ini = i + 1;
    } else {
      current.pb(v[i]);
    }
  }
  if (current.size() > 0) {
    buc.push_back(current);
    idx.pb(ii(ini, 0));
  }

  int max_ans = -1;
  ii ans;
  for (int i = 0; i < buc.size(); i++) {
    vi v = buc[i];
    // cout << v.size() << " " << idx[i].ff << " " << idx[i].ss << endl;

    int negs = 0;
    int twos = 0;
    for (int x : v) {
      if (x < 0) negs++;
      if (abs(x) == 2) twos++;
    }

    if (negs % 2 == 0) {
      if (max_ans < twos) {
        ans = idx[i];
        max_ans = twos;
      }
      continue;
    }

    int pref = 0;
    int pref_deleted = 0;
    for (int x : v) {
      pref_deleted++;
      if (abs(x) == 2) pref++;
      if (x <= 0) {
        break;
      }
    }

    reverse(all(v));
    int suf = 0;
    int suf_deleted = 0;
    for (int x : v) {
      suf_deleted++;
      if (abs(x) == 2) suf++;
      if (x <= 0) {
        break;
      }
    }

    if (pref <= suf) {
      if (max_ans <= twos - pref) {
        ans = ii(idx[i].ff + pref_deleted, idx[i].ss);
        max_ans = twos - pref;
      }
    } else {
      if (max_ans <= twos - suf) {
        ans = ii(idx[i].ff, idx[i].ss + suf_deleted);
        max_ans = twos - suf;
      }
    }
  }

  if (buc.size() == 0) {
    ans = ii(v.size(), 0);
  }
  cout << ans.ff << " " << ans.ss << endl;
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
