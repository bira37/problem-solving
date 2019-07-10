#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v, v+n);
	long long ans = 0;
	long long power2[n+1];
	power2[0] = 1;
	for(int i=1; i<=n; i++) power2[i] = (power2[i-1]*2)%MOD;
	for(int i=1; i<=n; i++){
		ans = (ans + (v[i-1]*(power2[i-1] - power2[n-i]))%MOD)%MOD;
	} 
	cout << ans << endl;
}
