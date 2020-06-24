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
  vector<ii> p;
  if (n % 4 == 0) {
    cout << 0 << endl;
    cout << n / 2;
    bool printa = false;
    for (int l = 1, r = n; l < r; l++, r--) {
      printa = !printa;
      if (!printa) continue;
      cout << " " << l << " " << r;
    }
    cout << endl;
    return;
  } else {
    int rem = n % 4;
    vector<int> ans;
    bool printa = false;
    for (int l = 1, r = n - rem; l < r; l++, r--) {
      printa = !printa;
      if (!printa) continue;
      ans.pb(l + rem);
      ans.pb(r + rem);
    }
    if (rem == 3) {
      ans.pb(rem);
      cout << 0 << endl;
      cout << ans.size();
      for (int x : ans) cout << " " << x;
      cout << endl;
    } else if (rem <= 2) {
      ans.pb(rem);
      cout << 1 << endl;
      cout << ans.size();
      for (int x : ans) cout << " " << x;
      cout << endl;
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

