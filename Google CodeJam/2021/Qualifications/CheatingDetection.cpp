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
#define PRINT_TEST_CASE
#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

string s[101];

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n = 100;
  int m = 10000;
  vi cnt(m);

  vi points(n);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') cnt[j]++, points[i]++;
    }
  }

  vi qs(m);
  iota(all(qs), 0);

  vi us(n);
  iota(all(us), 0);

  sort(all(qs), [&](const int a, const int b) {
    return cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b;
  });

  sort(all(us), [&](const int a, const int b) {
    return points[a] < points[b] || points[a] == points[b] && a < b;
  });

  vi coeff(n, 0);

  vector<pair<double, int>> suspicious(n, ii(0, 0));
  for (int i = 0; i < n; i++) {
    int lst = -1;
    suspicious[us[i]] = ii(0, us[i]);
    int cur = 0;
    for (int j = 0; j < m; j++) {
      if (s[us[i]][qs[j]] == '1') {
        if (j > 0 && s[us[i]][qs[j - 1]] == '0') coeff[us[i]]++;
        cur++;
      }
      if (j != 0 && j % 500 == 0) {
        if (lst != -1) suspicious[us[i]].ff += (lst - cur);
        lst = cur;
        cur = 0;
      }
    }
  }

  vii votes(n);
  for (int i = 0; i < n; i++) {
    votes[i] = ii(0, i);
  }

  for (int i = 0; i < n; i++) {
    vector<pair<double, int>> ord;
    for (int j = i; j < i + 10 && j < n; j++) {
      ord.pb(suspicious[us[j]]);
    }
    sort(all(ord));
    votes[ord[0].ss].ff++;
    // cout << "voting for " << ord[0].ss + 1 << endl;
  }

  sort(all(votes), [&](const ii x, const ii y) {
    return x.ff * coeff[x.ss] * points[x.ss] >
           y.ff * coeff[y.ss] * points[y.ss];
    // return x.ff > y.ff || (x.ff == y.ff && coeff[x.ss] > coeff[y.ss]) ||
    //        (x.ff == y.ff && coeff[x.ss] == coeff[y.ss] &&
    //         points[x.ss] > points[y.ss]);
  });
  // for (int i = 0; i < n; i++) {
  //   cout << votes[i].ss + 1 << " = " << votes[i].ff << " | "
  //        << points[votes[i].ss] << " | " << coeff[votes[i].ss] << endl;
  // }
  cout << votes.front().ss + 1 << endl;
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
  int p;
  cin >> p;
  for (int _testcase = 1; _testcase <= t; _testcase++) solution(_testcase);
}
