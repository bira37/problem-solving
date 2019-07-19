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
#define N 112345

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

/* Erasthostenes Sieve Implementation + Euler's Totient */
/* Calculate primes from 2 to N */
/* lf[i] stores the lowest prime factor of i(logn factorization) */

bitset<N> prime;
vector<int> primes;
int lf[N];
int totient[N];

void run_sieve(int n){
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

void run_totient(int n){
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

bool psycho(int n){
  map<int,int> cnt;
  int odd = 0, even = 0;
  while(n > 1){
    cnt[lf[n]]++;
    n /= lf[n];
  }
  for(auto x : cnt){
    if(x.ss%2) odd++;
    else even++;
  }
  return even > odd;
}


int32_t main(){
  DESYNC;
  run_sieve(112344);
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    bitset<100001> dp, aux;
    dp.set(0);
    for(int i=0; i<n; i++){
      int x;
      cin >> x;
      if(!psycho(x)) continue;
      aux |= dp;
      aux <<= x;
      dp |= aux;
    }
    if(dp[k]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}


