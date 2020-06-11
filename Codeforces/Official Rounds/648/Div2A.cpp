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
#define MULTIPLE_TEST_CASE
void solution() {
  int n, m;
  cin >> n >> m;
  int r = 0, c = 0;
  int A[n][m];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
      cnt += A[i][j];
    }
    if (cnt == 0) r++;
  }
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += A[i][j];
    }
    if (cnt == 0) c++;
  }
  if (min(r, c) % 2)
    cout << "Ashish" << endl;
  else
    cout << "Vivek" << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

