#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	int sum = 0;
	int ans = 0;
	for(int i=0; i<n; i++){
		if(v[i] >= sum){
			ans++;
			sum += v[i];
		}
	}
	cout << ans << endl;
} 
