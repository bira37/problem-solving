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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    int la = 0;
    int lb = 0;
    int turn = 0;
    bool flag = false;
    int l = 0, r = n - 1;
    int v[n];
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    while (l <= r) {
      turn++;
      if (!flag) {
        // alice
        int acc = 0;
        while (l <= r && acc <= lb) {
          acc += v[l];
          a += v[l++];
        }
        la = acc;
      } else {
        // bob
        int acc = 0;
        while (l <= r && acc <= la) {
          acc += v[r];
          b += v[r--];
        }
        lb = acc;
      }
      flag = !flag;
    }
    cout << turn << " " << a << " " << b << endl;
  }
}

int32_t main() {
  DESYNC;
  solution();
}

