#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	string x;
	cin >> x;
 
	if(n == 12){
		if(x[0] == '1' && x[1] >= '3' || ( x[0] >= '2')){
			x[0] = '0';
		}
		if(x[3] >= '6') x[3] = '0';
		if(x[0] == '0' && x[1] == '0') x[0] = '1';
	}
 
	else if(n == 24){
		if(x[0] == '2' && x[1] >= '4' || (x[0] >= '3')) x[0] = '0';
		if(x[3] >= '6') x[3] = '0';
	}
	cout << x << endl;
}
