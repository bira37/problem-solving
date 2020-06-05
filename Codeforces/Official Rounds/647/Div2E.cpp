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

inline int mod(int n, int m = M) {
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

int exp(int n, int k) {
  if (k == 0) return 1LL;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

void solution() {
  int n, p;
  cin >> n >> p;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (p == 1) {
    if (n % 2)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return;
  }
  vector<int> A, B;
  sort(v, v + n);
  reverse(v, v + n);
  vector<ii> bkt;
  for (int i = 0; i < n; i++) {
    if (bkt.size() == 0 || bkt.back().ff != v[i]) {
      bkt.pb(ii(v[i], 1));
    } else
      bkt.back().ss++;
  }
  bool aIsGreater = true;
  for (int i = 0; i < bkt.size(); i++) {
    int val = bkt[i].ff;
    int qtd = bkt[i].ss;
    if (qtd == 0) continue;
    if (qtd % 2 == 0) continue;
    if (aIsGreater) {
      aIsGreater = false;
      A.swap(B);
    }
    // give to A
    A.pb(val);
    aIsGreater = true;
    // try to adjust B
    int cnt = p;
    int expect = val - 1;
    for (int j = i + 1; j < bkt.size() && expect >= 0; j++) {
      if (cnt > 10000000) {
        // give everything
        for (int quant = 0; quant < bkt[j].ss; quant++) B.pb(bkt[j].ff);
        bkt[j].ss = 0;
      } else if (expect != bkt[j].ff) {
        cnt *= p;
        expect--;
        j--;
      } else {
        int tira = min(cnt, bkt[j].ss);
        for (int quant = 0; quant < tira; quant++) B.pb(bkt[j].ff);
        bkt[j].ss -= tira;
        cnt -= tira;
        if (cnt == 0) break;
        cnt *= p;
        expect--;
      }
    }
  }
  int valA = 0;
  // cout << "A:";
  for (int x : A) {
    // cout << " " << x;
    valA = mod(valA + exp(p, x));
  }
  // cout << endl;
  // cout << "B:";
  int valB = 0;
  for (int x : B) {
    // cout << " " << x;
    valB = mod(valB + exp(p, x));
  }
  // cout << endl;
  // cout << aIsGreater << endl;
  if (aIsGreater) swap(valA, valB);
  cout << mod(valB - valA) << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) solution();
}
