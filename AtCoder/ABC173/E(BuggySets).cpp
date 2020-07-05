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
  int n, k;
  cin >> n >> k;
  vector<int> v;
  int zeros = 0;
  rep(i, 0, n, 1) {
    int x;
    cin >> x;
    if (x == 0)
      zeros++;
    else
      v.pb(x);
  }
  sort(all(v), greater<int>());
  if (v.size() < k) {
    cout << 0 << endl;
    return;
  }
  multiset<int> neg, pos;
  for (int x : v) {
    if (x < 0)
      neg.insert(x);
    else if (x > 0)
      pos.insert(x);
  }

  // entope de negativo esse troço
  multiset<int> ans;
  while (neg.size() > 0 && ans.size() < k) {
    ans.insert(*neg.begin());
    neg.erase(neg.begin());
  }

  if (ans.size() % 2 != 0 && pos.size() == 0) {
    if (zeros > 0) {
      cout << 0 << endl;
      return;
    }

    vector<int> arr;
    for (int x : ans) arr.pb(x);
    for (int x : neg) arr.pb(x);
    sort(all(arr), greater<int>());
    int tot = 1;
    for (int i = 0; i < k; i++) tot = mod(tot * arr[i]);
    cout << tot << endl;
  } else {
    multiset<int> anspos;
    // tira o negativozin
    while (ans.size() + anspos.size() < k) {
      if (pos.size() == 0) break;
      anspos.insert(*pos.rbegin());
      pos.erase(pos.find(*pos.rbegin()));
    }

    if (ans.size() % 2 != 0 && pos.size() > 0) {
      ans.erase(ans.find(*ans.rbegin()));
      anspos.insert(*pos.rbegin());
      pos.erase(pos.find(*pos.rbegin()));
    }

    while (ans.size() >= 2 && pos.size() >= 2) {
      int x1 = *ans.rbegin();
      ans.erase(ans.find(*ans.rbegin()));
      int x2 = *ans.rbegin();
      ans.erase(ans.find(*ans.rbegin()));

      int y1 = *pos.rbegin();
      pos.erase(pos.find(*pos.rbegin()));
      int y2 = *pos.rbegin();
      pos.erase(pos.find(*pos.rbegin()));

      if (y1 * y2 >= x1 * x2) {
        anspos.insert(y1);
        anspos.insert(y2);
      } else {
        ans.insert(x1);
        ans.insert(x2);
        break;
      }
    }

    int tot = 1;
    for (int x : ans) {
      tot = mod(tot * x);
    }
    for (int x : anspos) {
      tot = mod(tot * x);
    }
    cout << tot << endl;
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

