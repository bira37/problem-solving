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

void brute() { int a, b, n; }

void solution() {
  int n, m;
  cin >> n >> m;
  n = m * 2 + 1;
  int mid = (n / 2) + 1;
  for (int l = 1, r = mid; l < r; l++, r--) {
    cout << l << " " << r << endl;
    m--;
    if (m == 0) break;
  }
  for (int l = mid + 1, r = n; l < r; l++, r--) {
    cout << l << " " << r << endl;
    m--;
    if (m == 0) break;
  }
}

int32_t main() {
  DESYNC;
  solution();
}

