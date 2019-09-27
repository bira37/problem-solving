#include <bits/stdc++.h>
#define int long long
#define MAXN 450
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

int A[MAXN];
int dp[MAXN][MAXN];

int solve(int i,int j){
		if(i==j)return 0;
		if(dp[i][j]!=-1)return dp[i][j];
		
		int res=1000000000;
		res*=MAXN;
		res*=MAXN;
	for(int k=i;k<j;k++){
		int atual = A[j]-A[i-1] + solve(i,k) + solve(k+1,j);
		res=min(res,atual);
	}
		
		return dp[i][j]=res;
		
}

int32_t main(){
	fastio;
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	A[0]=0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		A[i]+=A[i-1];
	}
	cout<<solve(1,n)<<endl;
}
