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
  
};
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  NT::Sieve(11234);
  vector< ii > ans;
  for(int i=1; i<=n-1; i++) ans.pb(ii(i, i+1));
  ans.pb(ii(n,1));
  int i=1;
  while(!NT::prime[ans.size()]){
    ans.pb(ii(i, n-i));
    i++;
  }
  cout << ans.size() << endl;
  for(ii p : ans) cout << p.ff << " " << p.ss << endl;
}
 
