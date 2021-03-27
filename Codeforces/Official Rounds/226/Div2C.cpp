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
namespace NT {

const int MAX_SIEVE = 11234567;

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
}

};  // namespace NT
/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
// #define PRINT_TEST_CASE
// #define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

int pf[11234567];
int cnt[11234567];

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  NT::Sieve(10000000);
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) cin >> v[i], cnt[v[i]]++;
  pf[0] = 0;
  for (int i = 1; i <= 10000000; i++) {
    pf[i] = pf[i - 1];
    if (!NT::prime[i]) continue;
    for (int j = i; j <= 10000000; j += i) {
      pf[i] += cnt[j];
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    b = min(b, 10000000);
    a = min(a, 10000000);
    cout << pf[b] - pf[a - 1] << endl;
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

