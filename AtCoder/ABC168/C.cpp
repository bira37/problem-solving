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

void solution() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double ang1 = h * 360 / 12;
  double x = ((double)m / 60) * 360 / 12;
  ang1 += x;
  // cout << ang1 << endl;
  double ang2 = m * 360 / 60;
  double ang = abs(ang1 - ang2);
  ang = min(ang, 360 - ang);
  double ans = a * a + b * b - 2 * a * b * cos((double)(ang * PI) / 180);
  cout << fixed << setprecision(15) << sqrt(ans) << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

