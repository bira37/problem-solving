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
 
int32_t main(){
	fastio;
	int n,x;
	cin>>n>>x;
	for(int i=0;i<MAXN;i++)dp[i]=inf;
	
	dp[0]=0;
	
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		for(int j=0;j+m<=x;j++){
			if(dp[j]!=inf){
				dp[j+m] = min(dp[j+m],dp[j]+1);
			}
		}
	}
	if(dp[x]==inf)cout<<-1<<endl;
	else cout<<dp[x]<<endl;
	
}