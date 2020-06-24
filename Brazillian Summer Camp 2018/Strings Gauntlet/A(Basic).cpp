#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int j = 0;
	for(int i = 0; i < n; i++) {
		int z;
		cin >> z;
		
		
		int zj = i+z-1;
		if(!z) zj++;
		int lz = min(z, 1+(j-i));
		
		//cout << zj << " " << lz << endl;
		for(; j <= zj; j++) {
			//cout << "-> " <<  lz << endl;
			cout << lz << " ";			
			lz++;
		}
	}
	cout << endl;
}
