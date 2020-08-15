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
  map<ii, int> m;
  int ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    double x;
    cin >> x;
    ii frac(round(x * 1e9), 1e9);
    int g = gcd(frac.ff, frac.ss);
    frac.ff /= g;
    frac.ss /= g;
    int pot5 = 0;
    int pot2 = 0;
    while (frac.ff % 2 == 0)
    {
      frac.ff /= 2;
      pot2++;
    }
    while (frac.ff % 5 == 0)
    {
      frac.ff /= 5;
      pot5++;
    }
    while (frac.ss % 2 == 0)
    {
      frac.ss /= 2;
      pot2--;
    }
    while (frac.ss % 5 == 0)
    {
      frac.ss /= 5;
      pot5--;
    }
    ii cur(pot5, pot2);
    for (auto p : m)
    {
      if (p.ff.ff + cur.ff >= 0 && p.ff.ss + cur.ss >= 0)
        ans += p.ss;
    }
    m[cur]++;
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

