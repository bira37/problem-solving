#include <bits/stdc++.h>
 
using namespace std;
 
long long calculate(long long x){
	long long ans = 0;
	long long aux = x;
	for(long long i = 0; i<=18; i++){
		ans += aux%10;
		aux/=10;
	}
	return x-ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	long long n, s;
	cin >> n >> s;
	
	long long l = 0;
	long long r = n;
	
	long long ans = n+1;
	while(l <= r){
		long long m = (l+r)/2;
 
		if(calculate(m) >= s){
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}
	
	cout << n - ans +1 << endl;
}
