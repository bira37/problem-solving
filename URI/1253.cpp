#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	string x;
	cin >> n;
	while(n--){
		cin >> x;
		cin >> k;
		for(int i=0; i<x.size(); i++){
			x[i] = x[i]-k;
			if(x[i] < 65) x[i] = 91 - (65-x[i]);
		}
		cout << x << endl;
	} 
	
}
		
