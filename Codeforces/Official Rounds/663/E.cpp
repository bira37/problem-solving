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

inline int mod(int n, int m = M)
{
  int ret = n % m;
  if (ret < 0)
    ret += m;
  return ret;
}

int exp(int n, int k)
{
  if (k == 0)
    return 1;
  if (k == 1)
    return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2)
    ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
#define MULTIPLE_TEST_CASE
void solution()
{
  int n, m;
  cin >> n >> m;
  vector<int> vis(n + 1, false);
  vector<vector<int>> bucket(n + 1, vector<int>());
  vector<vector<int>> g(n + 1, vector<int>());
  vector<int> dad(n + 1, -1);
  function<void(int, int, int)> go = [&](int u, int p, int dep) {
    vis[u] = true;
    dad[u] = p;
    bucket[dep].pb(u);
    for (int x : g[u])
    {
      if (vis[x])
        continue;
      go(x, u, dep + 1);
    }
  };

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  go(1, -1, 0);
  for (int i = (n + 1) / 2; i <= n; i++)
  {
    if (bucket[i].size() > 0)
    {
      vector<int> path;
      int cur = bucket[i][0];
      while (cur != -1)
      {
        path.pb(cur);
        cur = dad[cur];
      }
      cout << "PATH" << endl;
      cout << path.size() << endl;
      for (auto it = path.rbegin(); it != path.rend(); it++)
      {
        cout << *it << " ";
      }
      cout << endl;
      return;
    }
  }
  vector<ii> pairs;
  for (int i = 0; i <= n; i++)
  {
    while (bucket[i].size() > 1)
    {
      int a = bucket[i].back();
      bucket[i].pop_back();
      int b = bucket[i].back();
      bucket[i].pop_back();
      pairs.emplace_back(a, b);
    }
  }
  cout << "PAIRING" << endl;
  cout << pairs.size() << endl;
  for (auto p : pairs)
  {
    cout << p.ff << " " << p.ss << endl;
  }
}

int32_t main()
{
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--)
    solution();
}

