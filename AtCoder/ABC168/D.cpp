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
  int n, m;
  cin >> n >> m;
  vector<int> g[n + 1];
  vector<bool> vis(n + 1, false);
  vector<int> ans(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int count = 0;
  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    count++;
    for (int v : g[cur]) {
      if (vis[v]) continue;
      vis[v] = true;
      ans[v] = cur;
      q.push(v);
    }
  }
  if (count != n)
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (int i = 2; i <= n; i++) cout << ans[i] << endl;
  }
}

int32_t main() {
  DESYNC;
  solution();
}

