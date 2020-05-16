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

int odd(int n) {
  int terms = (n + 1) / 2;
  int sum = terms * terms;
  return sum;
}

int sumOdd(int l, int r) { return odd(r) - odd(l - 1); }

int PA(int n) { return (n * (n + 1)) / 2; }
int rangeSum(int l, int r) { return PA(r) - PA(l - 1); }

int sumEven(int l, int r) { return rangeSum(l, r) - sumOdd(l, r); }

vector<int> solution(int testcase, ii a, ii b) {
  cout << "Case #" << testcase << ": ";
  if (a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss)) swap(a, b);
  int l = 0, r = 2e9;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (a.ff - PA(m) < b.ff) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  ans--;
  int client = ans;
  a.ff -= PA(ans);
  if (a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss)) swap(a, b);

  l = ans + 1, r = 2e9;
  int ans2 = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int val_a, val_b;
    if ((ans + 1) % 2 == 0) {
      val_a = sumEven(ans + 1, m);
      val_b = sumOdd(ans + 1, m);
    } else {
      val_a = sumOdd(ans + 1, m);
      val_b = sumEven(ans + 1, m);
    }
    if (a.ff - val_a <= 0 || b.ff - val_b <= 0) {
      ans2 = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  ans2 -= 2;
  if (ans2 > ans) {
    client = ans2;
    int val_a, val_b;
    if ((ans + 1) % 2 == 0) {
      val_a = sumEven(ans + 1, ans2);
      val_b = sumOdd(ans + 1, ans2);
    } else {
      val_a = sumOdd(ans + 1, ans2);
      val_b = sumEven(ans + 1, ans2);
    }
    a.ff -= val_a;
    b.ff -= val_b;
  }
  if (a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss)) swap(a, b);
  int st = max(ans2 + 1, ans + 1);
  while (true) {
    if (a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss)) swap(a, b);
    if (a.ff - st >= 0) {
      client++;
      a.ff -= st;
    } else
      break;
    st++;
  }
  if (a.ss == 1) swap(a, b);
  vector<int> v;
  v.pb(client);
  v.pb(a.ff);
  v.pb(b.ff);
  // cout << a.ff << " " << a.ss << " " << b.ff << " " << b.ss << endl;
  return v;
}

vector<int> oracle(ii a, ii b) {
  int st = 1;
  int client = 0;
  while (true) {
    if (a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss)) swap(a, b);
    if (a.ff - st >= 0) {
      client++;
      a.ff -= st;
    } else
      break;
    st++;
  }
  if (a.ss == 1) swap(a, b);
  vector<int> v;
  v.pb(client);
  v.pb(a.ff);
  v.pb(b.ff);
  return v;
}

int32_t main() {
  DESYNC;
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++) {
    int l, r;
    cin >> l >> r;

    auto sol = solution(_testcase, ii(l, 0), ii(r, 1));
    cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;
  }
}

