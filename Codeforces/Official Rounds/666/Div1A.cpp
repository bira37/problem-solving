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
//#define MULTIPLE_TEST_CASE
void solution() {
  int n;
  cin >> n;
  int v[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  if (n <= 2) {
    cout << 1 << " " << 1 << endl;
    cout << -v[1] << endl;
    cout << n << " " << n << endl;
    cout << (n == 1 ? 0 : -v[n]) << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    return;
  }

  // op 1
  cout << 1 << " " << n - 1 << endl;

  for (int i = 1; i <= n - 1; i++) {
    int x = v[i] * (n - 1);
    v[i] += v[i] * (n - 1);
    cout << x << " ";
  }
  cout << endl;

  // op 2
  cout << 2 << " " << n << endl;
  for (int i = 2; i <= n; i++) {
    if (i != n)
      cout << 0 << " ";
    else {
      int x = v[i] * (n - 1);
      v[i] += v[i] * (n - 1);
      cout << x << " ";
    }
  }

  cout << endl;

  for (int i = 1; i <= n; i++) {
    assert(v[i] % n == 0);
  }

  // op 3
  cout << 1 << " " << n << endl;
  for (int i = 1; i <= n; i++) {
    cout << -v[i] << " ";
  }
  cout << endl;
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

