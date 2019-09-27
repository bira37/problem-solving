#include <bits/stdc++.h>
#define MAXN 100100
#define MAXH 21
#define inf 1000000000
using namespace std;
 
 int dp[MAXN][MAXH];
 int v[MAXN];
 int m[MAXN];
int main(){
	int n,L,H;
	cin>>n>>L>>H;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXH;j++){
		dp[i][j]=-inf;
		}
	}
	dp[0][0]=0;
	
	int best = -inf;
	if(m[1]==1){
		dp[1][0]=0;
		//dp[0][1] = v[0];
	}else{
		dp[1][0]=max(0,v[1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=H;j++){
			if(m[i]){
				if(j==0){
					dp[i][j]=0;
				}else{
					dp[i][j]=dp[i-1][j-1]+v[i];
				}
				
			}else{
				if(j==0){
					dp[i][j]=max(dp[i-1][j]+v[i],0);
				}else{
					dp[i][j]=dp[i-1][j]+v[i];
				}
			}
			if(j>=L && j<=H){
				best = max(best,dp[i][j]);
			}
		}
	}
	cout<<best<<endl;
}