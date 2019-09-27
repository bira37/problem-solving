#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
using namespace std;

int sum[10];

int32_t main(){
	fastio;
	int n;
	cin>>n;
	int fat=1;
	for(int i=1;i<=n;i++){
		fat*=i;
	}
	memset(sum,0,sizeof(sum));
	
	int deveria=0;
	for(int i=1;i<=n;i++){
		deveria+=(i*(fat/n));
	}
	for(int i=1;i<fat;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			sum[j]+=x;
		}
	}
	for(int j=0;j<n;j++){
		cout<<deveria-sum[j]<<" ";
	}
	cout<<endl;
}