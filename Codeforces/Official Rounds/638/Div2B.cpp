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
  // DESYNC;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    set<int> options;
    for (int i = 0; i < n; i++) options.insert(v[i]);
    if (options.size() > k) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 1; i <= n; i++)
      if (options.size() < k && !options.count(i)) options.insert(i);
    vector<int> ans;
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (s.count(v[i])) {
        for (int x : options) {
          if (s.size() < k && !s.count(x)) {
            s.insert(x);
            ans.pb(x);
          }
        }
        int id = ans.size();
        s.erase(ans[id - k]);
        i--;
      } else {
        ans.pb(v[i]);
        s.insert(v[i]);
      }
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
  }
}

