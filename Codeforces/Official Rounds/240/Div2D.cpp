#include <bits/stdc++.h>

using namespace std;
	
int main(){
	ios_base::sync_with_stdio(false);
	set<int> div[2001];
	int n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		for(int d = 1; d <= sqrt(i); d++){
			if(i%d == 0){
				div[i].insert(d);
				div[i].insert(i/d);
			}
		}
	}
	
	long long dp[k+1][n+1];
	
	for(int i=1; i<=n; i++) dp[1][i] = 1;
	
	for(int i=2; i<=k; i++){
		for(int j=1; j<=n; j++){
			dp[i][j] = 0;
			for(int d : div[j]){
				dp[i][j] += dp[i-1][d];
				dp[i][j] %= 1000000007;
			}
		}
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++) ans = (ans + dp[k][i])%1000000007;
	cout << ans << endl;
}