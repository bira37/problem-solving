#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, q;
		scanf("%d %d", &n, &q);
 
		char s[n];
		scanf("%s", s);
 
		int dp[n][26];
		for(int j = 0; j < 26; j++) {
			dp[0][j] = 0;
		}
		dp[0][s[0]-'a']++;
 
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 26; j++) {
				dp[i][j] = dp[i-1][j];
			}
			dp[i][s[i]-'a']++;
		}
 
		for(int i = 0; i < q; i++) {
			int l, r;
			char c;
			scanf("%d %d %c", &l, &r, &c);
			l--;
			r--;
			int ans = 0;
			if(l/n == r/n) {
				ans = dp[r%n][c-'a'];
				if(l%n) ans -= dp[(l%n)-1][c-'a'];
			} else {
				int inc = n-(l % n);
 
				ans += dp[n-1][c-'a'];
				if(n-1-inc >= 0) ans -= dp[n-1-inc][c-'a'];
 
				l += inc;
 
				int rang = r-l+1;
				ans += dp[n-1][c-'a'] * (rang/n);
 
				if(rang % n) ans += dp[(rang%n)-1][c-'a'];
			}
			printf("%d\n", ans);
		}
 
		
	}
}
