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
int mark = 0;
vector<int> g[212345];
ii interval[212345];
int anc[212345];

void go(int u, int p = -1) {
  anc[u] = (p == -1 ? 1 : p);
  int children = 0;
  for (int v : g[u]) {
    if (v == p) continue;
    children++;
  }
  if (children == 0) {
    interval[u] = ii(mark, mark);
    mark++;
    // cout << "interval for " << u << " " << interval[u].ff << " " <<
    // interval[u].ss << endl;
    return;
  }
  for (int v : g[u]) {
    if (v == p) continue;
    go(v, u);
    if (interval[u] == ii(-1, -1))
      interval[u] = interval[v];
    else
      interval[u] = ii(min(interval[u].ff, interval[v].ff),
                       max(interval[u].ss, interval[v].ss));
  }
  // cout << "interval for " << u << " " << interval[u].ff << " " <<
  // interval[u].ss << endl;
}

int32_t main() {
  DESYNC;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    interval[i + 1] = ii(-1, -1);
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  interval[n] = ii(-1, -1);
  go(1);

  while (k--) {
    int x;
    cin >> x;
    int v[x];
    for (int i = 0; i < x; i++) cin >> v[i];

    int l = interval[anc[v[0]]].ff, r = interval[anc[v[0]]].ss;
    // cout << "starting" << endl;
    // cout << "current " << l << " " << r << endl;
    bool ans = true;
    for (int i = 1; i < x; i++) {
      l = max(l, interval[anc[v[i]]].ff);
      r = min(r, interval[anc[v[i]]].ss);
      if (r < l) ans = false;
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}
