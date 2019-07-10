#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	string x;
	int n;
	cin >> x;
	cin >> n;
 
	int zerocount = 0;
	
	for(int i=0; i< x.size(); i++){
		if(x[i] == '0') zerocount++;
	}
 
	if(n > zerocount){
		cout << x.size()-1 << endl;
		return 0;
	}
	
	int aux =0;
	int ans = 0;
	for(int i= x.size()-1; i>=1; i--){
		if(x[i] == '0') aux++;
		else ans++;
		if(aux == n) break;
	}
 
	cout << ans << endl;
}
