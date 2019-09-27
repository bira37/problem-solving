#include <bits/stdc++.h>
#define MAXN 100100
#define int long long
using namespace std;

int abs(int& a){
	if(a<0)a*=-1;
	return a;
}

int32_t main(){
	int n,h[MAXN];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	int custo[MAXN];
	custo[0]=0;
	custo[1]=0;
	for(int i=2;i<=n;i++){
		custo[i]=custo[i-1]+abs(h[i]-h[i-1]);
		if(i>=3)custo[i]=min(custo[i],custo[i-2]+abs(h[i]-h[i-2]));
	}
	cout<<custo[n]<<endl;
}
