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
#define MULTIPLE_TEST_CASE
void solution() {
  bool good = true;
  int n, m;
  cin >> n >> m;
  char A[n][m];
  int gcount = 0;
  rep(i, 0, n, 1) {
    rep(j, 0, m, 1) {
      cin >> A[i][j];
      if (A[i][j] == 'G') gcount++;
    }
  }
  auto valid = [&](const int x, const int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };

  queue<ii> q;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};

  rep(i, 0, n, 1) {
    rep(j, 0, m, 1) {
      if (A[i][j] == 'B') {
        rep(x, 0, 4, 1) {
          if (valid(i + dx[x], j + dy[x])) {
            if (A[i + dx[x]][j + dy[x]] == 'G')
              good = false;
            else if (A[i + dx[x]][j + dy[x]] != 'B')
              A[i + dx[x]][j + dy[x]] = '#';
          }
        }
      }
    }
  }
  // rep(i, 0, n, 1) {
  //   rep(j, 0, m, 1) { cout << A[i][j] << " "; }
  //   cout << endl;
  // }
  if (A[n - 1][m - 1] != '#') {
    q.emplace(n - 1, m - 1);
    vis[n - 1][m - 1] = true;
  }
  while (!q.empty()) {
    ii cur = q.front();
    int i = cur.ff;
    int j = cur.ss;
    // cout << i << " " << j << " " << A[i][j] << endl;
    q.pop();
    if (A[i][j] == 'G') gcount--;
    if (A[i][j] == 'B') good = false;
    rep(x, 0, 4, 1) {
      if (valid(i + dx[x], j + dy[x]) && A[i + dx[x]][j + dy[x]] != '#' &&
          !vis[i + dx[x]][j + dy[x]]) {
        q.emplace(i + dx[x], j + dy[x]);
        vis[i + dx[x]][j + dy[x]] = true;
      }
    }
  }
  if (gcount > 0 || !good)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}

int32_t main() {
  // DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

