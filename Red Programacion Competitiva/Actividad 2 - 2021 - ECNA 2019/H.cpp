#include <bits/stdc++.h>
#define int long long
#define double long double
#define ms(v,x) memset(v,x,sizeof(v))
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define td(v) v.begin(), v.end()
#define tdr(v) v.rbegin(), v.rend()
#define endl "\n"
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 2e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline long long mod(long long n, long long m) {
    long long ret = n % m;
    if (ret < 0) ret += m;
    return ret;
}

double rad(double x) { return x * pi / 180.0; }

int exp(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = result * a % MOD;

        b >>= 1;
        a = a *a  % MOD;
    }
    return result;
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

void solve(){
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<int> aux;
    for(int i = 1; i < 100; i++){
        if(a-2*i > 0 and b-2*i > 0)
            aux.push_back((a-2*i) * (b-2*i) * i);
    }
    sort(tdr(aux));
    vector<int> v1;
    vector<int> v2 = {c, d, e};
    for(int i = 0; i < 3; i++){
        v1.push_back(aux[i]);
    }
    // for(int i = 0; i < 3; i++){
    //     cout << v1[i] << ' ' << v2[i] << endl;
    // }
    tuple<int,int> ans = NT::CRT(v2, v1);
    // first = numero, soma o second até chegar no range;
    int res = get<0>(ans);
    int sum = get<1>(ans);
    if(res < f){
        f -= res;
        res += (f+sum-1)/sum*sum;
    }
    cout << res << endl;
    // int ini = 0, fim = 1;
    // while(fim*sum < g){
    //     fim*=2;
    // }
    // while(ini <= fim){
    //     int mid = (ini+fim)/2;
    //     if(res+sum*mid < f){
    //         ini = mid+1;
    //     }
    //     else if(res+sum*mid > g){
    //         fim = mid - 1;
    //     }
    //     else{
    //         cout << res + sum*mid << endl;
    //         return;
    //     }
    // }
    assert(!NT::FailCRT);
}

int32_t main() {
	// fastio;
	// freopen("in.txt", "r", stdin);
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
}
