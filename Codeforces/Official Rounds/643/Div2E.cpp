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

void solution() {
  int n, a, r, m;
  cin >> n >> a >> r >> m;
  int v[n + 1];
  int pref[n + 1], suf[n + 2];
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v + 1, v + 1 + n);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];
  suf[n + 1] = 0;
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + v[i];

  int ans = INF;
  int bundle = min(a + r, m);
  for (int i = 1; i <= n; i++) {
    int lef = v[i] * (i - 1) - pref[i - 1];
    int rig = suf[i + 1] - v[i] * (n - i);
    int qtd = min(lef, rig);
    int cur = qtd * bundle;
    lef -= qtd;
    rig -= qtd;
    cur += lef * a;
    cur += rig * r;
    ans = min(ans, cur);
  }

  // test mean
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += v[i];
  int media = sum / n;

  for (int mean = max(0LL, media - 200LL); mean <= min(v[n], media + 200LL);
       mean++) {
    int add = 0;
    int rem = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i] < mean)
        add += mean - v[i];
      else
        rem += v[i] - mean;
    }
    int qtd = min(add, rem);
    int cur = qtd * bundle;
    add -= qtd;
    rem -= qtd;
    cur += add * a;
    cur += rem * r;
    ans = min(ans, cur);
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

