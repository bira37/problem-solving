#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
	int n ;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i < n; i ++)  cin>>v[i];
	int x;
	int minmod = (int) 1e9 , vl = -1;
	cin>>x;
	for(int i = 0 ; i < n;  i++){
		if((x % v[i] )< minmod){
			minmod = x%v[i];
			vl = i;
		}
	}
	cout<<v[vl]<<endl;
}
