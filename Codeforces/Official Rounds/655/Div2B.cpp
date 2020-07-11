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

ii brute(int n) {
  int a, b, cur = INF;
  for (int i = 1; i <= n - 1; i++) {
    int x = i;
    int y = n - i;
    if (cur > x * y / gcd(x, y)) {
      a = x;
      b = y;
      cur = x * y / gcd(x, y);
    }
  }
  return ii(a, b);
}
#define MULTIPLE_TEST_CASE
ii solution(int n) {
  int a = 1, b = n - 1, cur = a * b / gcd(a, b);
  vector<int> dvs;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i != 0) continue;
    int x = i;
    int y = n / i;
    dvs.pb(x);
    dvs.pb(y);
  }
  for (int k : dvs) {
    int qtd = n / k;
    int x = k;
    int y = k * (qtd - 1);
    if (x == 0 || y == 0) continue;
    if (cur > x * y / gcd(x, y)) {
      a = x;
      b = y;
      cur = x * y / gcd(x, y);
    }
  }
  return ii(a, b);
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto wtf = solution(n);
    cout << wtf.ff << " " << wtf.ss << endl;
  }
}

