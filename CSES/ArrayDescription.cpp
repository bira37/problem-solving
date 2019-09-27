#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 100100
#define MAXM 110
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
 
int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}
 
int dp[MAXN][MAXM];// numero de modos de fazer at? i tendo usando j antes;
 
int32_t main(){
	fastio;
	int n,m;
	cin>>n>>m;
	vector<int> v(n+3);
	v[0]=-123;
	v[n+1]=-123;
	for(int i=1;i<=n;i++){
	 cin>>v[i];	
	}
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=m;i++)dp[0][i]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i]!=0){
				if(j==v[i]){
					
					if(i>1)dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1];
					else dp[i][j]=1;
					dp[i][j]=mod(dp[i][j],MOD);
				}else dp[i][j] =0;
			}else{
				if((v[i-1]==0 || abs(j-v[i-1])<=1 || i==1) && (v[i+1]==0 || abs(j-v[i+1])<=1 || i==n)){
				  dp[i][j]+=dp[i-1][j];
				  dp[i][j]+=dp[i-1][j-1];
				  dp[i][j]+=dp[i-1][j+1]; 
				  dp[i][j] = mod(dp[i][j],MOD);	
				}
				if(i==1){
					dp[i][j]=1;
				}
			}
		}
		
		
	}
	int res=0;
	for(int i=1;i<=m;i++){res+=dp[n][i];res=mod(res,MOD);}
	cout<<res<<endl;
	
}