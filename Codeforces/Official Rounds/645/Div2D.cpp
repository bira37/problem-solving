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

int PA(int n) { return ((n) * (n + 1)) / 2LL; }
void solution() {
  int n, k;
  cin >> n >> k;

  int ans = 0;
  vector<int> v(2 * n);
  vector<int> shit(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i + n] = v[i];
  }

  shit[0] = PA(v[0]);
  for (int i = 1; i < 2 * n; i++) shit[i] = shit[i - 1] + PA(v[i]);

  int days = 0;
  int pt = 0;
  for (int i = 0; i < n; i++) {
    // starting at i
    if (pt < i) {
      pt = i;
      days = 0;
    }

    while (days + v[pt] <= k) {
      days += v[pt++];
    }

    // get ans
    int acc = shit[pt] - (i - 1 >= 0 ? shit[i - 1] : 0);
    acc -= PA(days + v[pt] - k);
    ans = max(ans, acc);

    // remove current day
    days -= v[i];
  }

  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

