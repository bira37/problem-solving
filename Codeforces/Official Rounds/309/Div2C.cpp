#include <bits/stdc++.h>
 
using namespace std;
 
#define M 1000000007
 
int main(){
	long long n;
	cin >> n;
	long long v[n];
	long long dp[1001][1001];
	dp[0][0] = 1;
	for(int i=0; i<1001; i++){
		dp[i][0] = 1;
		for(int j=1; j<=i; j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%M;
		}
	}
	for(int i=0; i<n; i++) cin >> v[i];
	int acc = v[0];
	int res = 1;
	for(int i=1; i<n; i++){
		acc += v[i];
		res = (res*dp[acc-1][v[i]-1])%M;
	}
	cout << res << endl;
}
