#include <bits/stdc++.h>
#define MAXK 100100
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
int dp[2][MAXK];//minimo preco para fazer x com i caras
int H[MAXK],S[MAXK];
 
int32_t main(){
	fastio;
	for(int i=0;i<2;i++)
		for(int j=0;j<MAXK;j++){
			dp[i][j]=-10000000;
		}
	int n,x;
	cin>>n>>x;
	
	dp[0][0]=0;
	dp[1][0]=0;
	
	for(int i=0;i<n;i++){
		cin>>H[i];
	}
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	
	dp[0][H[0]]=S[0];
	
	for(int i=1;i<n;i++)
		for(int j=0;j<=x;j++){
			dp[i%2][j]=dp[(i-1)%2][j];
			if(j-H[i]<0)continue;
			dp[i%2][j]=max(dp[(i-1)%2][j],S[i]+dp[(i-1)%2][j-H[i]]);
		}
		
	int best=0;
	for(int i=0;i<=x;i++){
		best=max(best,dp[(n-1)%2][i]);
	}
	cout<<best<<endl;
		
}