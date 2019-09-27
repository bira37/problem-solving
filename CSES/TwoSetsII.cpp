#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 250500
#define MAXL 30
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
int moeda[MAXN];
 
inline int mod(int a){
	int r = a%MOD;
	if(r<0)r+=MOD;
	return r;
}
 
 int exp(int x,int n,int m){
	 if(n==0)return 1;
	 if(n==1)return x;
	 int r = exp(x,n/2,m);
 	 r = mod(r*r);
 	  if(n%2==1)r=mod(r*x);
	return mod(r);	  	  
}
 
 int inv(int x){
	 return mod(exp(x,MOD-2,MOD));
 }
 
int32_t main(){
	fastio;
	int n;
	cin>>n;
	memset(moeda,0,sizeof(moeda));
	moeda[0]=1;
	int soma = n*(n+1);
	soma=soma/2;
	for(int j=1;j<=n;j++){
	for(int i=soma-j;i>=0;i--){
       if(moeda[i]!=-1)moeda[i+j]=mod(moeda[i+j]+moeda[i]);
	}
	}
	
	if(soma%2==1){
		cout<<0<<endl;
		return 0;
	}else{
		cout<<(moeda[soma/2]*inv(2))%MOD <<endl;
	}
	
	
}