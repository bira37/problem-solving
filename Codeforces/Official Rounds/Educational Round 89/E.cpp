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
#define M 998244353
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

int a[212345], b[212345];

map<tuple<int, int, bool>, int> dp;

int solve(int n, int m, bool f) {
  if (n == 0 || m == 0) {
    if (n == m)
      return 1;
    else
      return 0;
  }
  // wrong subarray
  if (a[n] < b[m]) return 0;
  if (dp.count(mt(n, m, f))) return dp[mt(n, m, f)];
  auto &ans = dp[mt(n, m, f)];
  ans = 0;

  f |= (a[n] == b[m]);
  // can break here
  if (f) ans = mod(ans + solve(n - 1, m - 1, false));
  // don't break
  ans = mod(ans + solve(n - 1, m, f));
  return ans;
}

// #define MULTIPLE_TEST_CASE
void solution() {
  int n, m;
  cin >> n >> m;
  rep(i, 1, n + 1, 1) cin >> a[i];
  rep(i, 1, m + 1, 1) cin >> b[i];
  cout << solve(n, m, false) << endl;
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

