#include <bits/stdc++.h>

#define int long long
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

using namespace std;

inline int mod(int n){ return (n%1000000007); }

bitset<5000001> prime;
int lf[5000001];
int pref[5000001];

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
}

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

int factors(int n){
  int res = 0;
  while(n > 1){
    res++;
    n /= lf[n];
  }
  return res;
}

int32_t main(){
	DESYNC;
	run_sieve(5000000);
	pref[0] = 0;
	pref[1] = 0;
	for(int i=2; i<=5000000; i++){
	  pref[i] = pref[i-1] + factors(i);
	}
	int t;
	cin >> t;
	while(t--){
	  int a,b;
	  cin >> a >> b;
	  cout << pref[a] - pref[b] << endl;
	}
}