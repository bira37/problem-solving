#include <bits/stdc++.h>

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
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

namespace NT {

const int MAX_N = 1123456;

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
  for (int i = 2; i <= n; i++)
    if (prime[i]) primes.pb(i);
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
  int n;
  cin >> n;
  NT::Sieve(1000000);
  int v[n];
  rep(i, 0, n, 1) cin >> v[i];
  int all_g = v[0];
  set<int> s;
  bool pair = true;
  rep(i, 0, n, 1) {
    all_g = gcd(all_g, v[i]);
    int x = v[i];

    vector<int> fac;
    while (x != 1) {
      if (pair == false) break;
      if (s.count(NT::lf[x])) pair = false;
      fac.pb(NT::lf[x]);
      x /= NT::lf[x];
    }
    for (int x : fac) s.insert(x);
  }
  if (pair)
    cout << "pairwise coprime" << endl;
  else if (all_g == 1)
    cout << "setwise coprime" << endl;
  else
    cout << "not coprime" << endl;
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
