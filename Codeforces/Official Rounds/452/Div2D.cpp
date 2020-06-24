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
void solution() {
  int n;
  cin >> n;
  int s = n + n - 1;

  if (n < 5) {
    cout << (n * (n - 1)) / 2 << endl;
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (exp(10, i) - 1 == s) {
      cout << 1 << endl;
      return;
    }
  }

  int dg = 0;
  int ax = s;
  while (ax >= 1) {
    dg++;
    ax /= 10;
  }

  int nines = (dg - 1 >= 0 ? exp(10, dg - 1) - 1 : 0);
  int ten = exp(10, dg - 1);
  // cout << nines << " " << ten << endl;

  int ans = 0;
  for (int digit = 0; digit < 9; digit++) {
    int num = nines + ten * digit;
    // cout << num << endl;
    if (num <= n + 1)
      ans += num / 2;
    else if (num <= s)
      ans += 1 + (n + (n - 1) - num) / 2;
  }

  cout << ans << endl;
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

