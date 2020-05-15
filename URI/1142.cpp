#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int k = 1;
	for(int i=0; i<n; i++){
		cout << k << " " << k+1 << " " << k+2 << " PUM" << endl;
		k+=4;
	}
}
