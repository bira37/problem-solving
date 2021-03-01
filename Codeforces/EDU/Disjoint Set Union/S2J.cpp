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
const int M = 1000000007;
// const int M = 998244353;
using ll = long long;
using namespace std;
inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k, int m = M) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2, m);
  ax = mod(ax * ax, m);
  if (k % 2) ax = mod(ax * n, m);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int uf[312345], d[312345], sz[312345];

ii get(int x) {
  if (uf[x] == x) {
    return ii(x, 0);
  }
  ii ans = get(uf[x]);
  d[x] = d[x] + ans.ss;
  uf[x] = ans.ff;
  return ii(uf[x], d[x]);
}

bool merge(int a, int b) {
  auto x = get(a), y = get(b);
  if (x.ff == y.ff) return false;
  if (sz[x.ff] < sz[y.ff]) swap(x, y);
  uf[y.ff] = x.ff;
  sz[x.ff] += sz[y.ff];
  d[y.ff] = y.ss + x.ss + 1;
  return true;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i <= n; i++) {
    uf[i] = i;
    sz[i] = 1;
    d[i] = 0;
  }
  int ans = -1;
  for (int i = 0; i < q; i++) {
    int t, a, b;
    cin >> a >> b;
    if (ans != -1) continue;
    ii x = get(a);
    ii y = get(b);

    if (x.ff == y.ff && (x.ss % 2 == y.ss % 2)) {
      ans = i + 1;
      continue;
    }
    merge(a, b);
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

