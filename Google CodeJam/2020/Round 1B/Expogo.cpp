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

void problem(int x, int y) {
  bool invx = false, invy = false;
  if (x % 2 && y % 2) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  if (x % 2 == 0 && y % 2 == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  if (x < 0) {
    x = abs(x);
    invx = true;
  }
  if (y < 0) {
    y = abs(y);
    invy = true;
  }

  for (int bits = 0; bits <= 50; bits++) {
    int fx = 0, fy = 0, bx = 0, by = 0;
    string ans = "";
    for (int b = bits - 1; b >= 0; b--) {
      int getx = x - (fx - bx);
      int retx = (fx - bx) - x;
      int gety = y - (fy - by);
      int rety = (fy - by) - y;
      int mx = max(getx, max(gety, max(retx, rety)));
      if (mx == getx) {
        fx += (1LL << b);
        ans += "E";
      } else if (mx == retx) {
        bx += (1LL << b);
        ans += "W";
      } else if (mx == gety) {
        fy += (1LL << b);
        ans += "N";
      } else {
        by += (1LL << b);
        ans += "S";
      }
    }
    if (fx - bx == x && fy - by == y) {
      if (invx)
        for (char& c : ans)
          if (c == 'W')
            c = 'E';
          else if (c == 'E')
            c = 'W';
      if (invy)
        for (char& c : ans)
          if (c == 'S')
            c = 'N';
          else if (c == 'N')
            c = 'S';

      reverse(ans.begin(), ans.end());
      cout << ans << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

void solve(int test_num) {
  cout << "Case #" << test_num << ": ";
  int x, y;
  cin >> x >> y;
  problem(x, y);
}

int32_t main() {
  DESYNC;
  int tt;
  cin >> tt;
  for (int test_num = 0; test_num < tt; test_num++) solve(test_num + 1);
}

