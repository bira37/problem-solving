#include <bits/stdc++.h>
#define MAXN 70
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int D[MAXN];
int E[MAXN];
int main(){
	fastio;
	int n;
	cin>>n;
	int a;
	char pe;
	for(int i=0;i<=60;i++){
	D[i]=0;
	E[i]=0;	
	}
	
	for(int i=0;i<n;i++){
		cin>>a>>pe;
		if(pe=='E'){
			E[a]++;
		}else{
			D[a]++;
		}
	}
	int res=0;
	for(int i=30;i<=60;i++){
		int atual = min(E[i],D[i]);
		res+=atual;
	}
	cout<<res<<endl;
	
}