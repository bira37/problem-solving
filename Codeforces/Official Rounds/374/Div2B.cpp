#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k;
	int best = 0;
	int worst = 0;
	
	cin >> n >> k;
	
	int cont[101]= {};
	
	for(int i=0; i<n; i++){
		string x;
		cin >> x;
		cont[x.size()]++;
	}
	
	string y;
	cin >> y;
	int len = y.size();
 
	int ans = 0;	
	for(int i=1; i<len; i++){
		ans+=cont[i];
	}
	
	best = ans+(ans/k)*5 + 1;
	int flag = ans%2;
	worst = ans+cont[len] + ((ans+cont[len]-1)/k)*5;
 
	cout << best << " " << worst << endl;
	 
}
