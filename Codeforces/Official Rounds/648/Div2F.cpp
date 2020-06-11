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
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
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
  int n;
  cin >> n;
  int v[n];
  rep(i, 0, n, 1) { cin >> v[i]; }
  multiset<ii> s;
  int mid = 0;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    s.emplace(min(v[i], v[j]), max(v[i], v[j]));
  }
  if (n % 2) mid = v[n / 2];
  rep(i, 0, n, 1) { cin >> v[i]; }
  bool nop = false;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (!s.count(ii(min(v[i], v[j]), max(v[i], v[j]))))
      nop = true;
    else {
      s.erase(s.find(ii(min(v[i], v[j]), max(v[i], v[j]))));
    }
  }
  if (n % 2) {
    if (mid != v[n / 2]) nop = true;
  }
  if (nop)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
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

