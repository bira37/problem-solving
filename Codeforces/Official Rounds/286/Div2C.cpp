#include <bits/stdc++.h>
 
using namespace std;
 
int dp[30002][1200];
int v[30002];
 
int main(){
	int n,d;
	cin >> n >> d;
	for(int i=0; i<=30001; i++) v[i] = 0;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v[x]++;
	}
	for(int i=0; i<=30001; i++){
		for(int j=0; j<=1199; j++){
			dp[i][j] = INT_MIN;
		}
	}
	dp[d][0] = v[d];
	int ans = 0;
	for(int i=d; i<=30000; i++){
		for(int j=0; j<=1199; j++){
			ans = max(ans, dp[i][j]);
			int delta = 0;
			if(j%2 == 0) delta = -j/2;
			else delta = (j+1)/2;
			int aux = i+(d+delta);
			int aux2;
			if(delta > 0) aux2 = 2*(delta)-1;
			else aux2 = abs(2*delta);
			if(aux > i && aux <= 30000) dp[aux][aux2] = max(dp[aux][aux2], dp[i][j] + v[aux]);
			aux = i+d+(delta-1);
			if(delta-1 > 0) aux2 = 2*(delta-1)-1;
			else aux2 = abs(2*(delta-1));
			if(aux > i && aux <= 30000) dp[aux][aux2] = max(dp[aux][aux2], dp[i][j] + v[aux]);
			aux = i+d+(delta+1);
			if(delta+1 > 0) aux2 = 2*(delta+1)-1;
			else aux2 = abs(2*(delta+1));
			if(aux > i && aux <= 30000) dp[aux][aux2] = max(dp[aux][aux2], dp[i][j] + v[aux]);
		}
	}
	cout << ans << endl;
}
