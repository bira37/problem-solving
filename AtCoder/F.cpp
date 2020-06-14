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
#define INF 1000000000
#define ROOT 1
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
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

void solution() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> A(n, vector<char>(m));
  vector<vector<int>> dist(n, vector<int>(m, INF));
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--, b--, c--, d--;
  rep(i, 0, n, 1) {
    rep(j, 0, m, 1) { cin >> A[i][j]; }
  }
  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};
  auto valid = [&](const int x, const int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };

  set<tuple<int, int, int>> q;
  q.insert(mt(0, a, b));
  dist[a][b] = 0;
  while (!q.empty()) {
    int x = get<1>(*q.begin());
    int y = get<2>(*q.begin());
    int dd = get<0>(*q.begin());
    q.erase(q.begin());
    if (dd > dist[x][y]) continue;
    for (int w = 0; w < 4; w++) {
      for (int i = 1; i <= k; i++) {
        if (!valid(x + dx[w] * i, y + dy[w] * i)) break;
        if (dist[x + dx[w] * i][y + dy[w] * i] < dist[x][y] + 1) break;
        if (A[x + dx[w] * i][y + dy[w] * i] == '@') break;
        // cout << x + dx[w] * i << " " << y + dy[w] * i << " " << dist[x][y] +
        // 1
        //<< endl;
        dist[x + dx[w] * i][y + dy[w] * i] = dist[x][y] + 1;
        q.insert(mt(dist[x][y] + 1, x + dx[w] * i, y + dy[w] * i));
      }
    }
  }
  cout << (dist[c][d] == INF ? -1 : dist[c][d]) << endl;
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

