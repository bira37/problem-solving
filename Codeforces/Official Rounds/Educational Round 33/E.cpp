#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
#define int long long
bool prime[1123456];
int factor[1123456];
int comb[1000026][26] = {0};

void sieve(int n){
	for(int i=0; i<=n; i++){
		prime[i] = true;
		factor[i] = i;
	}
	for(int i=2; i<= sqrt(n); i++){
		if(!prime[i]) continue;
		for(int j = i+i; j<=n; j+=i){
			prime[j] = false;
			factor[j] = min(factor[j], i);
		}
	}
}

int expo(int a, int p){
	if(p == 1) return a;
	if(p == 0) return 1;
	int k = expo(a, p/2);
	k%=M;
	k*=k;
	k%=M;
	if(p%2) k*=a;
	k%=M;
	return k;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	sieve(1000000);
	
	for(int i=0; i<=1000025; i++){
		for(int j = 0; j<=min(i,25LL); j++){
			if(j > i) continue;
			if(i == j || j == 0) comb[i][j] = 1;
			else comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%M;
		}
	}
	while(t--){
		int x,y;
		cin >> x >> y;
		map<int, int> f;
		while(x > 1){
			f[factor[x]]++;
			x/=factor[x];
		}
		int ans = 1;
		for(pair<int,int> it: f){
			ans*=comb[it.second + y -1][it.second];
			ans%=M;
		}
		ans*= expo(2, y-1);
		ans%=M;
		cout << ans << endl;
	}
}