#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
 
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	int pair[n];
	int sum[n];
	for(int i=0; i<n; i++){
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr+3);
		v[i] = arr[0] + arr[1];
		pair[i] = v[i];
		sum[i] = arr[0] + arr[1] + arr[2];
	}
	sort(v.begin(), v.end());
	//for(int x : v) cout << x << " ";
	//cout << endl;
	for(int i=0; i<n; i++){
		int ans = upper_bound(v.begin(), v.end(), sum[i]-2) - v.begin();
		if(pair[i] <= sum[i]-2) ans--;
		cout << ans << " ";
	}
	cout << endl;
}
