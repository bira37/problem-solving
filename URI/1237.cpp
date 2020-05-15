#include <bits/stdc++.h>

using namespace std;

int main(){
	string x,y;
	while(getline(cin, x)){
		getline(cin, y);
		int dp[x.size()+1][y.size()+1];
		for(int i=0; i<= x.size(); i++) dp[i][0] = 0;
		for(int i=0; i<= y.size(); i++) dp[0][i] = 0;
		int ans = 0;
		for(int i=1, len1 = x.size(); i<=len1; i++){
			for(int j=1, len2 = y.size(); j<=len2; j++){
				if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = 0;
				ans = max(ans, dp[i][j]);
			}
		}
		/*for(int i=1, len1 = x.size(); i<=len1; i++){
			for(int j=1, len2 = y.size(); j<=len2; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << ans << endl;
	} 
	
}
		
