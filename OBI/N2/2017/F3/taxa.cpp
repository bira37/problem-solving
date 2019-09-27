#include <bits/stdc++.h>
#define MAXN 500
#define int long long
#define inf 10000000
#define double long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

	int A[MAXN];
	int soma[MAXN];
	int dp[MAXN][MAXN];
	
	int calcula(int ini,int fim){
		return soma[fim]-soma[ini-1];
	}
	
	int divide(int ini,int fim){
		if(dp[ini][fim]!=-1)return dp[ini][fim];
		if(ini==fim)return dp[ini][fim]=0;
		int best=inf;
		for(int k = ini;k<fim;k++){
			best = min(best,divide(ini,k)+divide(k+1,fim)+max(soma[k]-soma[ini-1],soma[fim]-soma[k]));
		}
		return dp[ini][fim]=best;
	}
		
	
int32_t main(){
	fastio;
	int n;
	double F;
	cin>>n>>F;
	soma[0]=0;
	for(int i=1;i<=n;i++){
	cin>>A[i];
	A[i+n]=A[i];
	}
	for(int i=1;i<=2*n;i++){
		soma[i]=soma[i-1]+A[i];
	}
	memset(dp,-1,sizeof(dp));
	int res=inf;
		for(int j=1;j<n;j++)
			for(int k=j;k<n;k++){
				int dentro=j-1;
				int fim = n + dentro;
				int imp = max(calcula(j,k),calcula(k+1,fim));
				int op = imp + divide(j,k)+divide(k+1,fim);
			//	cout<<j<<" "<<k<<" "<<imp<<" "<<op<<" "<<fim<<endl;
				res=min(op,res);
			}
	double R = (double)res*F;		
	cout<<setprecision(2)<<fixed;
	cout<<R<<endl;
	
}