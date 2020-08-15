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

int v[3000][3000];
int dp[3000][3000][4];
int n, m, k;
int solve(int x, int y, int cnt)
{
  if (x == n - 1 && y == m - 1)
    return 0;
  if (dp[x][y][cnt] != -1)
    return dp[x][y][cnt];

  int &ans = dp[x][y][cnt];

  if (y + 1 < m)
  {
    if (cnt < 3 && v[x][y + 1] != -1)
    {
      ans = max(ans, solve(x, y + 1, cnt + 1) + v[x][y + 1]);
    }
    ans = max(ans, solve(x, y + 1, cnt));
  }
  if (x + 1 < n)
  {
    if (v[x + 1][y] != -1)
    {
      ans = max(ans, solve(x + 1, y, 1) + v[x + 1][y]);
    }
    ans = max(ans, solve(x + 1, y, 0));
  }

  //cout << "dp[" << x << "][" << y << "][" << cnt << "] = " << ans << endl;
  return ans;
}
//#define MULTIPLE_TEST_CASE
void solution()
{
  cin >> n >> m >> k;
  memset(v, -1, sizeof v);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < k; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    x--, y--;
    v[x][y] = c;
  }
  int ans = solve(0, 0, 0);
  if (v[0][0] != -1)
    ans = max(ans, solve(0, 0, 1) + v[0][0]);
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

