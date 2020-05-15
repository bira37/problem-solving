#include <bits/stdc++.h>

using namespace std;

int dist(int a, int b) {
	return min(abs(a-b), 24-abs(a-b));
}

int main(){
	int n;
	cin >> n;
	
	int nums[n];
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums+n);
	
	int ans1 = 0;
	for(int i = 0; i < n; i += 2) {
		ans1 += dist(nums[i], nums[i+1]);
	}
	
	int ans2 = 0;
	for(int i = 1; i < n-1; i += 2) {
		ans2 += dist(nums[i], nums[i+1]);
	}
	ans2 += dist(nums[0], nums[n-1]);
	
	cout << min(ans1, ans2) << endl;
}
