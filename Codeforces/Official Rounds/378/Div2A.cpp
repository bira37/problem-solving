#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string x;
	cin >> x;
	int maximo = 0, last = 0, sum = 0;
	x = x + "A";
	for(int i=0; i<x.size(); i++){
		sum++;
		if(x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U' || x[i] == 'Y'){
			maximo = max(sum,maximo);
			sum = 0;
			last = i;
		}
	}
	cout << maximo << endl;
}
