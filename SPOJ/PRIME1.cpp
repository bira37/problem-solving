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

namespace NT {
  
  const int MAX_N = 1123456;
  bitset<MAX_N> prime;
  vector<int> primes;
  vector<int> seg_primes;

  void Sieve(int n){
    prime.set();
    prime[0] = false;
    prime[1] = false;
    for(int p = 2; p*p <= n; p++){
      if(prime[p]){
        for(int i=p*p; i<=n; i+=p){
          prime[i] = false;
        }
      }
    }
    for(int i=2; i<=n; i++) if(prime[i]) primes.pb(i);
  }

  void SegmentedSieve(int l, int r){
    prime.set();
    seg_primes.clear();
    for(int p : primes){
      int start = l - l%p - p;
      while(start < l) start += p;
      if(p == start) start += p;
      for(int i = start; i<=r; i+=p){
        prime[i-l] = false;
      }
    }
    for(int i=0; i<r-l+1; i++){
      if(prime[i] && l+i > 1){
        seg_primes.pb(l+i);
      }
    }
  }
  
}

int32_t main(){
  DESYNC;
  NT::Sieve(100000);
  int t;
  cin >> t;
  bool print = false;
  while(t--){
    if(print) cout << endl;
    else print = true;
    int l, r;
    cin >> l >> r;
    NT::SegmentedSieve(l, r);
    for(int x : NT::seg_primes) cout << x << endl;
  }    
}


