#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, l;
	cin >> n >> l;
	int v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v,v+n);
	double ans = max(v[0], l - v[n-1]);
	for(int i=1; i<n; i++){
		ans = max(ans, (v[i] - v[i-1])/2.0);
	}
	cout << fixed << setprecision(9);
	cout << ans << endl;
}