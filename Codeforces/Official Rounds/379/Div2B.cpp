#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int k2,k3,k5,k6;
	cin >> k2 >> k3 >> k5 >> k6;
	int num256 = min(min(k2,k5),k6);
	k2 = max(0, k2-num256);
	int num32 = min(k2,k3);
	cout << 256*num256 + 32*num32 << endl;
}
