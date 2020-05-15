#include <bits/stdc++.h>

using namespace std;

int main(){
	bool v1[5],v2[5],v3[5];
	for(int i=0; i<5; i++){
		cin >> v1[i];
	}
	for(int i=0; i<5; i++){
		cin >> v2[i];
	}
	for(int i=0; i<5; i++){
		v3[i] = v1[i]^v2[i];
	}
	int ans = 1;
	for(int i=0; i<5; i++){
		ans = ans & v3[i];
	}
	if(ans) cout << "Y" << endl;
	else cout << "N" << endl;
}
