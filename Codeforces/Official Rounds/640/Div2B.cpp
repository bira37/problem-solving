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
    int n, k;
    cin >> n >> k;
    if (n < k) {
      cout << "NO" << endl;

    } else {
      if ((n - (k - 1)) % 2) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 1 << " ";
        cout << n - (k - 1) << endl;
      } else if (n > 2 * (k - 1) && (n - 2 * (k - 1)) % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 2 << " ";
        cout << n - 2 * (k - 1) << endl;
      } else
        cout << "NO" << endl;
    }
  }
}

int32_t main() {
  DESYNC;
  solution();
}

