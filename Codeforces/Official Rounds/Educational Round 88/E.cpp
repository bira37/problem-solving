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
#define M 998244353
#define curtime chrono::steady_clock::now().time_since_epoch().count
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k) {
  if (k == 0) return 1LL;
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

int ft[512345];
void solution() {
  ft[0] = 1;
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << 0 << endl;
    return;
  }
  if (k == 1) {
    cout << n << endl;
    return;
  }

  for (int i = 1; i <= n; i++) {
    ft[i] = mod(ft[i - 1] * i);
  }

  n--;
  k--;

  // get all sequences starting at 1
  int ans = ft[n];
  ans = mod(ans * exp(ft[n - k], M - 2));
  ans = mod(ans * exp(ft[k], M - 2));

  n++;
  for (int i = 2; i <= n; i++) {
    // sequences of multiples of i
    int mul = n / i;
    mul--;
    if (mul >= k) {
      int ans2 = ft[mul];
      ans2 = mod(ans2 * exp(ft[mul - k], M - 2));
      ans2 = mod(ans2 * exp(ft[k], M - 2));
      ans = mod(ans + ans2);
    }
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  solution();
}

