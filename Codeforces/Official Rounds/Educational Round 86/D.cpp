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

int32_t main() {
  DESYNC;
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int c[k + 1];
  for (int i = 1; i <= k; i++) cin >> c[i];
  vector<vector<int>> cases;
  cases.pb(vector<int>());
  for (int a : v) {
    if (cases.back().size() == 0) {
      cases.back().pb(a);
      continue;
    }
    int l = 0, r = cases.size() - 1;
    int ans = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (c[a] > cases[m].size()) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    if (ans != -1) {
      cases[ans].pb(a);
    } else {
      cases.pb(vector<int>());
      cases.back().pb(a);
    }
  }
  cout << cases.size() << endl;
  for (vector<int> cs : cases) {
    cout << cs.size();
    for (int x : cs) cout << " " << x;
    cout << endl;
  }
}

