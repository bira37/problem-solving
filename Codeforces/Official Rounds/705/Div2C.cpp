#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
using ll = long long;
using namespace std;
const double PI = acos(-1);
const int M = 1000000007;
// const int M = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k, int m = M) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2, m);
  ax = mod(ax * ax, m);
  if (k % 2) ax = mod(ax * n, m);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

/* LIBRARY INCLUDES */

/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
// #define PRINT_TEST_CASE
#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

string solution(int n, int k, string s) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  vi cnt(26, 0);
  if (n % k) {
    return to_string(-1);
  }

  for (char c : s) cnt[c - 'a']++;

  // check full
  bool full = 1;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % k) full = 0;
  }
  if (full) {
    return s;
  }

  // bruta do fim
  for (int i = n - 1, tenho = 1; i >= 0; i--, tenho++) {
    cnt[s[i] - 'a']--;
    if (s[i] == 'z') {
      continue;
    }

    // testa com prefixo
    int preciso = 0;
    for (int i = 0; i < 26; i++) {
      preciso += (k - (cnt[i] % k)) % k;
    }
    if (preciso <= tenho) {
      vi cnt2(26, 0);
      for (int j = 0; j < 26; j++) cnt2[j] = cnt[j];
      // constroi
      string part;
      int tot = 0;
      bool exists = false;
      bool exists_exactly = false;
      for (int j = 0; j < 26; j++) {
        if (cnt2[j] > 0 && j > s[i] - 'a' && cnt2[j] % k != 0) exists = 1;
        if (char(j + 'a') > s[i] && char(j + 'a') - s[i] == 1 && cnt2[j] > 0 && cnt2[j] % k != 0) {
          // cout << j << " " << s[i] - 'a' << " " << cnt2[j] << endl;
          exists_exactly = 1;
        }
        while (cnt2[j] % k) {
          part += char('a' + j);
          cnt2[j]++;
        }
        tot += cnt2[j];
      }
      if (tot == n && !exists) continue;
      // cout << exists_exactly << endl;
      string ans;
      for (int j = 0; j < i; j++) ans += s[j];
      if (ans.size() + part.size() < n) {
        if (!exists_exactly) {
          for (int j = 0; j < k; j++) part += char(s[i] + 1);
        }
        while (ans.size() + part.size() < n) part += 'a';
      }
      sort(all(part));
      for (int j = 0; j < part.size(); j++) {
        if (part[j] > s[i]) {
          swap(part[0], part[j]);
          break;
        }
      }
      // cout << part << endl;
      sort(part.begin() + 1, part.end());
      return ans + part;
    } else {
      continue;
    }
  }
  return to_string(-1);
}

string nxt(string s) {
  bool tudo_z = true;
  for (char c : s)
    if (c != 'z') tudo_z = 0;
  if (tudo_z) return s;
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'z')
      s[i] = 'a';
    else {
      s[i]++;
      return s;
    }
  }
  return s;
}

bool testa(string s, int k) {
  int n = s.size();
  vi cnt(26, 0);
  for (char c : s) cnt[c - 'a']++;
  for (int i = 0; i < 26; i++)
    if (cnt[i] % k) return 0;
  return 1;
}

string brutal(int n, int k, string s) {
  if (testa(s, k)) return s;
  while (true) {
    string nxts = nxt(s);
    if (nxts == s) return to_string(-1);
    if (testa(nxts, k)) return nxts;
    s = nxts;
  }
}

#ifdef FILE_INPUT
freopen("equal.in", "r", stdin);
freopen("equal.out", "w", stdout);
#endif

int32_t main() {
  // DESYNC;
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    // n = 6;
    // int tst[] = {1, 2, 3, 6};
    // k = tst[rng() % 4];

    // for (int i = 0; i < n; i++) s += char(rng() % 26 + 'a');

    // if (solution(n, k, s) != brutal(n, k, s)) {
    //   cout << "seu merda" << endl;
    //   cout << n << " " << k << " " << s << endl;
    //   cout << brutal(n, k, s) << endl;
    //   cout << solution(n, k, s) << endl;
    // }
    cout << solution(n, k, s) << endl;
  }
}

