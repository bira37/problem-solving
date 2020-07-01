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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

int M = 1000000007;

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
  int n, p;
  cin >> n >> p;
  M = p;
  vector<int> a(n);
  rep(i, 0, n, 1) { cin >> a[i]; }
  sort(all(a));
  int l = 0, r = 2e9;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;

    int candy = m;
    bool ok = true;
    for (int x : a) {
      if (candy >= x) {
        candy++;
      } else {
        ok = false;
      }
    }

    if (ok) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  vector<int> vals;

  l = 0, r = 2e9;
  int ansr = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int current = 0;
    int candy = m;
    vector<int> v;
    bool ok = true;
    for (int x : a) v.pb(x);
    reverse(all(v));
    for (int i = 0; i < n; i++) {
      while (v.size() > 0 && v.back() <= candy) {
        v.pop_back();
        current++;
      }
      if (current >= p) ok = false;
      current--;
      candy++;
    }
    if (ok) {
      ansr = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  if (ans != -1) {
    for (int i = ans; i <= ansr; i++) vals.pb(i);
  }

  cout << vals.size() << endl;
  for (int x : vals) cout << x << " ";
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

