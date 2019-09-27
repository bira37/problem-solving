#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
using namespace std;
int n,k;

int res=0;
int v[50];
void solve(int id,int have,int par){
	if(id==k){
		int contri = n/have;
		if(par%2)contri = -contri;
		res+=contri;
		return ;
	}
	
	solve(id+1,have,par);
	if(have*v[id]<=n)solve(id+1,have*v[id],par+1);
	
}


int32_t main(){
	fastio;
	cin>>n>>k;  	
	for(int i=0;i<k;i++){
		cin>>v[i];
	}
	solve(0,1,0);
	cout<<res<<endl;
}