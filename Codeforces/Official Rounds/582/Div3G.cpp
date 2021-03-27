#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

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
using ll = long long;
using namespace std;
const double PI = acos(-1);
const int M = 1000000007;
// const int M = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

// #define PRINT_TEST_CASE
//#define MULTIPLE_TEST_CASE

int uf[212345], sz[212345];

int get(int u) {
  if (u == uf[u])
    return u;
  else
    return uf[u] = get(uf[u]);
}

bool merge(int u, int v) {
  int a = get(u), b = get(v);
  if (a == b) return false;
  if (sz[a] < sz[b]) swap(a, b);
  uf[b] = a;
  sz[a] += sz[b];
  return true;
}

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n, q;
  cin >> n >> q;
  vector<ii> qs;
  int ans[q];
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.pb(mt(c, a, b));
  }
  sort(all(edges));
  reverse(all(edges));
  for (int i = 1; i <= n; i++) {
    uf[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    qs.pb(ii(x, i));
  }
  sort(all(qs));
  int acc = 0;
  for (ii qq : qs) {
    int x = qq.ff;
    int id = qq.ss;
    while (edges.size() > 0 && get<0>(edges.back()) <= x) {
      int a, b, c;
      tie(c, a, b) = edges.back();
      if (get(a) != get(b)) acc += sz[get(a)] * sz[get(b)];
      merge(a, b);
      edges.pop_back();
    }
    ans[id] = acc;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << " ";
  cout << endl;
}

int32_t main() {
  DESYNC;
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++) solution(_testcase);
}

