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

int n;
string s;
int dp[212345][2][2][2][2];

int f(int i, int lst1, int lst2, int ff, int ss)
{
  if (i == n - 1)
  {
    int mn = INF;
    // put L
    if (lst1 + lst2 > 0 && ff + ss > 0 && (lst2 + ff) > 0)
      mn = min(mn, (int)(s[i] != 'L'));

    //put R
    if (lst1 + lst2 < 2 && ff + ss < 2 && (lst2 + ff) < 2)
      mn = min(mn, (int)(s[i] != 'R'));

    return mn;
  }

  int &ans = dp[i][lst1][lst2][ff][ss];
  if (ans != -1)
    return ans;

  ans = INF;

  // take left
  if (lst1 + lst2 > 0)
  {
    ans = min(ans, f(i + 1, lst2, 0, ff, ss) + (s[i] != 'L'));
  }

  //take right
  if (lst1 + lst2 < 2)
  {
    ans = min(ans, f(i + 1, lst2, 1, ff, ss) + (s[i] != 'R'));
  }

  return ans;
}

#define MULTIPLE_TEST_CASE
void solution()
{
  cin >> n;
  cin >> s;
  int ans = INF;
  for (int i = 0; i < n; i++)
  {
    rep(a, 0, 2, 1)
    {
      rep(b, 0, 2, 1)
      {
        rep(c, 0, 2, 1)
        {
          rep(d, 0, 2, 1)
          {
            dp[i][a][b][c][d] = -1;
          }
        }
      }
    }
  }
  ans = min(ans, f(2, 0, 0, 0, 0) + (s[0] != 'L') + (s[1] != 'L'));
  ans = min(ans, f(2, 0, 1, 0, 1) + (s[0] != 'L') + (s[1] != 'R'));
  ans = min(ans, f(2, 1, 0, 1, 0) + (s[0] != 'R') + (s[1] != 'L'));
  ans = min(ans, f(2, 1, 1, 1, 1) + (s[0] != 'R') + (s[1] != 'R'));
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

