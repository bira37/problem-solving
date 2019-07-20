#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	
	x = min(x, 4*n);
	
	vector<int8_t> arr(n);
	
	
	int cur = 0;
	arr[0] = 1;
	for(int i = 1; i <= x; i++) {
	
		int mov = i%n;
		
		cur = (cur + mov)%n;
		
		arr[cur] = 1;
	}
	
	cout << accumulate(arr.begin(), arr.end(), 0) << endl;	
	
	
}
