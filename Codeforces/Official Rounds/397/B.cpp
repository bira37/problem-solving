#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string x;
	char last;
	cin >> x;
	if(x[0] == 'a') last = 'a';
	else{
		cout << "NO" << endl;
		return 0;
	}
	for(int i=1; i<x.size(); i++){
		if(last +2 > x[i]) last = max(x[i],last);
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
}
