#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9+7;
inline int mod(int a,int m){int r = a%m;if(r<0)r+=m;return r;}
int dp[10010];
int32_t main(){
	int n;
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=0;
		if(i>=1){
			dp[i]=mod(dp[i-1],M);
		}
		 if(i>=2){
			dp[i]=mod(dp[i]+4*dp[i-2],M);
		}
		if(i>=3){
			dp[i]=mod(dp[i]+2*dp[i-3],M);
		}
	}
	cout<<dp[n]<<endl;
}