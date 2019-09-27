#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int check(){
	for(int i=0;i<(int)v.size()-1;i++){
		if(v[i+1]-v[i] >8)return false;
	}
return true;
}

int main(){
	 int n;
	 cin>>n;
	 v.push_back(0);
	 for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
	 sort(v.begin(),v.end());  	
	if(check()){
		cout<<"S"<<endl;
	}else cout<<"N"<<endl;
	
}