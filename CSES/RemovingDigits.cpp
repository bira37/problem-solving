#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 1000100
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int dp[MAXN];
int pot[10];
 
 
int solve(int x){
	if(dp[x]!=-1)return dp[x];
	if(x==0)return 0;
	int res=inf;
	vector<int> v;
	int X = x;
	while(X>0){
		int y = X%10;
		v.pb(y);
		X=X/10;
	}
	for(int i=0;i<(int)v.size();i++){
		int y = v[i];
		if(y==0)continue;
		res = min(res,1+solve(x-y));
	}
	return dp[x]=res;
}
 
int32_t main(){
	fastio;
	int a;
	cin>>a;
	memset(dp,-1,sizeof(dp));
	pot[0]=1;
	for(int i=1;i<10;i++)pot[i]=10*pot[i-1];
	
	cout<<solve(a)<<endl;
}