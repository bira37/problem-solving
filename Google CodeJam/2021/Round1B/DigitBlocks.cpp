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

char ask() {
  char c;
  cin >> c;
  return c;
}

bool verdict() {
  int ans;
  cin >> ans;
  // cerr << "VERDICT " << ans << endl;
  return ans == 1;
}

void answer(int x) {
  cout << x + 1 << endl;
  cout.flush();
}

void add(string& s, char c) {
  reverse(all(s));
  s += c;
  reverse(all(s));
}

// APPROXIMATELLY 50% CHANCE TO PASS (A LITTLE LOWER), SUBMIT AT LEAST 3 TIMES :)
void solution(int testcase, int n, int b, int p) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  vector<string> pile;
  for (int i = 0; i < n; i++) pile.pb("");

  for (int iter = 0; iter < n * b; iter++) {
    char c = ask();
    int pivot = -1;

    // case for 9: put on the top
    if (c == '9') {
      for (int i = 0; i < n; i++) {
        if (pile[i].size() == b - 1) {
          pivot = i;
          break;
        }
      }
    }

    // if number is big: makes sense to put it on second place
    if (c >= '6' && pivot == -1) {
      for (int i = 0; i < n; i++) {
        if (pile[i].size() == b - 2) {
          pivot = i;
          break;
        }
      }
    }

    // if no case match: complete a tower
    if (pivot == -1) {
      for (int i = 0; i < n; i++) {
        if (pile[i].size() < b - 2) {
          pivot = i;
          break;
        }
      }
    }

    // if all towers are >= b-2: choose the smallest
    if (pivot == -1) {
      for (int i = n - 1; i >= 0; i--) {
        if (pivot == -1 || pile[pivot].size() > pile[i].size()) {
          pivot = i;
        }
      }
    }

    answer(pivot);
    add(pile[pivot], c);
  }
  // cerr << "P: " << p << endl;
  // for (int i = 0; i < n; i++) cerr << "PILE " << pile[i] << endl;
}

#ifdef FILE_INPUT
freopen("equal.in", "r", stdin);
freopen("equal.out", "w", stdout);
#endif

int32_t main() {
  DESYNC;
  int t = 1;
  int n, b, p;
#ifdef MULTIPLE_TEST_CASE
  cin >> t >> n >> b >> p;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++)
    solution(_testcase, n, b, p);

  verdict();
}
