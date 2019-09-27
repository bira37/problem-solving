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
	int n,x=0;
	cin>>n;
	for(int i=0;i<MAXN;i++)dp[i]=-1;
	
	dp[0]=1;
	vector<int> c(n);
	for(int i=0;i<n;i++){cin>>c[i];
	x+=c[i];}
	
      for(int i=0;i<n;i++){
		for(int j=x-c[i];j>=0;j--){
			  if(dp[j]!=-1)dp[j+c[i]]=1;	
		}
        }
        vector<int> res;
        for(int i=1;i<=x;i++){
			if(dp[i]!=-1)res.pb(i);
		}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}