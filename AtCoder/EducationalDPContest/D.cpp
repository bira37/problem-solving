#include <bits/stdc++.h>
#define MAXN 100100
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define INF 1000000
using namespace std;

int w[110],v[110];
int dp[MAXN][110];

int32_t main(){
	int n,W;
	cin>>n>>W;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=0;i<=n;i++)
	dp[0][i]=0;
	
	for(int p=0;p<=W;p++)dp[p][0]=0;

	for(int p=1;p<=W;p++){
		for(int i=1;i<=n;i++){
		dp[p][i]=dp[p][i-1];
		if(p-w[i]>=0){
			dp[p][i]=max(dp[p][i],dp[p-w[i]][i-1]+v[i]);
		}
		}
	}
	cout<<dp[W][n]<<endl;
}
