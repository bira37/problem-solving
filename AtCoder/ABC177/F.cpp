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
  int n, m;
  cin >> n >> m;
  ii bl[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> bl[i].ff >> bl[i].ss;
  }

  set<int> v;
  multiset<int> rmq;
  map<int, int> cst;
  rep(i, 1, m + 1, 1) {
    v.insert(i);
    cst[i] = 0;
    rmq.insert(cst[i]);
  }

  int acc = 0;
  for (int i = 1; i <= n; i++) {
    if (v.size() == 0) {
      cout << -1 << endl;
      continue;
    }
    // cout << "kept at " << i << " " << endl;
    // for (int x : v) cout << x << " " << cst[x] << " | ";
    // cout << endl;
    // cout << "at " << i << endl;
    if (bl[i].ff <= *v.begin() && *v.rbegin() <= bl[i].ss) {
      // cout << "keeping only one" << endl;
      // if all are in range, pick just the minimum value
      for (int x : v) {
        int cur = cst[x];
        cur += (bl[i].ss - x + 1);
        rmq.erase(rmq.find(cst[x]));
        cst.erase(x);
        if (bl[i].ss + 1 > m) continue;
        if (!cst.count(bl[i].ss + 1) || cst[bl[i].ss + 1] > cur) {
          if (cst.count(bl[i].ss + 1)) rmq.erase(rmq.find(cst[bl[i].ss + 1]));
          cst[bl[i].ss + 1] = cur;
          rmq.insert(cst[bl[i].ss + 1]);
        }
      }
      v.clear();
      if (bl[i].ss + 1 <= m) v.insert(bl[i].ss + 1);
    } else {
      // some are not in range, so we keep them
      // cout << "keeping only range" << endl;
      while (true) {
        auto it = v.lower_bound(bl[i].ff);
        if (it == v.end()) break;
        if (*it > bl[i].ss) break;
        int x = *it;
        v.erase(it);
        int cur = cst[x];
        cur += (bl[i].ss - x + 1);
        rmq.erase(rmq.find(cst[x]));
        cst.erase(x);
        if (bl[i].ss + 1 > m) continue;
        if (!cst.count(bl[i].ss + 1) || cst[bl[i].ss + 1] > cur) {
          if (cst.count(bl[i].ss + 1)) rmq.erase(rmq.find(cst[bl[i].ss + 1]));
          cst[bl[i].ss + 1] = cur;
          rmq.insert(cst[bl[i].ss + 1]);
          v.insert(bl[i].ss + 1);
        }
      }
    }

    if (v.size() == 0) {
      cout << -1 << endl;
      continue;
    }

    cout << *rmq.begin() + i << endl;
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
