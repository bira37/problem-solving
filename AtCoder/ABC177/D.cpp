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

int uf[212345], sz[212345];

int find(int u) {
  if (uf[u] == u)
    return u;
  else
    return uf[u] = find(uf[u]);
}

bool merge(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return false;
  if (sz[a] < sz[b]) swap(a, b);
  uf[b] = a;
  sz[a] += sz[b];
  return true;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  rep(i, 0, n + 1, 1) {
    uf[i] = i;
    sz[i] = 1;
  }
  rep(i, 0, m, 1) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }
  int ans = 0;
  rep(i, 1, n + 1, 1) { ans = max(ans, sz[find(i)]); }
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
