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

void solution() {
  int n;
  cin >> n;
  vector<vector<int> > dist(n, vector<int>(n));
  vector<vector<int> > mat(n, vector<int>(n));
  ii pos[n * n];
  int val = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = val;
      pos[val++] = ii(i, j);
      dist[i][j] = min(i, n - 1 - i);
      dist[i][j] = min(dist[i][j], min(j, n - 1 - j));
    }
  }

  function<bool(int&, int&)> valid = [&](int& a, int& b) {
    return a >= 0 && b >= 0 && a < n && b < n;
  };

  function<void(ii)> update = [&](const ii x) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int nx = x.ff + dx[i];
      int ny = x.ss + dy[i];
      if (!valid(nx, ny)) continue;
      if (dist[x.ff][x.ss] + (mat[x.ff][x.ss] != -1) < dist[nx][ny]) {
        dist[nx][ny] = dist[x.ff][x.ss] + (mat[x.ff][x.ss] != -1);
        update(ii(nx, ny));
      }
    }
  };

  int ans = 0;
  for (int i = 0; i < n * n; i++) {
    int x;
    cin >> x;
    x--;
    ans += dist[pos[x].ff][pos[x].ss];
    mat[pos[x].ff][pos[x].ss] = -1;
    update(pos[x]);
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

