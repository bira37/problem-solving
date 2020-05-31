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

void solution() {
  string s;
  cin >> s;
  int n = s.size();
  int pre[n + 1];
  pre[0] = 0;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (s[i - 1] == '0');
  }

  int ans = INF;
  for (int i = 1; i <= n; i++) {
    // rupture point is i

    // change all 0/1
    ans = min(ans, (i - pre[i]) + (pre[n] - pre[i]));

    // change all 0/0
    ans = min(ans, (i - pre[i]) + ((n - i) - (pre[n] - pre[i])));

    // change all 1/0
    ans = min(ans, pre[i] + ((n - i) - (pre[n] - pre[i])));

    // change all 1/1
    ans = min(ans, pre[i] + (pre[n] - pre[i]));
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) solution();
}

