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
#include "../cp-lib/codes/math_nt/binomial_fac.cpp"
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
  int n;
  cin >> n;
  int v[n];
  int s = 0;
  for (int i = 0; i < n; i++) cin >> v[i], s += v[i];

  if (s % n != 0) {
    cout << 0 << endl;
    return;
  }

  int add = 0, rem = 0;
  for (int i = 0; i < n; i++) {
    v[i] -= s / n;
    if (v[i] > 0)
      rem++;
    else if (v[i] < 0)
      add++;
  }

  if (max(add, rem) == 0) {
    cout << 1 << endl;
    return;
  }

  // corner case: all permutations without repetition
  if (add == 1 || rem == 1) {
    int ans = NT::fat[n];
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[v[i]]++;
    }
    for (ii p : cnt) {
      ans = mod(ans * NT::ifat[p.ss]);
    }
    cout << ans << endl;
    return;
  }

  // general case: divide all rem and add into two parts and merge with zeros
  int addans = NT::fat[add];
  int remans = NT::fat[rem];
  int zeroans = add + rem == n ? 1 : NT::C(n, n - add - rem);

  cout << addans << " " << remans << " " << endl;

  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) continue;
    cnt[v[i]]++;
  }

  for (ii p : cnt) {
    if (p.ff > 0) {
      remans = mod(remans * NT::ifat[p.ss]);
    } else if (p.ff < 0) {
      addans = mod(addans * NT::ifat[p.ss]);
    }
  }

  int ans = mod(zeroans * mod(addans * mod(2LL * remans)));

  cout << ans << endl;
}

#ifdef FILE_INPUT
freopen("equal.in", "r", stdin);
freopen("equal.out", "w", stdout);
#endif

int32_t main() {
  DESYNC;
  int t = 1;
  NT::precalculate(100005);
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++) solution(_testcase);
}
