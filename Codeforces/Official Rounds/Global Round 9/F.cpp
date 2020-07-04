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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
//#define MULTIPLE_TEST_CASE
void solution() {
  pair<int, int> v[3];
  cin >> v[0].ff >> v[1].ff >> v[2].ff;
  v[0].ss = 1;
  v[1].ss = 2;
  v[2].ss = 3;
  cout << "First" << endl;
  cout.flush();
  sort(v, v + 3);
  map<int, int> id;
  id[v[0].ss] = 0;
  id[v[1].ss] = 1;
  id[v[2].ss] = 2;

  cout << v[2].ff * 2 - v[1].ff - v[0].ff << endl;
  cout.flush();
  int s;
  cin >> s;
  int dummy;
  if (id[s] == 2) {
    v[2].ff += v[2].ff * 2 - v[1].ff - v[0].ff;
    cout << v[2].ff * 2 - v[1].ff - v[0].ff << endl;
    cout.flush();
    cin >> s;
    if (id[s] == 1) {
      cout << v[2].ff - v[0].ff << endl;
      cout.flush();
      cin >> dummy;
    } else {
      cout << v[2].ff - v[1].ff << endl;
      cout.flush();
      cin >> dummy;
    }
  } else if (id[s] == 1) {
    cout << v[2].ff - v[0].ff << endl;
    cout.flush();
    cin >> dummy;
  } else {
    cout << v[2].ff - v[1].ff << endl;
    cout.flush();
    cin >> dummy;
  }
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

