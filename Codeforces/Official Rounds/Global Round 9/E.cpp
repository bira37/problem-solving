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
int cnt[2];
vector<int> g[212345];
void go(int u, int p = -1, int wtf = 0) {
  cnt[wtf]++;
  for (int v : g[u]) {
    if (v == p) continue;
    go(v, u, wtf ^ 1);
  }
}
//#define MULTIPLE_TEST_CASE
void solution() {
  int n;
  cin >> n;
  int v[n];
  rep(i, 0, n, 1) { cin >> v[i]; }
  int w[n];
  rep(i, 0, n, 1) w[i] = i;
  sort(w, w + n, [&](const int x, const int y) {
    return v[x] < v[y] || (v[x] == v[y] && x < y);
  });
  vector<ii> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (w[j] > w[j + 1]) {
        ans.pb(ii(w[j + 1], w[j]));
        swap(w[j + 1], w[j]);
      }
    }
  }
  cout << ans.size() << endl;
  for (ii x : ans) cout << x.ff + 1 << " " << x.ss + 1 << endl;
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

