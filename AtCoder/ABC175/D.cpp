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
#define INF 2e18
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

int v[5005], p[5005];
bool vis[5005];
int dep[5005], cst[5005];

int start, cost, sizez;
void go(int u, int d, int c)
{
  vis[u] = true;
  dep[u] = d;
  cst[u] = c;
  if (vis[p[u]])
  {
    start = p[u];
    sizez = d - dep[p[u]] + 1;
    cost = c - cst[p[u]] + v[p[u]];
    return;
  }
  else
  {
    go(p[u], d + 1, c + v[p[u]]);
  }
}

//#define MULTIPLE_TEST_CASE
void solution()
{
  int n, k;
  cin >> n >> k;
  int ans;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
    if (i == 1)
      ans = v[i];
    else
      ans = max(ans, v[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    start = -1;
    cost = -1;
    sizez = -1;

    for (int i = 1; i <= n; i++)
    {
      vis[i] = false;
    }

    go(i, 0, 0);
    for (int j = 1; j <= n; j++)
    {
      if (vis[j] && dep[j] <= k && dep[j] > 0)
      {
        ans = max(ans, cst[j]);
      }
    }

    if (start == -1)
      continue;

    if (dep[start] >= k)
      continue;

    // take cycle
    int newk = k - dep[start];

    int cur = cst[start];

    int times = newk / sizez;

    times = max(0LL, times - 1);

    cur += times * cost;

    newk -= sizez * times;

    if (dep[start] != 0 || times > 0)
      ans = max(ans, cur);

    int pos = start;
    while (newk > 0)
    {
      cur += v[p[pos]];
      pos = p[pos];
      ans = max(ans, cur);
      newk--;
    }
  }
  cout << ans << endl;
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

