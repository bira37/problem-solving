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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, 0, n, 1) cin >> v[i];
  sort(all(v));
  int ans = 1;
  if (v[0] >= 0) {
    for (int i = 0; i < k; i++) ans = mod(ans * v[n - 1 - i]);
    cout << ans << endl;
    return;
  }
  if (v[n - 1] <= 0) {
    for (int i = 0; i < k; i++) {
      ans = mod(ans * v[(k % 2 ? n - 1 - i : i)]);
    }
    cout << ans << endl;
    return;
  }

  int l = 0, r = n - 1;
  if (k % 2) {
    ans = mod(ans * v[r]);
    r--;
    k--;
  }

  while (k > 0) {
    int ll = v[l] * v[l + 1];
    int rr = v[r] * v[r - 1];

    if (ll >= rr) {
      ans = mod(ans * mod(ll));
      l += 2;
    } else {
      ans = mod(ans * (mod(rr)));
      r -= 2;
    }
    k -= 2;
  }

  cout << ans << endl;
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

