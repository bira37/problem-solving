#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main(){
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i=0; i<n; i++) cin >> x[i] >> y[i];
	int ans = LLONG_MAX;
	for(int i=0; i<n; i++){
		int xb,yb,xc,yc;
		xb = x[(i+1)%n] - x[i];
		yb = y[(i+1)%n] - y[i];
		xc = x[(i+2)%n] - x[i];
		yc = y[(i+2)%n] - y[i];
		
		if(xb*yc - yb*xc > 0) ans = min(ans, xb*yc - yb*xc);
	}
	cout << ans << endl;
}
