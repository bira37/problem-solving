#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
 
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
 
	int nums[n];
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
 
	sort(nums, nums+n);
 
	long long ans = 0;
 
	for(int i = 0; i <= n; i++) {
		ans += max(0LL, min(n, nums[i]) - (i+1));
	}
 
	cout << ans*2LL << endl;
}
