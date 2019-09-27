#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 550
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int dp[MAXN][MAXN];
 
int solve(int a,int b){
	if(a>b)swap(a,b);
	if(dp[a][b]!=-1)return dp[a][b];
	if(a==0)return dp[a][b] = 0;
	if(a==1)return dp[a][b] = b-1;
	if(a<0)return dp[a][b] = inf;
	if(a==b)return dp[a][b] = 0;
	int res=inf;
	for(int i=1;i<a;i++){
		res = min(res,1+solve(a-i,b)+solve(i,b));
	}
	for(int i=1;i<b;i++){
		res=min(res,1+solve(a,b-i)+solve(i,a));
	}
	return dp[a][b]=res;
}
 
int32_t main(){
	fastio;
	int a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	cout<<solve(a,b)<<endl;
}