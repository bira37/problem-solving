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

void solution(int testcase) {
  cout << "Case #" << testcase << ": ";
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  set<tuple<int, int, int, int>> q;
  map<ii, ii> dist;
  int dd = 0;
  int ans = INF;
  for (char c : s) {
    dd++;
    if (c == 'E')
      x++;
    else if (c == 'W')
      x--;
    else if (c == 'N')
      y++;
    else
      y--;
    if (abs(x) + abs(y) <= dd) ans = min(ans, dd);
  }
  if (ans != INF)
    cout << ans << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
  DESYNC;
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++)
    solution(_testcase);
}

