#include <bits/stdc++.h>
 
using namespace std;
 
bool prime(unsigned long long n){
	unsigned long long limit = sqrt(n);
	for(unsigned long long i=2; i<=limit; i++){
		if(n%i == 0) return false;
	}
	return true;
}
			
int main(){
	unsigned long long n;
	cin >> n;
	if(n==2) cout << 1 << endl;
	else if(n%2 == 0) cout << 2 << endl;
	else if(prime(n)) cout << 1 << endl;
	else if(prime(n-2)) cout << 2 << endl;
	else cout << 3 << endl;
}	
