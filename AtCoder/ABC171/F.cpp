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

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

namespace Combinatorics {
vector<int> fat;
vector<int> ifat;

void precalculate(int n) {
  fat.resize(n + 1, 1);
  ifat.resize(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    fat[i] = mod(fat[i - 1] * i);
    ifat[i] = exp(fat[i], M - 2);
  }
}

int C(int n, int k) { return mod(mod(fat[n] * ifat[n - k]) * ifat[k]); }
}  // namespace Combinatorics

// #define MULTIPLE_TEST_CASE
void solution() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int ans = 0;
  int n = s.size() + k;
  int sz = s.size();
  Combinatorics::precalculate(n);
  for (int i = 0; i < sz; i++) {
    int tot = mod(Combinatorics::C(n, i) * exp(25, n - i));
    ans = mod(ans + tot);
  }
  cout << mod(exp(26, n) - ans) << endl;
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

