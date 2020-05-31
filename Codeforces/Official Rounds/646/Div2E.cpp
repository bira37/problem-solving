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

int a[212345], b[212345], c[212345];
int z[212345], o[212345];
vector<int> g[212345];
int ans;

void go(int u, int p = -1) {
  if (p != -1) a[u] = min(a[u], a[p]);

  for (int v : g[u]) {
    if (v == p) continue;
    go(v, u);
    z[u] += z[v];
    o[u] += o[v];
  }

  if (b[u] != c[u]) {
    if (b[u] == 0)
      z[u]++;
    else
      o[u]++;
  }

  int tira = min(o[u], z[u]);
  ans += 2 * tira * a[u];
  o[u] -= tira;
  z[u] -= tira;
  if (p == -1 && o[u] + z[u] > 0) ans = -1;
}

void solution() {
  int n;
  cin >> n;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    z[i] = o[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  go(1);
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  solution();
}

