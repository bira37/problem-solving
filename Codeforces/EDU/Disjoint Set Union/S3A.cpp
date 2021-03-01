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

struct RollbackDsu {
  int uf[312345];
  int sz[312345];
  stack<pair<int *, int>> history;
  stack<int> ans_history;
  int ans;
  RollbackDsu() {}
  RollbackDsu(int n, int init_ans) {
    rep(i, 0, n + 1, 1) {
      uf[i] = i;
      sz[i] = 1;
    }
    ans = init_ans;
  }

  int find(int u) {
    if (uf[u] == u)
      return u;
    else
      return find(uf[u]);
  }

  bool merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);

    history.emplace(&uf[y], uf[y]);
    history.emplace(&sz[x], sz[x]);
    ans_history.push(ans);

    uf[y] = x;
    sz[x] += sz[y];
    ans--;
    return true;
  }

  ii snapshot() { return ii(history.size(), ans_history.size()); }

  void rollback(ii sz) {
    while (history.size() > sz.ff) {
      *history.top().ff = history.top().ss;
      history.pop();
    }
    while (ans_history.size() > sz.ss) {
      ans = ans_history.top();
      ans_history.pop();
    }
  }
};

//#define MULTIPLE_TEST_CASE
void solution() {
  int n, q;
  cin >> n >> q;
  RollbackDsu dsu(n, n);
  stack<ii> saves;
  while (q--) {
    string qry;
    cin >> qry;
    if (qry == "persist") {
      saves.emplace(dsu.snapshot());
    } else if (qry == "rollback") {
      dsu.rollback(saves.top());
      saves.pop();
      cout << dsu.ans << endl;
    } else {
      int a, b;
      cin >> a >> b;
      dsu.merge(a, b);
      cout << dsu.ans << endl;
    }
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

