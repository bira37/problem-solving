#include <iostream>
using namespace std;

int abs(int x){
	if(x<0)return -x;
	return x;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int res=1;
	int ant = a[0];
	int atual=1;
	for(int i=1;i<n;i++){
		if(abs(a[i]-ant)<=1){
			atual++;
		}else{
			atual = 1;
		}
		res = max(res,atual);
		ant = a[i];
	}
	cout<<res<<endl;
}