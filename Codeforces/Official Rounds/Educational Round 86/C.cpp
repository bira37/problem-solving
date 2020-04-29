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
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int brute(int l, int r, int a, int b) {
  int tot = r - l + 1;
  for (int i = l; i <= r; i++) {
    if ((i % a) % b == (i % b) % a) tot--;
  }
  return tot;
}

int solve(int l, int r, int a, int b) {
  int mmc = a * (b / gcd(a, b));

  if (r < b) {
    return 0;
  }

  // if greater
  l = max(l, b);

  int diff = (r - l + 1);
  int mmc_cnt = r / mmc - (l - 1) / mmc;

  if (mmc_cnt > 0) diff -= (mmc_cnt - 1) * b;

  int mx = (r / mmc) * mmc;
  // cout << "mx " << mx << endl;
  diff -= max(0LL, min(r, mx + b - 1) - max(mx, l) + 1);

  int mn = ((l - 1) / mmc) * mmc;
  // cout << "mn " << mn << endl;
  if (mn != mx) diff -= max(0LL, min(r, mn + b - 1) - max(mn, l) + 1);
  return diff;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    int a, b, q;
    cin >> a >> b >> q;
    if (a > b) swap(a, b);

    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << solve(l, r, a, b) << " ";
    }
    cout << endl;
  }
}

