#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 100100
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
 
int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}
 
int exp(int a,int n,int m){
	if(n==0)return 1;
	if(n==1)return a;
	int r = exp(a,n/2,m);
	r = mod(r*r,m);
	if(n&1)r=mod(r*a,m);
	return r;
}
 
int total=0;
int v[20];
int n;
int32_t main(){
	fastio;
   	cin>>n;
   	int full=0;
   	for(int i=0;i<n;i++){
		   cin>>v[i];
		   total+=v[i];
    full+=(1<<i);
   }
   	
	     	
   	int best=inf;
   	for(int i=0;i<=full;i++){
	    int atual=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j))atual+=v[j];
		}
		best=min(best,abs((total-atual)-atual));   	   
    }
    cout<<best<<endl;
   	
}