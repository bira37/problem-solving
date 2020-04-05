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

    int acc = 0;
    int i;
    for (i = n - 2; i >= 0; i--) {
      if (acc + (n - i - 1) > k) break;
      acc += (n - i - 1);
      if (acc == k) break;
    }
    // cout << i << " " << acc << endl;
    string s;
    for (int i = 0; i < n; i++) s += 'a';
    s[i] = 'b';
    if (acc == k)
      s[i + 1] = 'b';
    else
      s[((n) - (k - acc))] = 'b';
    cout << s << endl;
  }
}
