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

bool check(string s, int n0, int n1, int n2) {
  while (n0 > 0 || n1 > 0 || n2 > 0) {
    if (s.back() == '0') {
      if (n0 > 0) {
        s += '0';
        n0--;
      } else if (n1 > 0) {
        s += '1';
        n1--;
      } else
        return false;
    } else if (s.back() == '1') {
      if (n2 > 0) {
        s += '1';
        n2--;
      } else if (n1 > 0) {
        s += '0';
        n1--;
      } else
        return false;
    }
  }
  cout << s << endl;
  return true;
}
void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    string s0 = "0";
    string s1 = "1";
    if (check(s0, n0, n1, n2))
      continue;
    else
      check(s1, n0, n1, n2);
  }
}

int32_t main() {
  DESYNC;
  solution();
}

