#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
 
		long long dp[n+1][31];
		int num;
		for(int i = 0; i < 31; i++) {
			dp[0][i] = 0;
		}
		for(int j = 1; j <= n; j++) {
			scanf("%d", &num);
			for(int i = 0; i < 31; i++) {
				if(num & (1 << i)) dp[j][i] = dp[j-1][i];
				else dp[j][i] = j;
			}
		}
 
		long long ans = 0;
 
		for(int r = 1; r <= n; r++) {
			for(int i = 0; i < 31; i++) {
				ans += (long long)(r-dp[r][i])*(long long)(1LL << i);
			}
		}
 
		printf("%I64d\n", ans);
	}
}
