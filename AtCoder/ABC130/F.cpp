#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<double, double>
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

double solve(vector<ii> p, vector<char> d, double x) {
  double mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
  int i = -1;
  for (ii cur : p) {
    i++;
    if (d[i] == 'L')
      cur.ff -= x;
    else if (d[i] == 'R')
      cur.ff += x;
    else if (d[i] == 'U')
      cur.ss += x;
    else
      cur.ss -= x;
    mnx = min(mnx, cur.ff);
    mxx = max(mxx, cur.ff);
    mny = min(mny, cur.ss);
    mxy = max(mxy, cur.ss);
  }
  return (mxx - mnx) * (mxy - mny);
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n;
  vector<ii> p;
  cin >> n;
  vector<char> d(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.pb(ii(x, y));
    cin >> d[i];
  }
  double l = 0, r = 2e8;
  for (int it = 0; it < 100; it++) {
    double m1 = l + (r - l) / 3.;
    double m2 = r - (r - l) / 3.;

    double fa = solve(p, d, m1);
    double fb = solve(p, d, m2);

    if (fa < fb) {
      r = m2;
    } else if (fa > fb) {
      l = m1;
    } else {
      l = m1;
      r = m2;
    }
  }
  cout << fixed << setprecision(10) << solve(p, d, l) << endl;
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

