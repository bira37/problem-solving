#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9+7;
inline int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}
int H,W;
char G[1010][1010];
int dp[1010][1010];
int solve(int l,int c){
	if(dp[l][c]!=-1)return dp[l][c];
	if(G[l][c]=='#')return dp[l][c]=0;
	if(l==H && c==W)return 1;
	dp[l][c]=0;

	if(l+1<=H){
		dp[l][c]=mod(solve(l+1,c),M);
	}
	if(c+1<=W){
		dp[l][c]=mod(dp[l][c]+solve(l,c+1),M);
	}
	return dp[l][c];
}

int32_t main(){
	memset(dp,-1,sizeof(dp));
	cin>>H>>W;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			cin>>G[i][j];
		}
	}
	cout<<solve(1,1)<<endl;
}