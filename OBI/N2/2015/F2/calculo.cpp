#include <bits/stdc++.h>
using namespace std;
int a[1010],b[1010],c[1010];

int main(){
	int n,m;
	cin>>n>>m;

	int carry=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=max(n,m) - 1;i>=0;i--){
		int soma = carry + a[i] + b[i];
		c[i] = soma%2;
		if(soma>=2)carry=1;
		else carry=0;
	}
	int r = 0;
	for(int i=0;i<max(n,m);i++){
		if(c[i]>0)r=i;
	}
	for(int i=0;i<=r;i++){
		cout<<c[i]<<" ";
	}    	
	cout<<endl;
}