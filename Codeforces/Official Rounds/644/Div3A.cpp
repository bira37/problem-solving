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
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b;
    c = a;
    d = b;
    int ans = max(max(b, d), (a + c));
    ans = min(ans, max(max(a, c), (b + d)));
    ans = min(ans, max(max(b, c), (a + d)));
    ans = min(ans, max(max(a, c), (b + d)));
    cout << ans * ans << endl;
  }
}

int32_t main() {
  DESYNC;
  solution();
}

