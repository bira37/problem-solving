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
#define MULTIPLE_TEST_CASE
void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  int fl = k / n;
  for (int i = 0; i < n; i++) r[i] = fl + (i < (k % n));
  int ans[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) ans[i][j] = 0;
  }
  set<ii> cols;
  for (int i = 0; i < n; i++) cols.insert(ii(0, i));
  for (int i = 0; i < n; i++) {
    while (r[i] > 0) {
      ii cur = *cols.begin();
      cols.erase(cols.begin());
      ans[i][cur.ss] = 1;
      cols.insert(ii(cur.ff + 1, cur.ss));
      r[i]--;
    }
  }
  int rmin = INF, rmax = -INF, cmin = INF, cmax = -INF;
  for (int i = 0; i < n; i++) {
    int acc = 0;
    for (int j = 0; j < n; j++) acc += ans[i][j];
    rmin = min(rmin, acc);
    rmax = max(rmax, acc);
  }
  for (int j = 0; j < n; j++) {
    int acc = 0;
    for (int i = 0; i < n; i++) acc += ans[i][j];
    cmin = min(cmin, acc);
    cmax = max(cmax, acc);
  }
  cout << (rmax - rmin) * (rmax - rmin) + (cmax - cmin) * (cmax - cmin) << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j];
    cout << endl;
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

