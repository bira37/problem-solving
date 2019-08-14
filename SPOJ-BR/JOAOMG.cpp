#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
whi:	while(cin >> n, n){
		long long aux = n*n;
		for(int i=1;i <= aux; i*=10){
			int p1 = aux/i;
			int p2 = aux%i;
			if(p1 + p2 == n && p1 > 0 && p2 > 0){
				cout << n << ": S" << endl;
				goto whi;
			}
		}
		if(n==1) cout << n << ": S" << endl;
		else cout << n << ": N" << endl;
	}
}

