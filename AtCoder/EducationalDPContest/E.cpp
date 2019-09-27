#include <bits/stdc++.h>
#define MAXN 110
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define INF 1000000007
#define MAXV 100100
using namespace std;

	int w[MAXN];
	int v[MAXN];
	int dp[MAXN][MAXV]; 
	  	
int32_t main(){
int n,W;
cin>>n>>W;
int sum=0;
for(int i=1;i<=n;i++){
	cin>>w[i]>>v[i];
	sum+=v[i];
}

	for(int i=0;i<=n;i++)
		for(int j=0;j<=MAXV;j++)
			dp[i][j]=INF;
		
		dp[0][0]=0;
		dp[1][0]=0;
	for(int i=1;i<=n;i++)
	dp[i][v[i]]=w[i];
	
	 	
	for(int i=2;i<=n;i++)
		for(int j=0;j<=sum;j++){//mudar limites
			dp[i][j]=dp[i-1][j];
			if(j-v[i]>=0)dp[i][j]=min(dp[i][j],w[i]+dp[i-1][j-v[i]]);
		}
	
	int maxi=0;
	for(int j=MAXV;j>=0;j--){
	//	cout<<dp[n][j]<<endl;
		if(dp[n][j]<=W){
			maxi=j;
			break;
		}
	}
	cout<<maxi<<endl;   	
}
