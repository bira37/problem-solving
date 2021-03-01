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

int uf[212345], sz[212345];
set<int> gr[212345];
int l[212345], r[212345];

void init(int n) {
  for (int i = 0; i <= n; i++) {
    uf[i] = i, sz[i] = 1;
    gr[i].insert(i);
  }
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
  for (int x : gr[b]) gr[a].insert(x);
  gr[b].clear();
  return 1;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n, m, q;
  cin >> n >> m;
  init(n);
  multiset<ii> conf;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    if (l[i] != -1) conf.insert(ii(i, l[i]));
    if (r[i] != -1) conf.insert(ii(i, r[i]));
  }
  vector<ii> qs(m);
  for (int i = 0; i < m; i++) {
    cin >> qs[i].ff >> qs[i].ss;
    if (qs[i].ss == 1) {
      conf.erase(conf.find(ii(qs[i].ff, l[qs[i].ff])));
    } else {
      conf.erase(conf.find(ii(qs[i].ff, r[qs[i].ff])));
    }
  }
  vector<int> ans(n + 1, -1);
  for (ii c : conf) {
    merge(c.ff, c.ss);
  }

  reverse(all(qs));

  int timer = m - 1;
  for (auto q : qs) {
    if (q.ss == 1) {
      // left
      int u = q.ff;
      int v = l[q.ff];
      if (get(1) == get(u)) swap(u, v);
      if (get(1) == get(v) && get(1) != get(u)) {
        for (int x : gr[get(u)]) ans[x] = timer;
      }
      // cout << "joining " << u << " " << v << endl;
      merge(q.ff, l[q.ff]);
    } else {
      // right
      int u = q.ff;
      int v = r[q.ff];
      if (get(1) == get(u)) swap(u, v);
      if (get(1) == get(v) && get(1) != get(u)) {
        for (int x : gr[get(u)]) ans[x] = timer;
      }
      // cout << "joining " << u << " " << v << endl;
      merge(q.ff, r[q.ff]);
    }
    timer--;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
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

