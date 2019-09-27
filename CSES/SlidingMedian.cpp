#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 200100
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
int n,k;
pii bit[MAXN];
void att(int x,int val){
	while(x<MAXN){
		bit[x].ff+=val;
		x+=(x&-x);
	}
}
void att2(int x,int val){
	while(x<MAXN){
		bit[x].ss+=val;
		x+=(x&-x);
	}
}
int sum2(int x){
	int r = 0;
	while(x>0){
		r+=bit[x].ss;
		x-=(x&-x);
	}
	return r;
}
int sum(int x){
	int r =0;
	while(x>0){
		r+=bit[x].ff;
		x-=(x&-x);
	}
	return r;
}

int need;
int check(int x){
	return sum2(x)<need;
}
int32_t main(){
	fastio;
	cin>>n>>k;
	vector<int> v(n);
	map<int,int> m1;
	map<int,int> m2;
	int sz = 1;
	for(int i=0;i<n;i++){
		cin>>v[i];
		m1[v[i]];
	}
	for(map<int,int>::iterator it = m1.begin();it!=m1.end();it++){
		m1[it->first] = sz++;
		m2[sz-1] = it->first;
	}
	sz--;
	need = k/2 + (k&1);
	if(k==1){
		for(int i=0;i<n;i++)cout<<v[i]<<" ";
		cout<<endl;
		return 0;
	}
	if(k==2){
		for(int i=1;i<n;i++)cout<<min(v[i],v[i-1])<<" ";
		cout<<endl;
		return 0;
	}
	
	for(int i=0;i<MAXN;i++)bit[i].ss=0;
	for(int i=0;i<n;i++){
		if(i==0){
			for(;i<k;i++){
				att2(m1[v[i]],1);
			}
			i--;
		}else{
			att2(m1[v[i]],1);
			att2(m1[v[i-k]],-1);
		}
		int l = 1,r = sz;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(mid)){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		cout<<m2[l]<<" ";
	}
	cout<<endl;
	
}