#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i=1; i<n; i++){
		int x;
		cin >> x;
		a[i] = x;
	}
	int acc = 0;
	int ans = INT_MAX;
	for(int i=1; i<=k; i++) acc += a[i];
	ans = min(ans, acc);
	for(int i=k+1; i<n; i++){
		acc -= a[i-k];
		acc += a[i];
		ans = min(acc, ans);
	}
	cout << ans << endl;
	
} 