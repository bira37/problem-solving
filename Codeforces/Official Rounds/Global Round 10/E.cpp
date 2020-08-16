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
//#define MULTIPLE_TEST_CASE
void solution()
{
  int n;
  cin >> n;

  int mat[n][n];
  int st = 1;
  for (int i = 0; i < n; i++)
  {
    int cur = st;
    for (int j = 0; j < n; j++)
    {
      if (i % 2)
        mat[i][j] = 0;
      else
        mat[i][j] = cur;
      cur *= 2LL;
    }
    st *= 2LL;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  cout.flush();
  int q;
  cin >> q;
  while (q--)
  {
    // answer
    int k;
    cin >> k;
    vector<ii> path;
    k -= mat[n - 1][n - 1];
    int x = n - 1, y = n - 1;
    path.pb(ii(x, y));
    while (x != 0 || y != 0)
    {
      if (x - 1 < 0)
      {
        y--;
        k -= mat[x][y];
      }
      else if (y - 1 < 0)
      {
        x--;
        k -= mat[x][y];
      }
      else
      {
        if (mat[x - 1][y] > mat[x][y - 1])
        {
          if (k >= mat[x - 1][y])
          {
            x--;
            k -= mat[x][y];
          }
          else
          {
            y--;
            k -= mat[x][y];
          }
        }
        else
        {
          if (k >= mat[x][y - 1])
          {
            y--;
            k -= mat[x][y];
          }
          else
          {
            x--;
            k -= mat[x][y];
          }
        }
      }
      path.pb(ii(x, y));
    }
    reverse(all(path));
    for (ii p : path)
      cout << p.ff + 1 << " " << p.ss + 1 << endl;
    cout.flush();
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

