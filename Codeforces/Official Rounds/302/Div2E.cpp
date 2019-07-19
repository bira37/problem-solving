#include <bits/stdc++.h>
using namespace std;
 
char s[21][21] = {0};
int c2[21][21] = {0};
int c1[21][21] = {0};
int lul[21][21] = {0};
int dp[(1<<20)] = {0};
			
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<(1<<n); i++){
		dp[i] = INT_MAX;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> s[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> c1[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int mxcur = 0;
			c2[i][j] = 0;
			for(int k=0; k<n; k++){
				if(s[i][j] != s[k][j]) continue;
				lul[i][j] |= (1<<k);
				mxcur = max(mxcur, c1[k][j]);
				c2[i][j] += c1[k][j];
			}
			c2[i][j] -= mxcur;
		}
	}
	
	dp[0] = 0;
	
	for(int msk = 1; msk < (1<<n); msk++){
		int cand;
		for(int i=0; i<n; i++) if(msk & (1<<i)) { cand = i; break; }
		for(int j = 0; j<m; j++){
			dp[msk] = min(dp[msk], dp[msk & (msk ^ lul[cand][j])] + c2[cand][j]);
			dp[msk] = min(dp[msk], dp[msk & (msk ^ (1<<cand))] + c1[cand][j]);
		}
	}
	cout << dp[(1<<n)-1] << endl; 
}
