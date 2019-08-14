#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n,v;
	cin >> n >> v;
	int dp[n+1];
	for(int i = 0; i<=n; i++) dp[i] = -1;
	dp[0] = 0;
	for(int i=0; i<v; i++){
		int coin;
		cin >> coin;
		for(int k = n-coin; k>=0; k--){
			if(dp[k] != -1) dp[k+coin] = 0;
		}
	}
	
	if(dp[n] == 0) cout << "S" << endl;
	else cout << "N" << endl;
}
