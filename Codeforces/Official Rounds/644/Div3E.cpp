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

ii uf[55][55];
int sz[55][55];
bool border[55][55];

ii find(int x, int y) {
  if (uf[x][y] == ii(x, y))
    return ii(x, y);
  else
    return uf[x][y] = find(uf[x][y].ff, uf[x][y].ss);
}

bool merge(int a, int b, int c, int d) {
  // cout << "merge " << a << "/" << b << " onto " << c << "/" << d << endl;
  ii x = find(a, b);
  ii y = find(c, d);
  if (x == y) return false;
  if (sz[x.ff][x.ss] < sz[y.ff][y.ss]) swap(x, y);
  uf[y.ff][y.ss] = x;
  sz[x.ff][x.ss] += sz[y.ff][y.ss];
  border[x.ff][x.ss] |= border[y.ff][y.ss];
}

void solution() {
  int n;
  cin >> n;
  vector<vector<char>> m(n + 2, vector<char>(n + 2));
  vector<vector<bool>> vis(n + 2, vector<bool>(n + 2));
  queue<ii> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> m[i][j];
      vis[i][j] = false;
      if (m[i][j] == '1' && (i == n || j == n)) {
        vis[i][j] = true;
        q.push(ii(i, j));
      }
    }
  }

  auto valid = [&](int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n && m[x][y] == '1' && !vis[x][y];
  };

  while (!q.empty()) {
    ii cur = q.front();
    q.pop();

    int dx[] = {0, -1};
    int dy[] = {-1, 0};

    for (int k = 0; k < 2; k++) {
      if (valid(cur.ff + dx[k], cur.ss + dy[k])) {
        vis[cur.ff + dx[k]][cur.ss + dy[k]] = true;
        q.push(ii(cur.ff + dx[k], cur.ss + dy[k]));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (m[i][j] == '1' && !vis[i][j]) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}

