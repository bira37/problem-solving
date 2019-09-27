#include <bits/stdc++.h>
#define MAXN 100100
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define INF 1000000000
using namespace std;

int abs(int& a){
	if(a<0)a=-a;
	return a;
}

int32_t main(){
	fastio;
	int n,h[MAXN],k;
	cin>>n>>k;
	int custo[MAXN];
	for(int i=1;i<=n;i++){cin>>h[i];
	custo[i]=INF;
	}
	custo[1]=0;
	custo[0]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(i-j>=1)custo[i]=min(custo[i],custo[i-j]+abs(h[i-j]-h[i]));
			else break;
			
			
			cout<<custo[n]<<endl;
}
