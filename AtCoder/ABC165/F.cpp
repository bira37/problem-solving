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

vector<int> g[212345];
int c[212345];
vector<int> seq(212345);
int ans[212345];
int n;

void go(int u, int p) {
  // calc lis
  int index =
      lower_bound(seq.begin(), seq.begin() + n + 50, c[u]) - seq.begin();
  index--;
  int before = seq[index + 1];
  seq[index + 1] = min(seq[index + 1], c[u]);
  // get ans bruh
  int l = 0, r = n + 50;
  int xx = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (seq[mid] == INF) {
      r = mid - 1;
    } else {
      xx = mid;
      l = mid + 1;
    }
  }
  ans[u] = xx;
  for (int v : g[u]) {
    if (v == p) continue;
    go(v, u);
  }
  // remove
  seq[index + 1] = before;
}

void solution() {
  cin >> n;
  for (int i = 1; i <= n + 100; i++) seq[i] = INF;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  seq[0] = -INF;
  go(1, -1);
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

