#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long n,k;
	cin >> n >> k;
	vector<long long> v;
	for(int i=0; i<n; i++){
		long long x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i=0; i<v.size(); i++){
		while(2*k < v[i]){
			k = k << 1;
			ans++;
		}
		k = max(k,v[i]);
	}
	
	cout << ans << endl;
}
