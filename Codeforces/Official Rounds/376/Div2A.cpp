#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string x;
	cin >> x;
	char ini = 'a';
	int k = 0;
	for(int i=0; i<x.size(); i++){
		k+= min(abs(x[i] - ini), 26 - abs(x[i] - ini));
		ini = x[i];
	}
	cout << k << endl;
}
