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
int n, m;
string v[11];
bool found;
string cur;
vector<bool> vis(11);

void brute(int p) {
  if (p == m) {
    found = true;
    return;
  }

  map<char, int> cnt;
  for (int i = 0; i < n; i++) cnt[v[i][p]]++;

  // try each char
  for (ii x : cnt) {
    // taking x.ff
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (x.ff != v[i][p] && vis[i]) ok = false;
    }
    if (!ok) continue;

    cur += x.ff;
    for (int i = 0; i < n; i++) {
      if (x.ff != v[i][p]) vis[i] = true;
    }
    brute(p + 1);
    if (found) return;
    for (int i = 0; i < n; i++) {
      if (x.ff != v[i][p]) vis[i] = false;
    }
    cur.pop_back();
  }
}
void solution() {
  cin >> n >> m;
  found = false;
  cur = "";
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    vis[i] = false;
  }
  brute(0);
  if (found)
    cout << cur << endl;
  else
    cout << -1 << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}

