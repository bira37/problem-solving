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

void run(int test_num) {
  cout << "Case #" << test_num << ": ";
  int n;
  cin >> n;
  tuple<int, int, int> v[n];
  for (int i = 0; i < n; i++) {
    cin >> get<0>(v[i]) >> get<1>(v[i]);
    get<2>(v[i]) = i;
  }
  string ans;
  for (int i = 0; i < n; i++) {
    ans += "Z";
  }
  int C = -1, J = -1;
  sort(v, v + n);
  for (int i = 0; i < n; i++) {
    int s, e, id;
    tie(s, e, id) = v[i];
    if (C == -1) {
      ans[id] = 'C';
      C = i;
    } else if (J == -1) {
      ans[id] = 'J';
      J = i;
    } else {
      if (get<1>(v[C]) <= s) {
        ans[id] = 'C';
        C = i;
      } else if (get<1>(v[J]) <= s) {
        ans[id] = 'J';
        J = i;
      } else {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) run(i);
}

