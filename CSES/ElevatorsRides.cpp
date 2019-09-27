#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int inf = 1e10;

const int N = 21;
pii dp[(1<<N)];

int32_t main() {
	int n,k;
	cin>>n>>k;   	
	 vector<int> v(n);
	 int full=0;
	 for(int i=0;i<n;i++)full+=(1<<i);
	 
	 for(int i=0;i<n;i++)cin>>v[i];  	
	 
	 
		 for(int mask=0;mask<=full;mask++){
			 dp[mask]=pii(1000,2e9);
		 }
	 
	 
		 dp[0]=pii(0,0);
		 for(int mask=0;mask<=full;mask++){
			 for(int j=0;j<n;j++){
				 if(mask&(1LL<<j))continue;
				 if(dp[mask].ss+v[j]<=k){
					 if(dp[mask].ff<dp[mask|(1LL<<j)].ff || (dp[mask].ff==dp[mask|(1LL<<j)].ff && dp[mask].ss+v[j]<dp[mask|(1LL<<j)].ss)){
						 dp[mask|(1LL<<j)]=pii(dp[mask].ff,dp[mask].ss+v[j]);
					 }
				 }
			 	 else {
			 	 	if(dp[mask].ff+1<dp[mask|(1LL<<j)].ff || (dp[mask].ff==dp[mask|(1LL<<j)].ff && dp[mask].ss+v[j]<dp[mask|(1LL<<j)].ss)){
					  dp[mask|(1LL<<j)]=pii(dp[mask].ff+1,v[j]);
					  }
				  }
			 }
		 }
	 
	 
	 cout<<1+dp[full].first<<endl;

}