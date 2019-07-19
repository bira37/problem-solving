#include <bits/stdc++.h>

#define ff first
#define ss second
#define LL_MAX (1e18)
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define IOS_SYNC ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>

using namespace std;

typedef long long ll;

////////////////////////CODE//////////////////////////////////////////////////////

ll dp[(int)1e4][(int)1e4/2];
pll v[(int)1e4];


int main(){

	IOS_SYNC(false);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i].ff >> v[i].ss;
	}
	
	//ll dp[n+1][n/2+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n/2; j++){
			dp[i][j] = LL_MAX;
		}
	}
	
	dp[1][1] = v[0].ss;
	for(int i=2; i<n; i++){
		for(int j=1; j<=n/2; j++){
			if(2*j < i) continue;
			dp[i][j] = min(dp[i-1][j-1] + v[i-1].ss, dp[i-1][j] + v[i-1].ff);
		}
	}
	cout << dp[n-1][n/2] + v[n-1].ff << endl;
}
