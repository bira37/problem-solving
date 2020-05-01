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
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string v[k];
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s.back()) {
      string ans = "";
      for (int i = 0; i < (s.size() + k - 1) / k; i++) ans += s[0];
      cout << ans << endl;
    } else {
      vector<pair<char, int> > occ;
      occ.pb(make_pair(s[0], 1));
      for (int i = 1; i < s.size(); i++) {
        if (occ.back().ff != s[i])
          occ.pb(mp(s[i], 1));
        else
          occ.back().ss++;
      }
      if (occ.size() == 2 && occ[0].ss == k) {
        string ans = "";
        ans += occ[0].ff;
        for (int i = 0; i < (occ[1].ss + k - 1) / k; i++) {
          ans += occ[1].ff;
        }
        cout << ans << endl;
      } else if (s[0] != s[k - 1])
        cout << s[k - 1] << endl;
      else {
        string ans = "";
        ans += s[0];
        for (int i = k; i < s.size(); i++) ans += s[i];
        cout << ans << endl;
      }
    }
  }
}
