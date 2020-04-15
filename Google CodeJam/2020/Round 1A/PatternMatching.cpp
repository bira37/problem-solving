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

bool pattern_check(vector<string>& v) {
  for (string& s : v) {
    if (v[0].substr(0, s.size()) != s) return false;
  }
  return true;
}

void solve(int test_num) {
  cout << "Case #" << test_num << ": ";
  int n;
  cin >> n;
  string v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // test set 1 and 2
  vector<string> l, r, mid;
  for (int i = 0; i < n; i++) {
    string cur;
    int st = 0, ed = v[i].size() - 1;
    for (char c : v[i]) {
      if (c == '*') {
        break;
      } else {
        cur += c;
        st++;
      }
    }
    st++;
    l.pb(cur);
    cur = "";
    reverse(v[i].begin(), v[i].end());
    for (char c : v[i]) {
      if (c == '*') {
        break;
      } else {
        cur += c;
        ed--;
      }
    }
    ed--;
    reverse(v[i].begin(), v[i].end());
    reverse(cur.begin(), cur.end());
    r.pb(cur);
    cur = "";
    for (int x = st; x <= ed; x++)
      if (v[i][x] != '*') cur += v[i][x];
    mid.pb(cur);
  }
  sort(l.begin(), l.end(), [](const string& a, const string& b) {
    return a.size() > b.size() || (a.size() == b.size() && a < b);
  });

  for (int i = 0; i < r.size(); i++) {
    reverse(r[i].begin(), r[i].end());
  }
  sort(r.begin(), r.end(), [](const string& a, const string& b) {
    return a.size() > b.size() || (a.size() == b.size() && a < b);
  });

  if (pattern_check(l) && pattern_check(r)) {
    reverse(r[0].begin(), r[0].end());
    string ans = l[0];
    for (string k : mid) ans += k;
    ans += r[0];
    cout << ans << endl;
  } else
    cout << "*" << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
}

