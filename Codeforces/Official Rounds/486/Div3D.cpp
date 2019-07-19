#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main(){
	int n;
	cin >> n;
	set<int> num;
	int maxi;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.insert(a);
		if(i == 0) maxi = a;
		maxi = max(a, maxi);
	}
	
	
	int ans = 0;
	int a1,a2,a3;
	
	for(int a : num) {
		for(int i = 0; (1LL<<i) <= 3LL*1000000000LL; i++) {
			int xns = 1;
			int x1 = a, x2 = a+(1LL<<i), x3 = a+((1LL<<i)*2LL);
			//cout << x1 << " " << x2 << " " << x3 << endl;
			if(num.find(x2) != num.end()) {
				xns = 2;
				//cout << 2 << endl;
				if(num.find(x3) != num.end()) {
					//cout << 3 << endl;
					xns = 3;
				}
			} else {
				if(num.find(x3) != num.end()) {
					//cout << 3 << endl;
					xns = 2;
					swap(x2,x3);
				}
			}
			//cout <<"x " <<  xns << endl;
			if(xns > ans) {
				ans = xns;
				a1 = x1;
				a2 = x2;
				a3 = x3;						
			}
		}
		
	}
	cout << ans << endl;
	if(ans >= 1) cout << a1 << " ";
	if(ans >= 2) cout << a2 << " ";
	if(ans >= 3) cout << a3 << " ";
	cout << endl;
}
