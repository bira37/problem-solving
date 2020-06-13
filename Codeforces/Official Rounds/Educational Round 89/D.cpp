#include <bits/stdc++.h>

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
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

/* Author: Ubiratan Correia Barbosa Neto
 * Erasthostenes Sieve Implementation + Euler's Totient
 */

/* Calculate primes from 2 to N */
/* lf[i] stores the lowest prime factor of i(logn factorization) */
namespace NT {

const int MAX_N = 11234567;

bitset<MAX_N> prime;
vector<int> primes;
int lf[MAX_N];
int totient[MAX_N];

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

};  // namespace NT

//#define MULTIPLE_TEST_CASE
void solution() {
  NT::Sieve(10000000);
  int n;
  cin >> n;
  vector<int> a, b;
  while (n--) {
    int x;
    cin >> x;
    vector<int> dvs;
    while (x > 1) {
      if ((dvs.size() == 0 || dvs.back() != NT::lf[x]) && NT::lf[x] != 1)
        dvs.pb(NT::lf[x]);
      x /= NT::lf[x];
    }
    if (dvs.size() < 2) {
      a.pb(-1);
      b.pb(-1);
    } else {
      a.pb(dvs[0]);
      b.pb(dvs[1]);
      for (int i = 2; i < dvs.size(); i++) b.back() *= dvs[i];
    }
  }
  for (int x : a) cout << x << " ";
  cout << endl;
  for (int x : b) cout << x << " ";
  cout << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

