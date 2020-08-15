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
  Matrix(int l, int c) { m.resize(l, vector<int>(c, INF)); }

  Matrix operator*(Matrix b) const
  {
    Matrix c(m.size(), b.m[0].size());
    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < b.m[0].size(); j++)
      {
        for (int k = 0; k < b.m.size(); k++)
        {
          if (b.m[k][j] != INF && m[i][k] != INF)
            c.m[i][j] = min(c.m[i][j], (m[i][k] + b.m[k][j]));
          // c.m[i][j] = mod(c.m[i][j], M);
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

struct DoubleMatrix
{
  vector<vector<double>> m;
  DoubleMatrix() {}
  DoubleMatrix(int l, int c) { m.resize(l, vector<double>(c)); }

  DoubleMatrix operator*(DoubleMatrix b) const
  {
    DoubleMatrix c(m.size(), b.m[0].size());
    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < b.m[0].size(); j++)
      {
        for (int k = 0; k < b.m.size(); k++)
        {
          c.m[i][j] += (m[i][k] * b.m[k][j]);
        }
      }
    }
    return c;
  }

  DoubleMatrix exp(int k)
  {
    if (k == 1)
      return *this;
    DoubleMatrix c = (*this).exp(k / 2);
    c = c * c;
    if (k % 2)
      c = c * (*this);
    return c;
  }
};

//#define MULTIPLE_TEST_CASE
void solution()
{
  int n, m, k;
  cin >> n >> m >> k;
  Matrix A(n + 1, n + 1);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    A.m[a][b] = min(A.m[a][b], c);
  }
  A = A.exp(k);
  int ans = INF;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      ans = min(ans, A.m[i][j]);
  }
  cout << (ans == INF ? "IMPOSSIBLE" : to_string(ans)) << endl;
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
