#include <bits/stdc++.h>
 
using namespace std;
 
int lst[200001];
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
 
		for(int i = 0; i < 200001; i++) lst[i] = -1;
 
		int dp[n];
		dp[0] = 0;
		int c;
		scanf("%d", &c);
		lst[c] = 0; 
		for(int i = 1; i < n; i++) {
			scanf("%d", &c);
			dp[i] = dp[i-1];
			if(lst[c] != -1) dp[i] = min(dp[i], dp[lst[c]]);
			dp[i]++;
			lst[c] = i;
		}
 
		printf("%d\n", dp[n-1]);
	}
}
