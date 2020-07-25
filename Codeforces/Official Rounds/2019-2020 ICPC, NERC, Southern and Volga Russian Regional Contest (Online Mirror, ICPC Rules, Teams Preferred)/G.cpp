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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), b(n + 1), sa(n + 1, 0), sb(n + 1, 0);
  rep(i, 0, n, 1) cin >> a[i + 1];
  rep(i, 0, n, 1) cin >> b[i + 1];
  rep(i, 1, n + 1, 1) sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];

  vector<int> back(n + 1, 0);
  vector<int> dp(n + 1, INF);

  int j = 0;
  int ans = INF;
  dp[0] = 0;
  rep(i, 1, n + 1, 1)
  {
    while (j < i)
    {
      if (sa[i] - min(sb[j], sa[j]) < k && sb[i] - min(sb[j], sa[j]) < k)
      {
        break;
      }
      j++;
    }
    if (j == i)
      continue;
    back[i] = j;
    dp[i] = dp[j] + 1;
  }

  int start = -1;
  j = 0;
  rep(i, 0, n, 1)
  {
    while (j < n)
    {
      if (sb[j] - min(sa[i], sb[i]) >= k)
        break;
      j++;
    }
    if (sb[j] - min(sa[i], sb[i]) < k)
      continue;
    if (sa[j] - min(sa[i], sb[i]) >= k)
      continue;
    if (dp[i] < ans)
    {
      ans = dp[i];
      start = i;
    }
  }

  if (ans == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
    vector<int> ans;
    while (start > 0)
    {
      ans.pb(start);
      start = back[start];
    }
    reverse(all(ans));
    for (int x : ans)
      cout << x << " ";
    cout << endl;
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

