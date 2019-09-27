#include <bits/stdc++.h>
#define double long double
#define MAXN 305
using namespace std;

double dp[MAXN][MAXN][MAXN];

double n;

double solve(int i,int j,int k){
	if(dp[i][j][k]!=-1){
	return dp[i][j][k];
	}
	double num = (i+j+k);
	double exp = (double)n/(i+j+k);
	double op1=0,op2=0,op3=0;
	if(i>=1)op1=(i/num)*(solve(i-1,j,k));
	if(j>=1)op2=(j/num)*solve(i+1,j-1,k);
	if(k>=1)op3=(k/num)*solve(i,j+1,k-1);
//	cout<<i<<" "<<j<<" "<<k<<" "<<exp<<" "<<op1<<" "<<op2<<" "<<op3<<" "<<endl;
	return dp[i][j][k]=(op1+op2+op3+exp);
}

int main(){
	cin>>n;
	
	int x,a1=0,a2=0,a3=0;
	for(int i=0;i<(int)n;i++){
		cin>>x;
		if(x==1)a1++;
		if(x==2)a2++;
		if(x==3)a3++;
	}

	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			for(int k=0;k<MAXN;k++)
				dp[i][j][k]=-1;
			
		dp[0][0][0]=0;
	//	cout<<a1<<" "<<a2<<" "<<a3<<endl;
		cout<<setprecision(14)<<fixed;		
	   cout<<solve(a1,a2,a3)<<endl;	
}
