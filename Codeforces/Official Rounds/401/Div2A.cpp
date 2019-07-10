#include <bits/stdc++.h>
 
using namespace std;
 
int calculate(int n, int k){
	int v[3];
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[k] = 1;
	for(int i=0; i<n; i++){
		if(i%2 ==  0) swap(v[0],v[1]);
		else swap(v[1],v[2]);
	}
	if(v[0] == 1) return 0;
	else if(v[1] == 1) return 1;
	else return 2;
}
 
int main() {
	int n, k;
	cin >> n >> k;
	n = n % 6;
	if(calculate(n,0) == k) cout << 0 << endl;
	else if(calculate(n,1) == k) cout << 1 << endl;
	else cout << 2 << endl;
 
}
