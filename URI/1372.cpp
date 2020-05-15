#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	while(cin >> n >> m, n+m !=0){
		int grid[n][m];
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> grid[i][j];
		
		int candy[n];

		//for(int i=0; i<n; i++) candy[i] = 0;
		
		for(int i=0; i<n; i++){
			int dp[m];
			for(int j=0; j<m; j++){
				if(j-2 < 0){
					dp[j] = grid[i][j];
					if(j == 1){
						dp[j] = max(dp[j-1], grid[i][j]);
					}
				}
				else dp[j] = max(dp[j-1], dp[j-2] + grid[i][j]);
				//if(j-3 >=0) dp[j] = max(dp[j], dp[j-3] + grid[i][j]);
			}
			candy[i] = dp[m-1];
		}
		//for(int i=0; i<n; i++) cout << candy[i] << endl;
		
		int dp[n];
		for(int i=0; i<n; i++){
			if(i-2 < 0){
				dp[i] = candy[i];
				if(i==1){
					dp[i] = max(dp[i-1], candy[i]);
				}
			}
			else dp[i] = max(dp[i-1], dp[i-2] + candy[i]);
			//if(i-3 >= 0) dp[i] = max(dp[i], dp[i-3] + candy[i]);
		}
		cout << dp[n-1] << endl;
	}
}
