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

struct Vector2D {
  int x, y;
  Vector2D() {}
  Vector2D(int x, int y) : x(x), y(y) {}

  bool operator<(Vector2D v) const { return tie(x, y) < tie(v.x, v.y); }
  bool operator==(Vector2D v) const { return tie(x, y) == tie(v.x, v.y); }
  bool operator>(Vector2D v) const { return tie(x, y) > tie(v.x, v.y); }
  bool operator<=(Vector2D v) const { return tie(x, y) <= tie(v.x, v.y); }
  bool operator>=(Vector2D v) const { return tie(x, y) >= tie(v.x, v.y); }

  Vector2D normalize() {
    if (x == 0) {
      return Vector2D(0, 1);
    }
    if (y == 0) {
      return Vector2D(1, 0);
    }
    int g = gcd(x, y);
    Vector2D norm(x / g, y / g);
    if (norm.y < 0) norm.x = -norm.x, norm.y = -norm.y;
    return norm;
  }
  Vector2D normalized_orthogonal() {
    if (x == 0) {
      return Vector2D(1, 0);
    }
    if (y == 0) {
      return Vector2D(0, 1);
    }
    int g = gcd(x, y);
    Vector2D ort = Vector2D(-y / g, x / g);
    if (ort.y < 0) ort.x = -ort.x, ort.y = -ort.y;
    return ort;
  }
};

void solution() {
  map<pair<Vector2D, Vector2D>, ii> m;
  int n;
  cin >> n;
  int pot2[n + 1];
  pot2[0] = 1;
  for (int i = 1; i <= n; i++) pot2[i] = mod(pot2[i - 1] * 2LL, M);
  int lixo = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      lixo++;
      continue;
    }
    Vector2D vec(a, b);
    vec = vec.normalize();
    auto ort = vec.normalized_orthogonal();
    if (m.count(mp(vec, ort)))
      m[mp(vec, ort)].ff++;
    else if (m.count(mp(ort, vec)))
      m[mp(ort, vec)].ss++;
    else
      m[mp(vec, ort)] = ii(1, 0);
  }
  set<Vector2D> vis;
  int ans = 1LL;
  for (auto p : m) {
    int cnt = p.ss.ff;
    int cnt2 = p.ss.ss;
    ans = mod(ans * mod(pot2[cnt] + pot2[cnt2] - 1LL, M), M);
  }
  ans = mod(ans + lixo - 1LL, M);
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  solution();
}

