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
int ans;

void calc(vector<int>& cur, vector<tuple<int, int, int, int>>& q, int n,
          int m) {
  int acc = 0;
  for (int i = 0; i < q.size(); i++) {
    int a, b, c, d;
    tie(d, a, b, c) = q[i];
    if (cur[b - 1] - cur[a - 1] == c) acc += d;
  }
  ans = max(acc, ans);
}
void brute_all(vector<int>& cur, vector<tuple<int, int, int, int>>& q, int n,
               int m) {
  if (cur.size() == n) {
    calc(cur, q, n, m);
    return;
  }
  // add more
  if (cur.size() == 0) {
    for (int i = 1; i <= m; i++) {
      cur.pb(i);
      brute_all(cur, q, n, m);
      cur.pop_back();
    }
  } else {
    for (int i = cur.back(); i <= m; i++) {
      cur.pb(i);
      brute_all(cur, q, n, m);
      cur.pop_back();
    }
  }
}
void solution() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> v(q);
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    v[i] = tie(d, a, b, c);
  }
  ans = 0;
  vector<int> start = vector<int>();
  brute_all(start, v, n, m);
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

