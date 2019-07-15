#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}

namespace NT {

  const int MAX_N = 11234567;
  
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

bool pal(int n){
  string s = to_string(n);
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int32_t main(){
  DESYNC;
  NT::Sieve(10000000);
  int prime_cnt = 0;
  int pal_cnt = 0;
  int p,q;
  cin >> p >> q;
  int ans = -1;
  for(int i=1; i<=10000000; i++){
    prime_cnt += NT::prime[i];
    pal_cnt += pal(i);
    if(q*prime_cnt <= p*pal_cnt){
      ans = i;
    }
  }
  if(ans == -1) cout << "Palindromic tree is better than splay tree" << endl;
  else cout << ans << endl; 
}

