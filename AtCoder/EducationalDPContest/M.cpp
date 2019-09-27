#include <bits/stdc++.h>
#define MAXN 110
#define MAXK 100100
#define M 1000000007
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n,K;
int A[MAXN];
int dp[MAXN][MAXK];

inline int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}



int32_t main(){
	fastio;
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>A[i];
	
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)dp[i][0]=1;
	int soma=0;
	 
	for(int i=1;i<=n;i++){
			soma=dp[i-1][0];
		for(int j=1;j<=K;j++){
			
			soma=mod(soma+dp[i-1][j],M);
			
			if(j>A[i]){
			soma=mod(soma-dp[i-1][j-A[i]-1],M);
			
			//	cout<<j<<" "<<A[i]<<" "<<j-A[i]<<endl;
			}
			
			dp[i][j]=mod(soma,M);
		//	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}	   	 	
	
		
	
	   	cout<<dp[n][K]<<endl; 		
	   	 		
}
