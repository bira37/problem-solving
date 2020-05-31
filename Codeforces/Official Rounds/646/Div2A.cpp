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
  int n, x;
  cin >> n >> x;
  int odd = 0;
  int even = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2)
      odd++;
    else
      even++;
  }

  if (odd > 0) {
    x--;
    odd--;
  } else {
    cout << "No" << endl;
    return;
  }
  while (x >= 2 && odd >= 2) {
    x -= 2;
    odd -= 2;
  }
  if (x <= 0 || even >= x) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) solution();
}

