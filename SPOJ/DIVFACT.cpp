#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

/* Erasthostenes Sieve Implementation + Euler's Totient */
/* Calculate primes from 2 to N */
/* lf[i] stores the lowest prime factor of i(logn factorization) */

namespace NT {

  const int MAX_N = 112345;
  
  bitset<MAX_N> prime;
  vector<int> primes;
  int lf[MAX_N];
  int totient[MAX_N];

  void Sieve(int n){
    for(int i=0; i<=n; i++) lf[i] = i;
    prime.set();
    prime[0] = false;
    prime[1] = false;
    for(int p = 2; p*p <= n; p++){
      if(prime[p]){
        for(int i=p*p; i<=n; i+=p){
          prime[i] = false;
          lf[i] = min(lf[i], p);
        }
      }
    }
    for(int i=2; i<=n; i++) if(prime[i]) primes.pb(i);
  }

  void EulerTotient(int n){
    for(int i=0; i<=n; i++) totient[i] = i;
    for(int p = 2; p <= n; p++){
      if(totient[p] == p){
        totient[p] = p-1;
        for(int i=p+p; i<=n; i+=p){
          totient[i] = (totient[i]/p) * (p-1);
        }
      }
    }
  }
  
};

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  NT::Sieve(100000);
  while(t--){
    int n;
    cin >> n;
    int ans = 1;
    for(int p : NT::primes){
      int cnt = 0;
      if(p > n) break;
      int cur = p;
      while(cur <= n){
        cnt += n/cur;
        cur*=p;
      }
      ans = ans*(cnt+1);
      ans = mod(ans, M);
    }
    cout << ans << endl;
  }
}


