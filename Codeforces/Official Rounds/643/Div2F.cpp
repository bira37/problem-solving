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

bool check_prime(int x) {
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}

void solution() {
  vector<int> primes;
  int ans = 1;
  for (int i = 2; i <= 2000; i++) {
    if (check_prime(i)) primes.pb(i);
  }
  reverse(primes.begin(), primes.end());
  int q = 22;
  while (q--) {
    int query = 1;
    vector<int> used;
    while (query < 1e18 / primes.back()) {
      query *= primes.back();
      used.pb(primes.back());
      primes.pop_back();
    }
    cout << "? " << query << endl;
    cout.flush();
    int g;
    cin >> g;
    for (int p : used) {
      if (g % p != 0) continue;
      if (q == 0) {
        ans *= 2LL;
        continue;
      }
      int pot = p;
      while (pot < 1e18 / p) pot *= p;
      cout << "? " << pot << endl;
      cout.flush();
      int g2;
      cin >> g2;
      int cnt = 0;
      while (g2 % p == 0) {
        g2 /= p;
        cnt++;
      }
      ans *= (cnt + 1LL);
      q--;
    }
  }
  cout << "! " << max(ans * 2LL, ans + 7LL) << endl;
  cout.flush();
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}

