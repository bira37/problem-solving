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

int uf[312345], sz[312345];

void init(int n) {
  for (int i = 0; i <= n; i++) uf[i] = i, sz[i] = 1;
}

int get(int a) {
  if (a == uf[a]) return a;
  return uf[a] = get(uf[a]);
}

bool merge(int a, int b) {
  a = get(a), b = get(b);
  if (a == b) return 0;
  if (sz[a] < sz[b]) swap(a, b);
  uf[b] = a;
  sz[a] += sz[b];
  return 1;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n, m, q;
  cin >> n >> m >> q;
  init(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
  }
  vector<string> ans;
  vector<tuple<string, int, int>> qs(q);
  for (int i = 0; i < q; i++) {
    cin >> get<0>(qs[i]) >> get<1>(qs[i]) >> get<2>(qs[i]);
  }
  reverse(all(qs));
  for (auto q : qs) {
    string s;
    int a, b;
    tie(s, a, b) = q;
    if (s == "cut") {
      merge(a, b);
    } else {
      ans.pb((get(a) == get(b)) ? "YES" : "NO");
    }
  }
  reverse(all(ans));
  for (string s : ans) cout << s << endl;
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

