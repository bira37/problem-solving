#include <bits/stdc++.h>
using namespace std;


int grundy[1000100];
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(k);
	for(int i=0;i<k;i++)cin>>v[i];
	grundy[0]=0;
	for(int i=1;i<=n;i++){
		int flag = false;
		for(int j=0;j<k;j++){
			if(i-v[j]>=0){
				if(grundy[i-v[j]]==0){
					flag = true;
					break;
				}
			}
		}
		if(flag){
			grundy[i] = 1;
		}else grundy[i]=0;
	}
	string s="";
	for(int i=1;i<=n;i++){
		if(grundy[i]==0)s+='L';
		else s+='W';
	}   	
	cout<<s<<endl;
}