#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, y;
	cin >> n >> y;
	int v[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	double res = -1;
	for(int i=0; i<n-1; i++){
		int l = i+2, r = n-1;
		int ans = -1;
		while(l <= r){
			int m = (l+r)>>1;
			if(v[m] - v[i] <= y){
				l = m+1;
				ans = m;
			}
			else r = m-1;
		}
		if(ans  == -1) continue;
		res = max(res, double(v[ans] - v[i+1])/double(v[ans] - v[i]));
	}
	if(res == -1) cout << "-1" << endl;
	else cout << setprecision(15) << res << endl;
}