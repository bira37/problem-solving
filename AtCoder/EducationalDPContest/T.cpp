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
#define MAXN 3100
using namespace std;
const int M = 1e9+7;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

int dp[MAXN][MAXN];
int soma[MAXN];
char sign[MAXN];

signed main(){
	int n;
	cin>>n;
	
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			dp[i][j]=0;
	dp[0][1]=1;
	//modo de fazer usando ate o sinal i e tendo usado por ultimo j;
	soma[0]=0;   	
	
	for(int i=1;i<n;i++)cin>>sign[i];
	 
	for(int i=1;i<n;i++){
		soma[0]=0;
		for(int k=1;k<=i+1;k++){
			//prefix sum na dp
			soma[k]=mod(soma[k-1]+dp[i-1][k],M);
		}
		
		for(int j=1;j<=i+1;j++){
			//dp[i][j] = sum{dp[i-1][k>=j]},se sign == >
			// se nao sum{dp[i-1][k<j],se s <};
			
			if(sign[i]=='<'){
				dp[i][j]=mod(soma[j-1],M);
			}else{
					dp[i][j]=mod(soma[i+1]-soma[j-1],M);
			}
		}
		
	}

	int res=0;
	for(int j=1;j<=n;j++){
		res=mod(dp[n-1][j]+res,M);
	}
	cout<<res<<endl;
	
}
