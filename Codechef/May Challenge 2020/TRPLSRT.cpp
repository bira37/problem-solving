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

namespace Old {
void tswap(vector<int>& v, int i, int j, int k) {
  int aux = v[k];
  v[k] = v[j];
  v[j] = v[i];
  v[i] = aux;
}

int solution(int n, int k, vector<int> v) {
  vector<tuple<int, int, int>> ans;
  set<int> wrong;
  for (int i = 1; i <= n; i++) {
    if (v[v[v[i]]] == i && i != v[i] && i != v[v[i]] && v[i] != v[v[i]]) {
      ans.pb(mt(i, v[i], v[v[i]]));
      tswap(v, i, v[i], v[v[i]]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] != i) wrong.insert(i);
  }
  // greedily fix
  while (wrong.size() > 0 && ans.size() < k) {
    int i = *wrong.begin();
    if (v[v[i]] == i) {
      int j = v[i];
      wrong.erase(i);
      wrong.erase(j);
      if (wrong.size() == 0) {
        // nothing to do
        break;
      }
      int l = *wrong.begin();
      wrong.erase(l);
      ans.pb(mt(i, j, l));
      tswap(v, i, j, l);
      if (v[i] != i) wrong.insert(i);
      if (v[j] != j) wrong.insert(j);
      if (v[l] != l) wrong.insert(l);
    } else {
      int j = v[i];
      int l = v[v[i]];
      ans.pb(mt(i, j, l));
      tswap(v, i, j, l);
      wrong.erase(i);
      wrong.erase(j);
      wrong.erase(l);
      if (v[i] != i) wrong.insert(i);
      if (v[j] != j) wrong.insert(j);
      if (v[l] != l) wrong.insert(l);
    }
  }
  bool sorted = true;
  for (int i = 1; i <= n; i++) {
    if (v[i] != i) sorted = false;
  }
  if (sorted) {
    cout << ans.size() << endl;
    for (auto x : ans)
      cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    return ans.size();
  } else {
    cout << -1 << endl;
    return -1;
  }
}
}  // namespace Old

namespace Solution {
void tswap(vector<int>& v, int i, int j, int k) {
  int aux = v[k];
  v[k] = v[j];
  v[j] = v[i];
  v[i] = aux;
}

void rem_from(vector<int> elem, set<int>& s) {
  for (int x : elem) {
    if (s.count(x)) s.erase(x);
  }
}

void add(vector<int>& v, set<int>& p, set<int>& t, set<int>& s, int i) {
  if (v[v[v[i]]] == i && i != v[i] && i != v[v[i]] && v[i] != v[v[i]]) {
    t.insert(i);
    t.insert(v[i]);
    t.insert(v[v[i]]);
    vector<int> to_rem{i, v[i], v[v[i]]};
    rem_from(to_rem, p);
    rem_from(to_rem, s);
  } else if (i != v[i] && v[v[i]] == i) {
    p.insert(i);
    p.insert(v[i]);
    vector<int> to_rem{i, v[i]};
    rem_from(to_rem, t);
    rem_from(to_rem, s);
  } else if (i != v[i]) {
    vector<int> to_rem{i};
    s.insert(i);
    rem_from(to_rem, p);
    rem_from(to_rem, t);
  }
}

int solution(int n, int k, vector<int> v) {
  vector<tuple<int, int, int>> ans;
  set<int> p, t, s;
  for (int i = 1; i <= n; i++) {
    add(v, p, t, s, i);
  }
  while (ans.size() < k) {
    if (t.size() >= 3) {
      // fix triple with one query
      int x = *t.begin();
      t.erase(x);
      t.erase(v[x]);
      t.erase(v[v[x]]);
      // cout << "triple adding " << x << " " << v[x] << " " << v[v[x]] << endl;
      ans.pb(mt(x, v[x], v[v[x]]));
      tswap(v, x, v[x], v[v[x]]);
    } else if (p.size() >= 4) {
      // fix pairs with 2 queries
      int a1 = *p.begin();
      int a2 = v[a1];
      p.erase(a1);
      p.erase(a2);
      int b1 = *p.begin();
      int b2 = v[b1];
      p.erase(b1);
      p.erase(b2);
      // cout << "pair adding " << a1 << " " << a2 << " " << b1 << endl;
      ans.pb(mt(a1, a2, b1));
      tswap(v, a1, a2, b1);
      // cout << "pair adding " << a1 << " " << v[a1] << " " << v[v[a1]] <<
      // endl;
      ans.pb(mt(a1, v[a1], v[v[a1]]));
      tswap(v, a1, v[a1], v[v[a1]]);
    } else if (s.size() >= 3) {
      // fix anything
      int a = *s.begin();
      s.erase(a);
      int b = v[a];
      s.erase(b);
      int c = v[b];
      s.erase(c);
      // cout << "none adding " << a << " " << b << " " << c << endl;
      ans.pb(mt(a, b, c));
      tswap(v, a, b, c);
      add(v, p, t, s, a);
      add(v, p, t, s, b);
      add(v, p, t, s, c);
    } else
      break;
  }
  bool sorted = true;
  for (int i = 1; i <= n; i++) {
    if (v[i] != i) sorted = false;
  }
  if (sorted && ans.size() <= k) {
    cout << ans.size() << endl;
    for (auto x : ans)
      cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    return ans.size();
  } else {
    cout << -1 << endl;
    return -1;
  }
}
}  // namespace Solution

int32_t main() {
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++) {
    int n, k;
    // n = rand() % 12 + 1;
    // k = n / 2;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    // for (int i = 1; i <= n; i++) v[i] = i;
    // random_shuffle(v.begin() + 1, v.end());
    int ans = Solution::solution(n, k, v);
    // int old = Old::solution(n, k, v);
    // if (ans != old) {
    //   cout << "wrong, dude" << endl;
    //   cout << n << " " << k << endl;
    //   for (int i = 1; i <= n; i++) cout << v[i] << " ";
    //   cout << endl;
    //   exit(0);
    // }
  }
}

