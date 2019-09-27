#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;

int BIT[MAXN];
int andar[MAXN];

void att(int x,int val){
	int ant = andar[x];
	andar[x] = val;
	while(x<MAXN){
		BIT[x]-=ant;
		BIT[x]+=val;
		x+=(x&-x);
	}
	
}
int sum(int x){
	int r =0;
	while(x>0){
		r+=BIT[x];
		x-=(x&-x);
	}
	return r;
}

int main(){
	int n,q;
	cin>>n>>q;
	memset(BIT,0,sizeof(BIT));
	for(int i=1;i<=n;i++){
		int x;
		andar[i]=0;
		cin>>x;
		att(i,x);
		andar[i]=x;
	}
	
	while(q--){
		int op;
		cin>>op;
		if(op==0){
			int  k, p;
			cin>>k>>p;
			att(k,p);
		}else{
			int k;
			cin>>k;
			cout<<sum(k)<<endl;
		}
	}
}