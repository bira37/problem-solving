#include <bits/stdc++.h>
#define MAXN 3010
#define int long long
#define INF 123456789
using namespace std;

int dp[MAXN][MAXN];
int V[MAXN];

int solve(int i,int j){
	if(i>j)return 0;
	if(dp[i][j]!=-INF)return dp[i][j];
	
	int op1 = V[i]+min(solve(i+1,j-1),solve(i+2,j));
	int op2 = V[j]+min(solve(i+1,j-1),solve(i,j-2));
	return dp[i][j]=max(op1,op2);
}

int32_t main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=-INF;
	int soma=0;
	for(int i=0;i<n;i++){
		cin>>V[i];
		soma+=V[i];
	}
	int X = solve(0,n-1);
	int Y = soma - X;
	
	cout<<X-Y<<endl;	
		
}
