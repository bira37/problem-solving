#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, s;
	cin >> n >> s;
	int d[n];
	int max_sum = 0;
	int lb[n];
	for(int i=0; i<n; i++){
		cin >> d[i];
		max_sum += d[i];
	}
	for(int i=0; i<n; i++){
		max_sum -= d[i];
		if(max_sum < s){
			int val = s - max_sum;
			lb[i] = val;
		}
		else lb[i] = 1;
		max_sum += d[i];
	}
	max_sum = 0;
	int rb[n];
	for(int i=0; i<n; i++) max_sum += lb[i];
	for(int i=0; i<n; i++){
		max_sum -= lb[i];
		int range = s - max_sum;
		rb[i] = min(d[i], range);
		max_sum += lb[i];
	}
	for(int i=0; i < n; i++){
		//cout << lb[i] << " " << rb[i] << endl;
	}
	for(int i=0; i<n; i++){
		if(i) cout << " ";
		cout << max(0LL, d[i] - (rb[i] - lb[i]+1));
	}
	cout << endl;
}