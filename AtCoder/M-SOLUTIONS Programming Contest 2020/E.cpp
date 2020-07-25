#include <bits/stdc++.h>

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

int x[20], y[20], p[20];

long long best[20];

int32_t main() {
  DESYNC;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> p[i], best[i] = INF;

  // brute people
  int d[n];
  for (int msk = 0; msk < (1 << n); msk++) {
    int cnt = __builtin_popcount(msk);
    for (int dir = msk;; dir = (dir - 1) & msk) {
      for (int i = 0; i < n; i++) d[i] = min(abs(x[i]), abs(y[i]));
      for (int i = 0; i < n; i++) {
        if (msk >> i & 1) {
          if (dir >> i & 1)
            for (int j = 0; j < n; j++) {
              d[j] = min(d[j], abs(x[i] - x[j]));
            }
          else
            for (int j = 0; j < n; j++) {
              d[j] = min(d[j], abs(y[i] - y[j]));
            }
        }
      }

      long long ans = 0;
      for (int i = 0; i < n; i++) {
        ans += (1LL * d[i] * p[i]);
      }
      best[cnt] = min(best[cnt], ans);
      if (dir == 0) break;
    }
  }

  for (int i = 0; i <= n; i++) cout << best[i] << endl;
}

