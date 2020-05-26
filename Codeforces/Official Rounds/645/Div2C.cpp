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

void solution() {
  int mat[500][500];
  int acc2 = 1;
  int cntfora = 0;
  for (int j = 0; j < 20; j++) {
    acc2 += cntfora;
    int cnt = j + 1;
    int acc = acc2;
    for (int i = 0; i < 20; i++) {
      mat[i][j] = acc;
      cnt++;
      acc = acc + cnt;
    }
    cntfora++;
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  queue<tuple<int, int, int>> q;
  q.push(mt(0, 0, 0));
  set<int> s;
  while (q.size() > 0) {
    int ss, x, y;
    tie(ss, x, y) = q.front();
    q.pop();

    if (x == 8 && y == 11) {
      s.insert(ss);
      continue;
    }
    if (x + 1 < 9) q.push(mt(ss + mat[x + 1][y], x + 1, y));
    if (y + 1 < 12) q.push(mt(ss + mat[x][y + 1], x, y + 1));
  }
  cout << s.size() << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = (c - a);
    int y = (d - b);
    cout << x * y + 1 << endl;
  }
}

