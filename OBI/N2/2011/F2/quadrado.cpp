#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	srand(time(0));
	int n,s;
	cin>>n>>s;
	int vall[n+1],valc[n+1];
    
	
	for(int i=1;i<=n;i++)vall[i] = i;
	


	for(int i=1;i<n;i++){
		valc[i] = (i-1)*n;
	}
	
	int x=0;
	for(int i=1;i<=n;i++){
		x+=vall[i];
	}
	for(int j=1;j<n;j++){
		x+=valc[j];
	}
	valc[n] = s-x;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<vall[i]+valc[j]<<" ";
		}
		cout<<endl;
	}
	
}