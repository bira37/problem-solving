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
/* Author: Ubiratan Correia Barbosa Neto
 * Erasthostenes Sieve Implementation + Euler's Totient
 */

/* Calculate primes from 2 to N */
/* lf[i] stores the lowest prime factor of i(logn factorization) */

namespace NT {

const int MAX_SIEVE = 1123456;

bitset<MAX_SIEVE> prime;
vector<int> primes;
vector<int> seg_primes;
int lf[MAX_SIEVE];
int totient[MAX_SIEVE];

void Sieve(int n) {
  for (int i = 0; i <= n; i++) lf[i] = i;
  prime.set();
  prime[0] = false;
  prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
        lf[i] = min(lf[i], p);
      }
    }
  }
  for (int i = 2; i <= n; i++)
    if (prime[i]) primes.pb(i);
}

void SegmentedSieve(int l, int r) {
  prime.set();
  seg_primes.clear();
  for (int p : primes) {
    int start = l - l % p - p;
    while (start < l) start += p;
    if (p == start) start += p;
    for (int i = start; i <= r; i += p) {
      prime[i - l] = false;
    }
  }
  for (int i = 0; i < r - l + 1; i++) {
    if (prime[i] && l + i > 1) {
      seg_primes.pb(l + i);
    }
  }
}

void EulerTotient(int n) {
  for (int i = 0; i <= n; i++) totient[i] = i;
  for (int p = 2; p <= n; p++) {
    if (totient[p] == p) {
      totient[p] = p - 1;
      for (int i = p + p; i <= n; i += p) {
        totient[i] = (totient[i] / p) * (p - 1);
      }
    }
  }
}

int SingleTotient(int x) {
  int ans = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      ans -= ans / i;
    }
  }
  if (x > 1) ans -= ans / x;
  return ans;
}

};  // namespace NT
/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
// #define PRINT_TEST_CASE
// #define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, q;
  NT::Sieve(212345);
  cin >> n >> q;
  map<int, int> pots[n];

  map<int, multiset<int>> all;
  int g = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (g == -1)
      g = x;
    else
      g = gcd(g, x);
    while (x > 1) {
      pots[i][NT::lf[x]]++;
      x /= NT::lf[x];
    }
    for (auto p : pots[i]) {
      all[p.ff].insert(p.ss);
    }
  }

  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;

    set<int> not_changed;
    set<int> changes;

    // pega
    int nx = x;
    while (nx > 1) {
      changes.insert(NT::lf[nx]);
      nx /= NT::lf[nx];
    }

    for (int x : changes) {
      if (all[x].count(pots[i][x])) {
        if (pots[i][x] == *all[x].begin()) {
          if (all[x].size() == n) {
            int val = exp(x, *all[x].begin());
            g = mod(g * exp(val, M - 2));
          }
        } else {
          not_changed.insert(x);
        }
        all[x].erase(all[x].find(pots[i][x]));
      }
    }

    // altera
    while (x > 1) {
      changes.insert(NT::lf[x]);
      pots[i][NT::lf[x]]++;
      x /= NT::lf[x];
    }

    for (int x : changes) {
      all[x].insert(pots[i][x]);
      if (!not_changed.count(x) && all[x].size() == n) {
        int val = exp(x, *all[x].begin());
        g = mod(g * val);
      }
    }
    cout << g << endl;
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

