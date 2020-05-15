#include <bits/stdc++.h>

using namespace std;

int main(){
	int q,d,p;
	while(cin >> q, q){
		cin>> d >> p;
		int res = abs(d*p*q/(q-p));
		cout << res;
		if(res > 1) cout << " paginas" << endl;
		else cout << " pagina" << endl;
	}
}
