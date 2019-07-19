#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int dp[2][505][505];
int w[505];
 
int n,m,b, mod;
 
int32_t main(){
	cin >> n >> m >> b >> mod;
	for(int i=1; i<=n; i++){
		cin >> w[i];
	}
	
	for(int i=0; i<=m; i++){
		for(int j=0; j<=b; j++){
			dp[0][i][j] = dp[1][i][j] = 0;
		}
	}
	
	dp[0][0][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			for(int k=0; k<=b; k++){
				dp[(i%2)][j][k] = dp[!(i%2)][j][k];
				dp[(i%2)][j][k] %= mod;
				if(j-1 >= 0 && k - w[i] >= 0) dp[(i%2)][j][k] += dp[(i%2)][j-1][k-w[i]];
				dp[(i%2)][j][k] %= mod;
			}
		}
	}
	int ans = 0;
	for(int i=0; i<=b; i++){
		ans += dp[(n%2)][m][i];
		ans %= mod;
	}
	cout << ans << endl;
}
