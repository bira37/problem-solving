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

  void print()
  {
    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < m[i].size(); j++)
      {
        cout << m[i][j] << " ";
      }
      cout << endl;
    }
  }
};

//#define MULTIPLE_TEST_CASE
void solution()
{
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int c[n];
  for (int i = 0; i < n; i++)
    cin >> c[i];
  int p, q, r;
  cin >> p >> q >> r;

  if (k < n)
  {
    cout << a[k] << endl;
    return;
  }
  Matrix A(n + 6, n + 6);
  for (int i = 1; i < n; i++)
  {
    A.m[i][i - 1] = 1;
  }
  for (int i = 0; i < n; i++)
    A.m[0][i] = c[i];
  // get next a_i
  A.m[0][n] = 1;
  A.m[0][n + 1] = 2 * r;
  A.m[0][n + 2] = r;
  A.m[0][n + 3] = 1;
  A.m[0][n + 4] = r;
  A.m[0][n + 5] = q;

  // update p
  A.m[n][n] = 1;

  // update i-1
  A.m[n + 1][n + 1] = 1;
  A.m[n + 1][n + 4] = 1;

  // update square i-1
  A.m[n + 2][n + 1] = 2;
  A.m[n + 2][n + 2] = 1;
  A.m[n + 2][n + 4] = 1;

  // update (i-1)*q
  A.m[n + 3][n + 3] = 1;
  A.m[n + 3][n + 4] = q;

  // update ones
  A.m[n + 4][n + 4] = 1;
  A.m[n + 5][n + 5] = 1;

  Matrix B(n + 6, 1);
  for (int i = 0; i < n; i++)
  {
    B.m[i][0] = a[n - 1 - i];
  }

  B.m[n][0] = p;
  B.m[n + 1][0] = n - 1;
  B.m[n + 2][0] = (n - 1) * (n - 1);
  B.m[n + 3][0] = (n - 1) * q;
  B.m[n + 4][0] = 1;
  B.m[n + 5][0] = 1;

  //A.print();
  //cout << "B" << endl;
  //B.print();

  A = A.exp(k - n + 1);
  Matrix C = A * B;

  //cout << "C:" << endl;
  //C.print();
  cout << C.m[0][0] << endl;
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
