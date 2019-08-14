#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	int x1,x2;
	char op;
	cin >> n >> x1 >> op >> x2;
	if(op == '+') x1+=x2;
	else x1*=x2;
	if(x1 <= n) cout << "OK" << endl;
	else cout << "OVERFLOW" << endl;
}

