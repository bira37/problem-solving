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
int reversort(vector<int> v) {
  int n = v.size();
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int id = i;
    for (int j = i; j < n; j++) {
      if (v[id] > v[j]) id = j;
    }
    // cout << i << " " << id << endl;
    ans += (id - i + 1);
    reverse(v.begin() + i, v.begin() + id + 1);
  }
  return ans;
}

/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
#define PRINT_TEST_CASE
#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */
int n;

int dp[101][101][1001];
ii bk[101][101][1001];
tuple<int, int, int> nxt[101][101][1001];

bool go(int i, int j, int c) {
  if (i == j) {
    if (i == n - 1)
      return c == 0;
    else
      return c == 1;
  }

  if (dp[i][j][c] != -1) {
    return dp[i][j][c];
  }

  // skip guy
  if (go(i + 1, j, c - 1)) {
    dp[i][j][c] = true;
    bk[i][j][c] = ii(i, i);
    nxt[i][j][c] = mt(i + 1, j, c - 1);
    return true;
  }

  for (int k = i + 1; k <= j; k++) {
    if (go(i + 1, k, c - (k - i + 1)) == 1) {
      dp[i][j][c] = true;
      nxt[i][j][c] = mt(i + 1, k, c - (k - i + 1));
      bk[i][j][c] = ii(i, k);
      return true;
    }
  }

  dp[i][j][c] = 0;
  return 0;
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ":";
#endif
  // Code starts here
  int x;
  cin >> n >> x;
  vi v(n);
  iota(all(v), 1);
  int mx = 0;

  if (x > (n * (n + 1)) / 2 - 1 || x < n - 1) {
    cout << " IMPOSSIBLE" << endl;
    return;
  }

  memset(dp, -1, sizeof dp);

  if (go(0, n - 1, x) == 1) {
    int i = 0, j = n - 1, c = x;
    vector<ii> revs;
    while (true) {
      if (i == j) break;
      // cout << bk[i][j][c].ff << " " << bk[i][j][c].ss << endl;
      revs.pb(ii(bk[i][j][c].ff, bk[i][j][c].ss));
      // reverse(v.begin() + bk[i][j][c].ff, v.begin() + bk[i][j][c].ss + 1);
      auto tp = nxt[i][j][c];
      i = get<0>(tp);
      j = get<1>(tp);
      c = get<2>(tp);
    }
    reverse(all(revs));
    for (ii x : revs) reverse(v.begin() + x.ff, v.begin() + x.ss + 1);
    for (int x : v) cout << " " << x;
    cout << endl;
    // cout << reversort(v) << endl;
  } else {
    cout << " IMPOSSIBLE" << endl;
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
