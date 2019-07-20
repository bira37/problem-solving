#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main(){
	int r,d;
	
	cin >> r >> d;
 
	
	int ans = 0;
	
	int c = 0;
	
	for(int i = 1; i<= r+d; i++){
		c += floor(sqrt((r+d)*(r+d) - i*i)) + 1;
	}
	
	ans += 4*c + 1;
	
	c = 0;
	
	for(int i = 1; i<= r-d; i++){
		c += ceil(sqrt((r-d)*(r-d) - i*i));
	}
	
	ans -= 4*c;
	
	if(r-d > 0) ans--;
	
	cout << ans << endl;
	
}
