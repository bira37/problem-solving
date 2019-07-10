#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	long long n,k;
	cin >> n >> k;
	long long v[n];
	long long menor = INT_MAX;
	for(int i=0; i<n; i++){
		cin >> v[i];
		menor = min(menor, v[i]);
	}
 
	long long modulo = 0;
	modulo = v[0]%k;
	for(int i=1; i<n; i++){
		if(v[i]%k != modulo){
			cout << -1 << endl;
			return 0;
		}
	}
	
	long long ans = 0;
	for(int i=0; i<n; i++){
		ans += (v[i] - menor)/k;
	}
 
	cout << ans << endl;
	
}
