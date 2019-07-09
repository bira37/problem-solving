#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long a,b,c,n;
	cin >> n >> a >> b >> c;
	if(n % 4 == 0) cout << 0 << endl;
	else {
		n = 4 - (n%4);
 
		long long res;
 
		if(n==1) res = min(min(a, b+c), 3*c);
 
		else if(n == 2) {
 
			res = min(min(b, 2*a), 2*c);
 
		}
 
		else if(n == 3) {
			res = min(min(b + a, 3*a), c);
		}
 
		cout << res << endl;
	}
}
