#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define MAXN 10100
#define MAXD 110
#define INI 12332112
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int M = 1e9+7;

string s;
int d;
int n;
int dp[MAXN][MAXD][2];

inline int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}


int s2(int dig,int soma,int flag){
	if(dp[dig][soma][flag]!=-1)return dp[dig][soma][flag];
	if(dig==n){
		if(soma==0){
			return dp[dig][soma][flag]=1;
		}else return dp[dig][soma][flag]=0;
		
	}
	if(flag){
		int res=0;
		for(int i=0;i<10;i++){
			res=mod(res+s2(dig+1,mod(soma+i,d),1),M);
		}
		return dp[dig][soma][flag]=mod(res,M);
	}else{
		int res=0;
		for(int i=0;i<10;i++){
			if(s[dig]-'0'>i){
				res=mod(res+s2(dig+1,mod(soma+i,d),1),M);
			}else if(s[dig]-'0'==i){
				res=mod(res+s2(dig+1,mod(soma+i,d),0),M);
			}else break;
		}
		return dp[dig][soma][flag]=mod(res,M);
	}
	
}



int32_t main(){
	fastio;
	cin>>s;
	cin>>d;
	n = s.size();
	memset(dp,-1,sizeof(dp));

	int r2 =0;
	for(int i=0;i<10;i++){
		if(s[0]-'0'>i){
			r2=mod(r2+s2(1,mod(i,d),1),M);
		}else if(s[0]-'0'==i){
			r2=mod(r2+s2(1,mod(i,d),0),M);
		}
	}
	
	cout<<mod(r2-1,M)<<endl;
	
}
