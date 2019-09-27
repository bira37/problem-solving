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
	for(int i=0;i<MAXN;i++)dp[i]=0;
	
	dp[0]=1;
	vector<int> c(n);
	for(int i=0;i<n;i++)cin>>c[i];
	
			for(int i=0;i<n;i++){
		for(int j=0;j<=x;j++){
			  if(j-c[i]>=0)dp[j] = (dp[j] + dp[j-c[i]])%MOD;	
			
		}
			}
	cout<<dp[x]<<endl;
}