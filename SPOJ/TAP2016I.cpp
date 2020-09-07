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
#define INF 4e18
#define ROOT 1
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);
const int M = 1000000007;
// const int M = 998244353;
using ll = long long;
using namespace std;
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

/* Author: Ubiratan Correia Barbosa Neto
 * Diophantine and CRT
 */

namespace NT {

int GCD(int a, int b) {
  if (a == 0)
    return b;
  else
    return GCD(b % a, a);
}

tuple<int, int> shift_solution(int a, int b, int g, int s1, int s2) {
  // shifts solution
  int l = 0, r = 1e9;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (s2 + m * (a / g) >= 0) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  if (ans != -1) {
    s1 = s1 - ans * (b / g);
    s2 = s2 + ans * (a / g);
  }

  l = 0, r = 1e9;
  ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (s1 + m * (a / g) >= 0) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  if (ans != -1) {
    s1 = s1 + ans * (b / g);
    s2 = s2 - ans * (a / g);
  }

  l = 0, r = 1e9;
  ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (s1 - m * (a / g) <= s2 + m * (b / g)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  if (ans != -1) {
    s1 = s1 - ans * (b / g);
    s2 = s2 + ans * (a / g);
  }

  return make_tuple(s1, s2);
}

tuple<int, int> ExtendedEuclidean(int a, int b) {
  // solves ax+by = gcd(a,b)
  // careful when a or b equal to 0
  if (a == 0) return make_tuple(0, 1);
  int x, y;
  tie(x, y) = ExtendedEuclidean(b % a, a);
  return make_tuple(y - (b / a) * x, x);
}

bool FailCoprime = false;
int CoprimeInverse(int a, int m) {
  FailCoprime = false;
  if (NT::GCD(a, m) != 1) {
    FailCoprime = true;
    return -1;
  }
  int s1, s2;
  tie(s1, s2) = ExtendedEuclidean(a, m);
  return (s1 % m + m) % m;
}

bool FailDiophantine = false;

tuple<int, int> Diophantine(int a, int b, int c, bool shift = true) {
  FailDiophantine = false;
  // finds a solution for ax+by = c
  // given a solution (x,y), all solutions have the form (x + m*(b/gcd(a,b)), y
  // - m*(a/(gcd(a,b))), multiplied by (c/g)

  int g = GCD(a, b);

  if (g == 0 || c % g != 0) {
    FailDiophantine = true;
    return make_tuple(0, 0);
  }

  int x, y;

  tie(x, y) = ExtendedEuclidean(a, b);
  int s1 = x * (c / g), s2 = y * (c / g);

  // shift
  if (!shift)
    return make_tuple(s1, s2);
  else
    return shift_solution(a, b, g, s1, s2);
}

bool FailCRT = false;

tuple<int, int> CRT(vector<int>& a, vector<int>& n) {
  FailCRT = false;
  for (int i = 0; i < a.size(); i++) a[i] = mod(a[i], n[i]);
  int ans = a[0];
  int modulo = n[0];

  for (int i = 1; i < a.size(); i++) {
    int x, y;
    tie(x, y) = ExtendedEuclidean(modulo, n[i]);
    int g = GCD(modulo, n[i]);

    if (g == 0 || (a[i] - ans) % g != 0) {
      FailCRT = true;
      return make_tuple(0, 0);
    }

    ans = mod(ans + (x * ((a[i] - ans) / g)) % (n[i] / g) * modulo,
              modulo * (n[i] / g));
    modulo = modulo * (n[i] / g);
  }

  return make_tuple(ans, modulo);
}

}  // namespace NT

struct equation {
  int a, b, c, g, s1, s2;
  equation() {}
  equation(int a, int b, int c, int g, int s1, int s2)
      : a(a), b(b), c(c), g(g), s1(s1), s2(s2) {}
};

int A[200 + 10][200 + 10], B[200 + 10];
equation eq[200 + 10][200 + 10][200 + 10];
int sum[200 + 10];

void solution(int n, int r, int k) {
  for (int i = 0; i < r; i++) {
    cin >> B[i];
    B[i]--;
  }

  for (int i = 0; i < r; i++) {
    int s = 0;
    for (int j = 0; j < k; j++) {
      cin >> A[i][j];
      s += A[i][j];
    }
    sum[i] = s;
  }

  vector<int> dist(r + 1, INF);
  set<ii> s;
  s.insert(ii(0, 0));
  dist[0] = 0;
  while (s.size() > 0) {
    int d = s.begin()->ff;
    int u = s.begin()->ss;
    // cout << "at " << u << " " << d << endl;
    s.erase(s.begin());
    if (dist[u] >= INF) break;
    if (dist[u] != d) continue;

    for (int v = 0; v < r; v++) {
      if (v == u) continue;
      int pi = 0, pj = 0;

      int a = mod(sum[u] - sum[v], n);
      int b = -n;
      int g = NT::GCD(a, b);

      int x1, x2;
      tie(x1, x2) = NT::ExtendedEuclidean(a, b);

      for (int pf = 0; pf <= k; pf++) {
        if (pf > 0) {
          pi += A[u][pf - 1];
          pj += A[v][pf - 1];
        }
        // T(sum_i - sum_j) - n*b = p_jk - p_ik + B[j] - B[i]
        int c = pj - pi + B[v] - B[u];
        c = mod(c, n);
        if (c % g) continue;

        int s1 = (c / g) * (x1);

        s1 = mod(s1, n);

        int i = pf;

        // shift the solution to get the first after d
        int mid = (d - i) / k;

        int D = ((mid - s1) * abs(g) + abs(b) - 1) / abs(b);

        if ((s1 + (D - 1) * (abs(b) / abs(g))) * k + i >= d) {
          D--;
        }

        while ((s1 + (D) * (abs(b) / abs(g))) * k + i < d) {
          D++;
        }

        int nxt = (s1 + (D) * (abs(b) / abs(g))) * k + i;

        // cout << "next match of " << u << " " << v << " will be " << nxt <<
        // endl;
        // assert(nxt >= d);
        if (dist[v] > nxt) {
          dist[v] = nxt;
          s.insert(ii(nxt, v));
        }
      }
    }
  }

  int ans = 0;
  int mx = 0;
  for (int i = 0; i < r; i++) {
    if (dist[i] != INF) {
      ans++;
      mx = max(mx, dist[i]);
    }
  }
  cout << ans << " " << mx << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  int n, r, k;
  while (cin >> n >> r >> k) solution(n, r, k);
}
