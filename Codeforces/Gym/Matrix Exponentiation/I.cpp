#include <bits/stdc++.h>

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
const int M = 1000000007;
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

struct Matrix
{
  vector<vector<int>> m;
  Matrix() {}
  Matrix(int l, int c)
  {
    m.resize(l, vector<int>(c, 0));
  }

  Matrix operator*(Matrix b) const
  {
    Matrix c(m.size(), b.m[0].size());
    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < b.m[0].size(); j++)
      {
        for (int k = 0; k < b.m.size(); k++)
        {
          c.m[i][j] += (1LL * m[i][k] * b.m[k][j]) % M;
          c.m[i][j] %= M;
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
  Matrix v[31];
  int n, m, q;
  cin >> n >> m >> q;
  v[0] = Matrix(n, n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[0].m[a][b]++;
  }
  for (int i = 1; i < 31; i++)
    v[i] = v[i - 1] * v[i - 1];

  while (q--)
  {
    int a, b, k;
    cin >> a >> b >> k;
    a--, b--;
    Matrix ans(1, n);
    ans.m[0][a] = 1;
    for (int i = 30; i >= 0; i--)
    {
      if ((1LL << i) <= k)
      {
        k -= (1LL << i);
        ans = ans * v[i];
      }
    }
    cout << ans.m[0][b] << endl;
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
