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

int solve(vector<int>& v, int i) {
  int acc = 0;
  bool has = false;
  int ans = 0;
  for (int x : v) {
    if (x > i) {
      acc = 0;
      has = false;
    } else {
      acc += x;
      if (x == i) has = true;

      if (acc < 0) {
        acc = 0;
        has = false;
      }

      if (has) ans = max(ans, acc - i);
    }
  }
  return ans;
}

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 1; i <= 30; i++) {
    // solve as i being the greatest element of the sequence
    ans = max(ans, solve(v, i));
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  solution();
}

