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
#define M 4294967296
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

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

struct Matrix
{
  vector<vector<int>> m;
  Matrix() {}
  Matrix(int l, int c) { m.resize(l, vector<int>(c, 0)); }

  Matrix operator*(Matrix b) const
  {
    Matrix c(m.size(), b.m[0].size());
    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < b.m[0].size(); j++)
      {
        for (int k = 0; k < b.m.size(); k++)
        {
          c.m[i][j] += (m[i][k] * b.m[k][j]);
          c.m[i][j] = mod(c.m[i][j], M);
        }
      }
    }
    return c;
  }

  Matrix exp(int k)
  {
    if (k == 1)
      return *this;
    Matrix c = (*this).exp(k / 2);
    c = c * c;
    if (k % 2)
      c = c * (*this);
    return c;
  }
};

//#define MULTIPLE_TEST_CASE
void solution()
{
  int ex;
  cin >> ex;
  if (ex == 0)
  {
    cout << 1 << endl;
    return;
  }
  int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
  int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
  Matrix A(65, 65);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      int cur = i * 8 + j;
      A.m[cur][64] = 1;
      for (int k = 0; k < 8; k++)
      {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
        {
          A.m[cur][ni * 8 + nj]++;
        }
      }
    }
  }
  A.m[64][64] = 1;
  A = A.exp(ex);
  int ans = 0;
  for (int i = 0; i <= 64; i++)
  {
    ans = mod(ans + A.m[0][i]);
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
