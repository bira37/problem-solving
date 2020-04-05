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

inline int mod(int n, int m)
{
  int ret = n % m;
  if (ret < 0)
    ret += m;
  return ret;
}

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

double dp[(1 << 18)][18];
int n;
double m[18][18];

double solve(int msk, int x)
{
  if (msk == (1 << n) - 1)
    return 1;

  if (dp[msk][x] > -1)
    return dp[msk][x];

  if (x == 0)
  {
    double ans = 1;
    for (int i = 1; i < n; i++)
    {
      if (msk & (1 << i))
        continue;
      ans *= m[0][i];
    }
    return ans;
  }

  for (int i = 0; i < n; i++)
  {
    if (msk & (1 << i))
      continue;

    if (i == 0)
    {
      dp[msk][x] = max(dp[msk][x], m[0][x] * solve(msk | (1 << 0), 0));
    }
    else
    {
      dp[msk][x] = max(dp[msk][x], m[x][i] * solve(msk | (1 << i), x) + m[i][x] * solve(msk | (1 << i), i));
    }
  }
  return dp[msk][x];
}

int32_t main()
{
  DESYNC;
  cin >> n;
  if (n == 1)
  {
    cout << fixed << setprecision(10) << 1.0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < (1 << n); i++)
  {
    for (int j = 0; j < n; j++)
      dp[i][j] = -1;
  }

  double ans = 0;
  for (int i = 0; i < (1 << n); i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (i == 0)
      {
        ans = max(ans,
                  solve((1 << i) | (1 << j), i) * m[i][j]);
      }
      else
      {
        ans = max(ans,
                  solve((1 << i) | (1 << j), i) * m[i][j] + solve((1 << i) | (1 << j), j) * m[j][i]);
      }
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}

