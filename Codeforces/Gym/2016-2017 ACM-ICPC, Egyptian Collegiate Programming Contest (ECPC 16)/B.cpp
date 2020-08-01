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
  fin.tie(0);                       \
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
ifstream fin("street.in");
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
#define MULTIPLE_TEST_CASE
void solution() {
  int n, H, W;
  fin >> n >> H >> W;
  double cst[n + 2][n + 2];
  double dst[n + 2];
  for (int i = 0; i <= n + 1; i++) {
    dst[i] = INF;
    for (int j = 0; j <= n + 1; j++) {
      cst[i][j] = 0;
    }
  }
  int h[n + 2], w[n + 2], d[n + 2], k[n + 2];
  for (int i = 1; i <= n; i++) fin >> h[i] >> w[i] >> d[i] >> k[i];

  // link top and bottom
  cst[0][n + 1] = cst[n + 1][0] = H;

  // precalc this bullshit cost
  for (int i = 1; i <= n; i++) {
    // cost to extremes
    cst[n + 1][i] = cst[i][n + 1] = H - (d[i] + h[i]);
    cst[0][i] = cst[i][0] = d[i];

    for (int j = i + 1; j <= n; j++) {
      int y = min(abs(d[i] + h[i] - d[j]), abs(d[j] + h[j] - d[i]));
      int x = max(0LL, W - w[i] - w[j]);

      // if they are at the same side, just go up

      if (k[i] == k[j]) {
        cst[i][j] = cst[j][i] = y;
        continue;
      }

      // else, you need to go diagonal / to the sides
      if (d[i] > d[j] + h[j] || d[j] > d[i] + h[i]) {
        // need to go diagonal bullshit
        cst[i][j] = cst[j][i] = sqrt(x * x + y * y);
      } else {
        cst[i][j] = cst[j][i] = x;
      }
    }
  }

  // NOWWWWWW YOU DO DIJKSTRA

  set<pair<double, int>> q;
  q.emplace(0, 0);
  dst[0] = 0;
  while (q.size() > 0) {
    double cur = q.begin()->ff;
    int u = q.begin()->ss;
    q.erase(q.begin());
    if (EPS < abs(cur - dst[u])) continue;
    // cout << "at " << u << " " << cur << endl;
    for (int v = 0; v <= n + 1; v++) {
      if (dst[v] > cur + cst[u][v]) {
        dst[v] = cur + cst[u][v];
        q.emplace(dst[v], v);
      }
    }
  }

  cout << fixed << setprecision(9) << dst[n + 1] << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  fin >> t;
#endif
  while (t--) solution();
}
