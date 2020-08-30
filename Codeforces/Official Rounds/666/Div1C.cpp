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
int n, r1, r2, r3, d;
int v[1123456];
int dp[1123456][2];

int solve(int i, bool last_alive) {
  if (i == n - 1) {
    int ans = INF;

    // op1 = kill boss AMP
    if (last_alive) {
      ans = min(ans, v[i] * r1 + r3 + d + r1);
    } else {
      ans = min(ans, v[i] * r1 + r3);
    }

    // op2 = kill + boss kill pistol
    if (last_alive) {
      ans = min(ans, v[i] * r1 + r1 + d + r1 + d + r1);
    } else {
      ans = min(ans, v[i] * r1 + r1 + d + d + r1);
    }

    // op3 = kill + boss shoot laser
    if (last_alive) {
      ans = min(ans, r2 + d + r1 + d + r1);
    } else {
      ans = min(ans, r2 + d + d + r1);
    }

    return ans;
  }

  if (dp[i][last_alive] != -1) return dp[i][last_alive];

  int &ans = dp[i][last_alive];
  ans = INF;

  // opt1 = kill all + boss with AMP
  if (last_alive) {
    ans = min(ans, v[i] * r1 + r3 + d + r1 + d + solve(i + 1, false) + d);
  } else {
    ans = min(ans, v[i] * r1 + r3 + solve(i + 1, false) + d);
  }

  // opt2 = kill all + shoot boss with pistol
  if (last_alive) {
    ans = min(ans, v[i] * r1 + r1 + d + r1 + d + r1 + solve(i + 1, false) + d);
  } else {
    ans = min(ans, v[i] * r1 + r1 + solve(i + 1, true) + d);
  }

  // opt3 = shoot boss with laser
  if (last_alive) {
    ans = min(ans, r2 + d + r1 + d + r1 + solve(i + 1, false) + d);
  } else {
    ans = min(ans, r2 + solve(i + 1, true) + d);
  }

  // cout << "dp[" << i << "][" << last_alive << "] = " << ans << endl;
  return ans;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  rep(i, 0, n, 1) cin >> v[i];

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0) << endl;
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

