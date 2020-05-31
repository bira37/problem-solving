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
  int n, k;
  cin >> n >> k;
  vector<int> subs[k];
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      subs[i].pb(x);
    }
  }
  int l = 0, r = k - 1;
  int ans = -1;

  cout << "? " << n;
  for (int i = 1; i <= n; i++) cout << " " << i;
  cout << endl;
  cout.flush();

  int max_val;
  cin >> max_val;

  while (l <= r) {
    int m = (l + r) >> 1;

    // query all [l, m]
    vector<int> qry;
    for (int i = l; i <= m; i++) {
      for (int x : subs[i]) qry.pb(x);
    }

    cout << "? " << qry.size();
    for (int x : qry) cout << " " << x;
    cout << endl;
    cout.flush();

    int mx;
    cin >> mx;

    if (mx == max_val) {
      // max is here
      ans = m;
      r = m - 1;
    } else {
      // max is not here
      l = m + 1;
    }
  }

  if (ans == -1) {
    cout << "!";
    for (int i = 0; i < k; i++) {
      cout << " " << max_val;
    }
    cout << endl;
    cout.flush();
  } else {
    // max is at ans
    set<int> qry;
    for (int i = 1; i <= n; i++) qry.insert(i);
    for (int x : subs[ans]) qry.erase(x);

    cout << "? " << qry.size();
    for (int x : qry) cout << " " << x;
    cout << endl;
    cout.flush();

    int mx;
    cin >> mx;

    cout << "!";
    for (int i = 0; i < k; i++) {
      if (i == ans)
        cout << " " << mx;
      else
        cout << " " << max_val;
    }
    cout << endl;
    cout.flush();
  }

  string verd;
  cin >> verd;
  if (verd != "Correct") exit(0);
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) solution();
}

