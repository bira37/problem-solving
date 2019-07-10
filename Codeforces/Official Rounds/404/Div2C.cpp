#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long n,m;
	cin >> n >> m;
	if(m >= n){
		cout << n << endl;
		return 0;
	}
	
	else {
		long long ans = m+1;
		long long l = 0, r = 1e10;
		long long aux = 0;
		while(l < r){
			long long mid = (l+r)/2;
		
			if(mid*(mid+1)/2 + ans + mid >= n){
				r= mid;
			}
			else {
				l = mid +1;
			}
		}
 
		cout << ans + l << endl;
	}
}
