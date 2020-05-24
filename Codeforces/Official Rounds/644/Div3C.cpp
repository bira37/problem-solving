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
  int n;
  cin >> n;
  multiset<int> odd, even;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2)
      odd.insert(x);
    else
      even.insert(x);
  }
  if (odd.size() % 2 == 0 && even.size() % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (odd.size() % 2 != even.size() % 2) {
    cout << "NO" << endl;
  }
  for (int x : odd) {
    if (even.count(x - 1) || even.count(x + 1)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}

