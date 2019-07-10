#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	long long mat[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m;j++) cin >> mat[i][j];
	}
 
	int dp[m][n];
	
	for(int j=0; j<m; j++){
		dp[j][0] = 0;
		for(int i=1; i<n; i++){
			if(mat[i][j] >= mat[i-1][j]) dp[j][i] = dp[j][i-1];
			else dp[j][i] = i;
		}
	}
	
	int dp2[n];
	for(int i=0; i<n; i++){
		int menor = dp[0][i];
		for(int j=1; j<m; j++){
			menor = min(menor, dp[j][i]);
		}
		dp2[i] = menor;
	}
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		int l,r;
		cin >> l >> r;
		if(dp2[r-1] <= l-1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
	
