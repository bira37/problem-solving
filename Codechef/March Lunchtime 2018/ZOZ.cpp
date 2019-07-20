#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int v[n];
		int sum = 0;
		for(int i=0; i<n; i++){
			cin >> v[i];
			sum += v[i];
		}
		int ans = 0;
		for(int i=0; i<n; i++){
			if(v[i] + k > sum - v[i]) ans++;
		}
		cout << ans << endl;
	}
}
