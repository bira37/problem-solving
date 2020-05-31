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
  int n;
  cin >> n;
  int mul = 1;
  int has_zero = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) has_zero = 1;
    v.pb(x);
  }
  if (has_zero == 1) {
    cout << 0 << endl;
    return;
  }
  for (int x : v) {
    if (mul > (int)(1e18) / x) {
      cout << -1 << endl;
      return;
    }
    mul *= x;
    if (mul > 1000000000000000000) {
      cout << -1 << endl;
      return;
    }
  }
  cout << mul << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  solution();
}

