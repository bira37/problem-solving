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
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int calc(int n, int a, int b, int c, int d) {
  if (n == 0) return 0;
  int cnta = 0;
  while (n % 2 == 0) {
    cnta += a;
    n /= 2;
  }
  int cntb = 0;
  while (n % 3 == 0) {
    cntb += b;
    n /= 3;
  }
  int cntc = 0;
  while (n % 5 == 0) {
    cntc += c;
    n /= 5;
  }
  int ans = cnta + cntb + cntc + n * d;
  return ans;
}

map<int, int> dp;
vector<int> ku;

int solve(int n, int a, int b, int c, int d) {
  if (n == 0) return 0;
  if (dp.count(n)) return dp[n];
  int &ans = dp[n];
  ans = INF;

  if (n < INF / d) ans = min(ans, n * d);

  for (int x : ku) {
    int fl = (n / x);
    int ce = ((n + x - 1) / x);
    int cst;
    if (x == 2)
      cst = a;
    else if (x == 3)
      cst = b;
    else
      cst = c;
    ans = min(ans, solve(fl, a, b, c, d) + cst + abs(fl * x - n) * d);
    ans = min(ans, solve(ce, a, b, c, d) + cst + abs(ce * x - n) * d);
  }
  return ans;
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c, d;
    dp.clear();
    ku.pb(3);
    ku.pb(5);
    ku.pb(2);
    cin >> n >> a >> b >> c >> d;
    cout << solve(n, a, b, c, d) << endl;
  }
}

int32_t main() {
  DESYNC;
  solution();
}

