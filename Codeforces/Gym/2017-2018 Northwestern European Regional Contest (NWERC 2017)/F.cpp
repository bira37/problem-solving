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
  
};
 
vector<int> fac[1123456];
int l[1123456], r[1123456];
int p[1123456];
 
bool solve(int ll, int rr, int anc){
  if(rr < ll) return true;
  int i = ll, j = rr;
  while(i <= j){
    if(l[i] <= ll && rr <= r[i]){
      p[i] = anc;
      return solve(ll, i-1, i) && solve(i+1, rr, i);
    }
    else if(l[j] <= ll && rr <= r[j]){
      p[j] = anc;
      return solve(ll, j-1, j) && solve(j+1, rr, j);
    }
    else i++, j--;
  }
  return false;
}
 
int32_t main(){
  DESYNC;
  NT::Sieve(10000000);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    while(x > 1){
      if(fac[i].size() == 0 || fac[i].back() != NT::lf[x]) fac[i].pb(NT::lf[x]);
      x /= NT::lf[x];
    }
  }
  
  map<int,int> occ;
  for(int i=0; i<n; i++){
    l[i] = -1;
    for(int x : fac[i]){
      if(occ.count(x)) l[i] = max(l[i], occ[x]);
      occ[x] = i;
    }
    l[i]++;
  }
  occ.clear();
  for(int i=n-1; i>=0; i--){
    r[i] = n;
    for(int x : fac[i]){
      if(occ.count(x)) r[i] = min(r[i], occ[x]);
      occ[x] = i;
    }
    r[i]--;
  }
  if(!solve(0, n-1, -1)) cout << "impossible" << endl;
  else {
    for(int i=0; i<n; i++) cout << p[i]+1 << " ";
    cout << endl;
  }
}
 
