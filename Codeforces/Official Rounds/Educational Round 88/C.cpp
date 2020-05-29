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

double calc(int x, int h, int c) {
  return (double)(((x * h) + ((x - 1) * c))) / (double)((x + x - 1));
}

void solution() {
  int h, c;
  double t;
  cin >> h >> c >> t;
  if (2 * t <= (h + c)) {
    cout << 2 << endl;
    return;
  }
  int l = 2, r = (int)1e12;
  while (l < r) {
    int m = (l + r) >> 1;
    double cm = calc(m, h, c);
    double prv = calc(m - 1, h, c);
    double nxt = calc(m + 1, h, c);
    if (abs(t - cm) >= abs(t - prv)) {
      r = m - 1;
    } else if (abs(t - cm) > abs(t - nxt)) {
      l = m + 1;
    } else {
      l = r = m;
    }
  }
  int ans = l;
  double calc_ans = calc(ans, h, c);
  double one = calc(1, h, c);
  if (abs(t - calc_ans) >= abs(t - one)) {
    ans = 1;
  } else
    ans = (ans + ans - 1);
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}

