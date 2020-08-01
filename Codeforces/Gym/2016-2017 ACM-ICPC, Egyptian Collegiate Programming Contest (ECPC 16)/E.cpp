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

ifstream fin("jumping.in");

#define MULTIPLE_TEST_CASE
void solution() {
  int n;
  fin >> n;
  int v[n];
  for (int i = 0; i < n; i++) fin >> v[i];
  vector<int> adj[n];
  for (int i = 0; i < n; i++) {
    int prv = i - v[i];
    int nxt = i + v[i];
    if (prv >= 0) adj[prv].pb(i);
    if (nxt < n) adj[nxt].pb(i);
  }
  queue<ii> q;
  vector<int> dist(n, INF);

  dist[n - 1] = 0;
  q.push(ii(n - 1, 0));
  while (!q.empty()) {
    int u = q.front().ff;
    int d = q.front().ss;
    q.pop();
    if (dist[u] != d) continue;
    for (int v : adj[u]) {
      if (dist[v] > d + 1) {
        dist[v] = d + 1;
        q.emplace(v, dist[v]);
      }
    }
  }
  for (int i = 0; i < n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << endl;
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
