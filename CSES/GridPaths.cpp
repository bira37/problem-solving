#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 1010
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
 
int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}
 
int dp[MAXN][MAXN];// numero de modos de fazer at? i tendo usando j antes;
string s[MAXN];
int32_t main(){
	fastio;
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(s[0][0]=='*'){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0)continue;
			if(s[i][j]=='*')dp[i][j]=-inf;
			else{
				
				dp[i][j]=0;
				if(i-1>=0)dp[i][j]=mod(max(dp[i-1][j],0LL),MOD);
				if(j-1>=0)dp[i][j]=mod(dp[i][j]+max(dp[i][j-1],0LL),MOD);
			}
		}
	}
	if(s[n-1][n-1]=='*')cout<<0<<endl;
	else cout<<dp[n-1][n-1]<<endl;	
	
	
}