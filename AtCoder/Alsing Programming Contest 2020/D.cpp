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

//#define MULTIPLE_TEST_CASE
map<int, int> dp;
map<ii, int> pot2;

void precalc(string s, int digits, int n) {
  for (int m = max(digits - 1, 1LL); m <= digits + 1; m++) {
    int ans = 0;
    pot2[ii(0, m)] = 1;
    for (int i = 1; i <= n; i++) {
      pot2[ii(i, m)] = (pot2[ii(i - 1, m)] * 2) % m;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') ans = (ans + pot2[ii(i, m)]) % m;
    }
    dp[m] = ans;
  }
}

int firstSolve(string s, int digits, int i, int n) {
  if (s[i] == '0') {
    return mod(dp[digits + 1] + pot2[ii(i, digits + 1)], digits + 1);
  } else {
    if (digits - 1 == 0) return -1;
    return mod(dp[digits - 1] - pot2[ii(i, digits - 1)], digits - 1);
  }
}

int cntBits(int n) {
  int ans = 0;
  for (int i = 0; i < 25; i++) {
    if (n & (1 << i)) ans++;
  }
  return ans;
}

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int digits = 0;
  for (char c : s)
    if (c == '1') digits++;

  precalc(s, digits, n);

  for (int i = n - 1; i >= 0; i--) {
    // change s[i]

    int ans = 0;
    int cur = firstSolve(s, digits, i, n);
    ans++;
    if (cur == -1) {
      cur = 0;
      ans--;
    }

    while (cur > 0) {
      cur %= cntBits(cur);
      ans++;
    }

    cout << ans << endl;
  }
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

