#include <bits/stdc++.h>
#define int long long
#define MAXN 5050
using namespace std;
 
int dp[MAXN][MAXN];
int A[MAXN];
 
 
int solve(int l,int r){
	if(r<l)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	int op1 = A[l]+min(solve(l+1,r-1),solve(l+2,r));
	int op2 = A[r]+min(solve(l+1,r-1),solve(l,r-2));
	return dp[l][r]=max(op1,op2);
}
 
int32_t main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)cin>>A[i];
	cout<<solve(0,n-1)<<endl;
}