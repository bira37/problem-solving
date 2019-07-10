#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define IOS_SYNC ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>
#define vpll vector< pll >
#define vpii vector< pii >
#define MOD 1000000007
 
using namespace std;
 
typedef long long ll;
 
////////////////////////CODE//////////////////////////////////////////////////////
 
ll prime[5000001];
ll memo[5000001];
 
void run_sieve(int n){
	for(int i = 0; i<=n; i++){
		prime[i] = i;
		memo[i] = -1;
	}
	for(ll p = 2; p*p <= n; p++){
		if(prime[p] == p){
			for(ll i=p*p; i<=n; i+=p){
				prime[i] = min(p, prime[i]);
			}
		}
	}
}
 
ll pa(ll n){
	return (n*(n-1))/2;
}
 
ll solve(ll n){
	if(n <= 1) return 0;
	if(memo[n] != -1) return memo[n];
	return memo[n] = ((n/prime[n])*pa(prime[n]))%MOD + solve(n/prime[n])%MOD;
}
 
int main(){
	IOS_SYNC(false);
	ll t,l,r;
	cin >> t >> l >> r;
	run_sieve(r);
	ll ans = solve(l)%MOD;
	ll pot = 1;
	ll f;
	for(int i=l+1; i<=r; ++i){
		pot=t*pot;
		pot %= MOD;
		f = solve(i);
		f %= MOD;
		ans += (pot*f)%MOD;
		ans %=MOD;
	}
	cout << ans << endl;
	return 0;
}
