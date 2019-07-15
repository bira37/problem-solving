#include <bits/stdc++.h>

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

/* Erasthostenes Sieve Implementation + Euler's Totient */
/* Calculate primes from 2 to N */
/* lf[i] stores the lowest prime factor of i(logn factorization) */

namespace NT {

  const int MAX_N = 15000001;
  
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

int vis[20000000];

int32_t main(){
  for(int i=0; i<20000000; i++) vis[i] = 0;
  NT::Sieve(15000000);
  int n;
  scanf("%d", &n);
  int v[n];
  int g = 0;
  cin >> v[0];
  g = v[0];
  for(int i=1; i<n; i++){
    scanf("%d", v+i);
    g = __gcd(g, v[i]);
  }
  vector<int> fac;
  for(int i=0; i<n; i++){
    v[i] /= g;    
    vis[v[i]]++;
    while(v[i] > 1){
      if(fac.size() == 0 || fac.back() != NT::lf[v[i]]){
        fac.pb(NT::lf[v[i]]);
      }
      v[i] /= NT::lf[v[i]];
    }
  }
  
  int ans = 0;
  sort(fac.begin(), fac.end());
  for(int i = 0; i<fac.size(); i++){
    if(i && fac[i-1] == fac[i]) continue;
    int x = fac[i];
    int cnt = 0;
    if(x == 1) continue;
    for(int j=x; j<20000000; j+=x ){
      cnt += vis[j];
    }
    ans = max(ans, cnt);
  }
  if(n - ans == n) puts("-1");
  
  else printf("%d\n", n-ans);
}

