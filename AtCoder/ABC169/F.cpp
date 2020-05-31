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
#define M 998244353
#define curtime chrono::steady_clock::now().time_since_epoch().count
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
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

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

void solution() {
  int n, s;
  cin >> n >> s;
  vector<int> dp(s + 1, 0);
  vector<int> last_dp(s + 1, 0);
  last_dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = s; j >= 0; j--) {
      dp[j] = mod((j - x >= 0 ? last_dp[j - x] : 0LL) + 2 * last_dp[j]);
    }
    for (int j = 0; j <= s; j++) {
      last_dp[j] = dp[j];
      // cout << "dp[" << i << "][" << j << "] = " << dp[j] << endl;
    }
  }
  cout << dp[s] << endl;
}
int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  solution();
}

