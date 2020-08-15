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

int bit_cnt(int x)
{
  return __builtin_popcount(x);
}

int mat[1123456][3];
int n, m;
int dp[1123456][8];

bool can(int l, int r)
{
  int mat[2][3];
  for (int i = 0; i < 3; i++)
  {
    mat[0][i] = (l >> i) & 1;
    mat[1][i] = (r >> i) & 1;
  }
  for (int i = 0; i < m - 1; i++)
  {
    if ((mat[0][i] + mat[0][i + 1] + mat[1][i] + mat[1][i + 1]) % 2 == 0)
      return false;
  }
  return true;
}

int solve(int x, int last)
{
  if (x == n)
    return 0;
  if (dp[x][last] != -1)
    return dp[x][last];
  int &ans = dp[x][last];
  ans = INF;
  for (int cmb = 0; cmb < (1LL << m); cmb++)
  {
    if (x == 0 || can(last, cmb))
      ans = min(ans, bit_cnt(cmb ^ mat[x][0]) + solve(x + 1, cmb));
  }
  return ans;
}
//#define MULTIPLE_TEST_CASE
void solution()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      int x = (c == '1');
      if (m > n)
        mat[j][i] = x;
      else
        mat[i][j] = x;
    }
  }
  if (min(n, m) >= 4)
  {
    cout << -1 << endl;
    return;
  }
  if (n < m)
    swap(n, m);
  for (int i = 0; i < n; i++)
  {
    mat[i][0] = mat[i][0] + 2 * mat[i][1] + 4 * mat[i][2];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
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

