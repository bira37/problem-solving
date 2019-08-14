#include <bits/stdc++.h>
#define debug 0
#define int unsigned long long
using namespace std;

int memo[1000001];

int dp(int n){
	if(n == 1) return 1;
	if(memo[n] != 0) return memo[n];
	int ans = dp(n-1)*n;
	while(!(ans%10)) ans/=10;
	memo[n] = ans % 100000;
	return memo[n];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	int n;
	int t=0;
	for(int i=0; i<1000001; i++) memo[i] = 0;
	dp(1000000);
	while(cin >> n){
		int ans = memo[n];
		while(ans%10 == 0) ans/=10;
		cout << "Instancia " << ++t << endl;
		cout << ans%10 << endl;
		cout << endl;
	}
	return 0;
}
