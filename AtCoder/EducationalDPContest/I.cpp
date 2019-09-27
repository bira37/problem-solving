#include <bits/stdc++.h>
#define double long double
#define int long long
#define MAXN 3010
using namespace std;
	int n;
	double P[MAXN];
	double dp[MAXN][MAXN];
double solve(int id,int heads){
	if(dp[id][heads]!=-1)return dp[id][heads];
	if(id==n+1){
		if(heads>n-heads)return dp[id][heads]=(double)1;
		else return dp[id][heads]=(double)0;
	}
	double op1 = solve(id+1,heads+1);
	double op2 = solve(id+1,heads);
	return dp[id][heads]=P[id]*op1+(1-P[id])*op2;
}


int32_t main(){
	for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)dp[i][j]=-1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>P[i];
	cout<<setprecision(10)<<fixed;
	cout<<solve(1,0)<<endl;
}
