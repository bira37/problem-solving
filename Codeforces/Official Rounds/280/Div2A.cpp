#include <bits/stdc++.h>

using namespace std;

int PA(int n){
	return (n*(n+1))/2;
}

int main(){
	int n;
	cin >> n;
	if(n == 1) cout << 1 << endl;
	else {
		int ans = 0;
		for(int i=1, k = 1; i<=1000; i++, k+=PA(i)){
			if(k <= n) ans = i;
		}
		cout << ans << endl;
	}
}