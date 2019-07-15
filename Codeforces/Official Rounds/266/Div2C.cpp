//Ubiratan Correia Barbosa Neto

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long v[n];
	long long pre[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
		if(i ==0) pre[i] = v[i];
		else pre[i] = pre[i-1] + v[i];
	}
	long long total = pre[n-1];
	if(total % 3){
		cout << 0 << endl;
		return 0;
	}
	
	long long ans = 0;
	long long sum = v[n-1];	
	long long dp[n];
	dp[n-1] = (sum == total/3 ? 1 : 0);
	for(int i = n-2; i>=0; i--){
		sum += v[i];
		dp[i] = dp[i+1] + (sum == total/3 ? 1 : 0);
	}
	
	for(int i=0; i<n-2; i++){
		if(pre[i] == total/3) ans += dp[i+2];
	}
	
	cout << ans << endl;
}