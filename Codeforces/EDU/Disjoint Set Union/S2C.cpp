#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
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

typedef tree<int,  // change for pair<int,int> to use like multiset
             null_type,
             less<int>,  // change for pair<int,int> to use like multiset
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;

int uf[212345], sz[212345];
ordered_set gr[212345];
void init(int n) {
  for (int i = 0; i <= n; i++) {
    uf[i] = i, sz[i] = 1;
    gr[i].insert(i);
  }
}

void dummy() {
  char c;
  cin >> c;
}

int get(int a) { return uf[a] = (uf[a] == a ? a : get(uf[a])); }

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
  int n, q;
  cin >> n >> q;
  init(n);
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 3) {
      cout << (get(a) == get(b) ? "YES" : "NO") << endl;
    } else if (t == 1) {
      merge(a, b);
    } else {
      merge(a, b);
      int x = get(a);
      while (true) {
        // cout << "finding by " << endl;
        // for (int k : gr[x]) cout << k << " ";
        // cout << endl;
        int l = a, r = b, ans = -1;
        while (l <= r) {
          int m = (l + r) >> 1;
          int ax = gr[x].order_of_key(m + 1);
          int bx = gr[x].order_of_key(a);
          // cout << "at " << m << " " << ax - bx << " " << m - a + 1 << endl;
          if (ax - bx != m - a + 1) {
            ans = m;
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
        if (ans == -1) break;
        // cout << "merging " << x << " " << ans << endl;
        merge(x, ans);
        x = get(x);
      }
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

