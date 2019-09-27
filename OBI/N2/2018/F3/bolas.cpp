#include <bits/stdc++.h>
using namespace std;
int check(vector<int> v){
	int ant = -1;
	for(int i=0;i<8;i++){
		if(v[i]==ant)return false;
		ant = v[i];
	}
	return true;
}
int main(){
	vector<int> v(8);
	for(int i=0;i<8;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	do{
		 if(check(v)){
			 cout<<"S"<<endl;
			 return 0;
		 }  	
	}while(next_permutation(v.begin(),v.end()));
	cout<<"N"<<endl;
	return 0;
}