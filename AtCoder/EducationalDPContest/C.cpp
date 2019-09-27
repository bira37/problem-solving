#include <bits/stdc++.h>
#define MAXN 100100
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define INF 1000000
using namespace std;

	int A[MAXN],B[MAXN],C[MAXN];
	int dp[MAXN][4];
int32_t main(){
	fastio;
	int n;
	cin>>n;
	memset(dp,-INF,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin>>A[i]>>B[i]>>C[i];
	}
	dp[0][1]=dp[0][2]=dp[0][3]=dp[0][0]=0;
	dp[1][1]=A[1];
	dp[1][2]=B[1];
	dp[1][3]=C[1];
	
	for(int i=2;i<=n;i++){
	dp[i][1]=max(dp[i-1][2],dp[i-1][3])+A[i];
	dp[i][2]=max(dp[i-1][3],dp[i-1][1])+B[i];
	dp[i][3]=max(dp[i-1][1],dp[i-1][2])+C[i];
	}	
	int res=max(dp[n][1],max(dp[n][2],dp[n][3]));
	cout<<res<<endl;
}
