#include <bits/stdc++.h>
#define int long long
using namespace std;

string s[112345], sr[112345];
int c[112345];
int dp[112345][2];
int32_t main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> c[i];
	for(int i=0; i<n; i++){
		cin >> s[i];
		sr[i] = s[i];
		reverse(sr[i].begin(), sr[i].end());
	}
	
	for(int i=0; i<n; i++){
		dp[i][0] = dp[i][1] = (int)1e16;
	}
	
	dp[0][0] = 0;
	dp[0][1] = c[0];
	
	for(int i=0; i<n-1; i++){
		//for dp[i][0]
		if(dp[i][0] < (int)1e16){
			if(s[i+1] >= s[i]) dp[i+1][0] = min(dp[i+1][0], dp[i][0]);
			if(sr[i+1] >= s[i]) dp[i+1][1] = min(dp[i+1][1], dp[i][0] + c[i+1]);
		}
		if(dp[i][1] < (int)1e16){
			if(s[i+1] >= sr[i]) dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
			if(sr[i+1] >= sr[i]) dp[i+1][1] = min(dp[i+1][1], dp[i][1] + c[i+1]);
		}
	}
	
	int ans = min(dp[n-1][0], dp[n-1][1]);
	
	if(ans >= (int)1e16) cout << -1 << endl;
	else cout << ans << endl;
}
		
		
			
	