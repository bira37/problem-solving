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

struct BIT {
  vector<int> bit;

  BIT() {}

  int n;

  BIT(int n) {
    this->n = n;
    bit.resize(n + 1);
  }

  void update(int idx, int val) {
    for (int i = idx; i <= n; i += i & -i) {
      bit[i] += val;
    }
  }

  int prefix_query(int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += bit[i];
    }
    return ans;
  }

  int query(int l, int r) { return prefix_query(r) - prefix_query(l - 1); }

  // int bit 0-1 it finds the index of k-th element active
  int kth(int k) {
    int cur = 0;
    int acc = 0;
    for (int i = 19; i >= 0; i--) {
      if (cur + (1 << i) > n) continue;
      if (acc + bit[cur + (1 << i)] < k) {
        cur += (1 << i);
        acc += bit[cur];
      }
    }
    return ++cur;
  }
};

//#define MULTIPLE_TEST_CASE
void solution() {
  int n, q;
  cin >> n >> q;
  int v[n + 1];
  vector<int> lst(n + 1, -1);
  BIT bit = BIT(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  vector<vector<tuple<int, int, int>>> queries(n + 1);
  int ans[q];
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries[r].pb(mt(l, r, i));
  }
  for (int i = 1; i <= n; i++) {
    if (lst[v[i]] != -1) {
      bit.update(lst[v[i]], -1);
    }
    bit.update(i, 1);
    lst[v[i]] = i;
    // cout << "updated" << endl;
    for (auto tp : queries[i]) {
      int l, r, i;
      tie(l, r, i) = tp;
      ans[i] = bit.query(l, r);
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << endl;
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

