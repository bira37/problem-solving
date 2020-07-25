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
  int n, m, k;
  cin >> n >> m >> k;
  function<bool(string, string, int)> check = [&](string a, string b, int k) {
    int cnt = 0;
    for (int i = 0; i < m; i++)
      cnt += (a[i] == b[i]);
    return cnt >= k;
  };

  vector<ii> g[n];
  vector<string> v(n);

  rep(i, 0, n, 1) cin >> v[i];

  rep(i, 0, n, 1)
  {
    rep(j, i + 1, n, 1)
    {
      if (check(v[i], v[j], k))
      {
        reverse(all(v[i]));
        if (check(v[i], v[j], k))
        {
          reverse(all(v[i]));
          continue;
        }
        reverse(all(v[i]));

        g[i].pb(ii(j, 1));
        g[j].pb(ii(i, 1));
      }
      else
      {
        reverse(all(v[i]));
        if (check(v[i], v[j], k))
        {
          g[i].pb(ii(j, 0));
          g[j].pb(ii(i, 0));
          // cout << i << " " << j << " " << 0 << endl;
        }
        else
        {
          cout << -1 << endl;
          return;
        }
        reverse(all(v[i]));
      }
    }
  }

  bool ok = true;
  vector<int> cur;
  vector<int> color(n, -1);
  function<void(int)> go = [&](int u) {
    cur.pb(u);
    //cout << "at " << u << " " << color[u] << endl;
    for (ii v : g[u])
    {
      if (!ok)
        return;
      if (color[v.ff] != -1)
      {
        if (v.ss && color[v.ff] != color[u])
        {
          ok = false;
        }
        if (!v.ss && color[v.ff] == color[u])
        {
          ok = false;
        }
      }
      else
      {
        if (v.ss)
        {
          color[v.ff] = color[u];
        }
        else
        {
          color[v.ff] = color[u] ^ 1;
        }
        go(v.ff);
      }
    }
  };

  vector<int> ans;

  for (int i = 0; i < n; i++)
  {
    if (color[i] != -1)
      continue;
    cur.clear();
    color[i] = 0;
    go(i);
    if (!ok)
    {
      cout << -1 << endl;
      return;
    }
    vector<int> cnt(2, 0);
    for (int x : cur)
    {
      cnt[color[x]]++;
    }
    int chosen = 0;
    if (cnt[0] > cnt[1])
    {
      chosen = 1;
    }
    for (int x : cur)
    {
      if (color[x] == chosen)
        ans.pb(x);
    }
  }

  cout << ans.size() << endl;
  for (int x : ans)
    cout << x + 1 << " ";
  cout << endl;
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

