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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

const int M = 1000000007;

struct Matrix
{
  int m[2][2];
  Matrix() { m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0; }

  Matrix operator*(Matrix b) const
  {
    Matrix c = Matrix();
    c.m[0][0] = (1LL * m[0][0] * b.m[0][0] + 1LL * m[0][1] * b.m[1][0]) % M;
    c.m[0][1] = (1LL * m[0][0] * b.m[0][1] + 1LL * m[0][1] * b.m[1][1]) % M;
    c.m[1][0] = (1LL * m[1][0] * b.m[0][0] + 1LL * m[1][1] * b.m[1][0]) % M;
    c.m[1][1] = (1LL * m[1][0] * b.m[0][1] + 1LL * m[1][1] * b.m[1][1]) % M;
    return c;
  }
};

Matrix st[4 * 212345];
string s;

Matrix Pick(char c)
{
  Matrix val = Matrix();
  if (c == '?')
  {
    val.m[0][0] = 19;
    val.m[0][1] = 7;
    val.m[1][0] = 6;
    val.m[1][1] = 20;
  }
  else if (c == 'H')
  {
    val.m[0][0] = val.m[1][0] = 1;
  }
  else if (c == 'S' || c == 'D')
  {
    val.m[0][1] = val.m[1][1] = 1;
  }
  else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
  {
    val.m[0][1] = val.m[1][0] = 1;
  }
  else
  {
    val.m[0][0] = val.m[1][1] = 1;
  }
  return val;
}

void build(int cur, int l, int r)
{
  if (l == r)
  {
    st[cur] = Pick(s[l]);
    return;
  }
  int m = (l + r) >> 1;
  build(2 * cur, l, m);
  build(2 * cur + 1, m + 1, r);
  st[cur] = st[2 * cur] * st[2 * cur + 1];
}

void update(int cur, int l, int r, int x, char c)
{
  if (l == r)
  {
    st[cur] = Pick(c);
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m)
    update(2 * cur, l, m, x, c);
  else
    update(2 * cur + 1, m + 1, r, x, c);
  st[cur] = st[2 * cur] * st[2 * cur + 1];
}

//#define MULTIPLE_TEST_CASE
void solution()
{
  int n, q;
  cin >> n >> q;
  cin >> s;
  build(1, 0, n - 1);
  cout << st[1].m[0][0] << endl;
  while (q--)
  {
    int id;
    char c;
    cin >> id >> c;
    update(1, 0, n - 1, id - 1, c);
    cout << st[1].m[0][0] << endl;
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
