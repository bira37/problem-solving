#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int32_t main(){
	int a,b;
	cin >> a >> b;
	int res = 0;
	while(true){
		if(b == 0) break;
		if(a < b) swap(a,b);
		if(a > b){
			
			int l = 1, r = 1123456789999;
			int ans = -1;
			while(l <= r){
				int m = (l+r)/2;
				if(a > m*b){
					ans = m;
					l = m+1;
				}
				else r = m-1;
			}
			res += ans;
			a -= ans*b;
		}
		else break;
	}
	cout << res+1 << endl;
}