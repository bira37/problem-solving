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

string bin(int x) {
  string ans;
  while (x > 0) {
    if (x % 2)
      ans += "1";
    else
      ans += "0";
    x /= 2;
  }
  while (ans.size() < 43) ans += "0";
  reverse(ans.begin(), ans.end());
  return ans;
}

int mx;
int ans;

void greedy(int b, int x, int y, int cur) {
  while (b >= 0) {
    bool pick = false;
    if ((1LL << b) & x) pick = true;
    if ((1LL << b) & y) pick = true;
    if (pick) cur |= (1LL << b);
    b--;
  }
  // calc
  int F = (x & cur) * (y & cur);
  if (F > mx || (F == mx && ans > cur)) {
    mx = F;
    ans = cur;
  }
}
void brute(int b, int x, int y, int l, int r, bool fl, bool fr, int cur) {
  if (b == -1) {
    // calc here
    int F = (x & cur) * (y & cur);
    if (F > mx || (F == mx && ans > cur)) {
      mx = F;
      ans = cur;
    }
    return;
  }
  if (fr && fl) {
    greedy(b, x, y, cur);
    return;
  }
  // bruting bit
  if (!fl && !fr) {
    // equal both
    if ((1LL << b) & r) {
      // r is 1
      if ((1LL << b) & l) {
        // l is also 1
        // can only pick one
        brute(b - 1, x, y, l, r, fl, fr, cur | (1LL << b));
      } else {
        // l is 0
        // pick 1 and break fl
        brute(b - 1, x, y, l, r, true, fr, cur | (1LL << b));

        // pick 0 and break fr
        brute(b - 1, x, y, l, r, fl, true, cur);
      }
    } else {
      // r is zero
      // can only pick 0
      if ((1LL << b) & l) {
        // l is 1
        // wrong dude
        return;
      } else {
        // l is 0
        // pick 0 and nothing changes
        brute(b - 1, x, y, l, r, fl, fr, cur);
      }
    }
  } else if (!fl) {
    // lower than max
    if ((1LL << b) & l) {
      // l is 1
      // can only pick 1 and stays equal to l
      brute(b - 1, x, y, l, r, fl, fr, cur | (1LL << b));
    } else {
      // l is 0
      // pick 0 and stays equal to l
      brute(b - 1, x, y, l, r, fl, fr, cur);

      // pick 1 and breaks l
      brute(b - 1, x, y, l, r, true, fr, cur | (1LL << b));
    }
  } else if (!fr) {
    // greater than min
    if ((1LL << b) & r) {
      // r is 1
      // pick 1 and stays equal to r
      brute(b - 1, x, y, l, r, fl, fr, cur | (1LL << b));

      // pick 0 and breaks r
      brute(b - 1, x, y, l, r, fl, true, cur);
    } else {
      // r is 0
      // can only pick 0 and stays equal to r
      brute(b - 1, x, y, l, r, fl, fr, cur);
    }
  }
}

void solve() {
  int x, y, l, r;
  cin >> x >> y >> l >> r;
  mx = 0;
  ans = INF;
  brute(43, x, y, l, r, false, false, 0);
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++) solve();
}

