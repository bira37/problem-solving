#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define MAXN 20
#define inf 1000000007
#define INI 12332112
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

int pre[(1<<16)+10];
int a[MAXN][MAXN];
int dp[(1<<16)+10];
int full=0;


int32_t main(){
	fastio;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		full+=(1<<i);
	}
	for(int x=1;x<=full;x++){
		int atual=0;
		for(int b1=0;b1<n;b1++){
			for(int b2=b1+1;b2<n;b2++){
				if(((x&(1<<b1))!=0) && ((x&(1<<b2))!=0)){
					atual+=a[b1][b2];
				}
			}
		}
		pre[x]=atual;
	}
	for(int i=1;i<=full;i++){
		dp[i]=pre[i];
	}
		
	for(int x=1;x<=full;x++){
		for(int g1=x;g1>0;g1=(g1-1)&x){
			int g2=x^g1;
			dp[x] = max(dp[x],dp[g1]+dp[g2]);
		}
	}
	
	cout<<dp[full]<<endl;
		
}
