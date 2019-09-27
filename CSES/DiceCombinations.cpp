#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 1001000
#define MAXL 30
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int dp[MAXN];
 
inline int mod(int a){
	int r = a%MOD;
	if(r<0)r+=MOD;
	return r;
}
 
int32_t main(){
	fastio;
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	
	for(int i=0;i<=n;i++){
		for(int j=1;j<=6;j++){
			if(i-j>=0)dp[i]=mod(dp[i]+dp[i-j]);
		}
	}
 
	cout<<dp[n]<<endl;
	
}