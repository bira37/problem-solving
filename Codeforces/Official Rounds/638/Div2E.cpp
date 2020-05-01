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

int32_t main() {
  DESYNC;
  int n, k;
  cin >> n >> k;
  int dp[n + 1][k];
  int red[n + 1], blue[n + 1];
  for (int i = 0; i < n; i++) cin >> red[i + 1] >> blue[i + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < k; j++) dp[i][j] = false;
  }

  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      dp[i][j] |= dp[i - 1][mod(j - red[i] % k, k)];
      for (int ex = 0; ex <= min(red[i] - 1LL, k - 1); ex++) {
        if ((red[i] - ex) % k + blue[i] >= k) {
          dp[i][j] |= dp[i - 1][mod(j - ex, k)];
        }
      }
    }
  }

  int s = 0;
  for (int i = 0; i < n; i++) s += red[i + 1] + blue[i + 1];
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans = max(ans, dp[n][i] ? ((s - i) / k) : 0LL);
  }
  cout << ans << endl;
}

