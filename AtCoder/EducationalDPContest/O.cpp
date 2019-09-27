#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
#define MAXN 21
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
int n;
int dp[1<<MAXN][MAXN];
int can[MAXN][MAXN];

int solve(int id,int bitmask){
	//	cout<<id<<" "<<bitmask<<endl;
		if(id==n)return 1;
		if(dp[bitmask][id]!=-1)return dp[bitmask][id];
		int res=0;
		for(int i=0;i<n;i++){
			if((bitmask&(1<<i))==0 && can[id][i]){
				res=mod(res+solve(id+1,bitmask|(1<<i)),M);
			}
			
		}   	
	return dp[bitmask][id]=mod(res,M);
}


int32_t main(){
	fastio;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>can[i][j];
	
	cout<<solve(0,0)<<endl;
}
