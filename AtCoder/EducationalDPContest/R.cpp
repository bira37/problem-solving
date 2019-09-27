#include <bits/stdc++.h>
#define int long long
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
#define MAXN 55
using namespace std;
typedef long long ll;

int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}

struct matrix{
	int m [MAXN][MAXN];	
};

matrix base,identidade;
ll n;

matrix mul(matrix a,matrix b){
	matrix aux;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			   	aux.m[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int A=0;A<n;A++)
				aux.m[i][j]=mod(aux.m[i][j]+a.m[i][A]*b.m[A][j],M);
	return aux;		
}

matrix exp(int k){
	if(k==0)return identidade;
	if(k==1)return base;
	if(k%2==1){
		matrix c = mul(base,exp(k-1));
		return c;
	}
	matrix c = exp(k/2);
	return mul(c,c);
}

int32_t main(){
	ll k;
	cin>>n>>k;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			cin>>base.m[i][j];
				  if(i==j)identidade.m[i][j]=1;
				  else identidade.m[i][j]=0;		
	}
	ll res=0;	
	matrix t = exp(k);		  	

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			res=mod(res+t.m[i][j],M);
		}
	}
	cout<<res<<endl;
}
