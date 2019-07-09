#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	unsigned long long n;
	cin >> n;
	unsigned long long a=1,b=1,sum = 0;
	unsigned long long res = 1;
	sum = a+b;
	while(sum < n){
		res++;
		a = b;
		b = sum;
		sum = a + b;
	}
	if(sum > n) res--;
	cout << res << endl;
}
