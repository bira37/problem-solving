#include <bits/stdc++.h>
#define int long long
#define LIM (long long)1e18
using namespace std;
int dp[201][201][201][3];
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	int b,r,s,k;
	cin >> b >> r >> s >> k;
	for(int i=0; i<=b; i++){
		for(int j = 0; j<=r; j++){
			for(int k = 0; k <= s; k++){
				for(int w = 0; w<3; w++){
					dp[i][j][k][w] = 0;
				}
			}
		}
	}
	dp[1][0][0][0] = dp[0][1][0][1] = dp[0][0][1][2] = 1;
	for(int i=0; i<=b; i++){
		for(int j = 0; j<=r; j++){
			for(int k = 0; k <= s; k++){
				if(i == 0 && j == 0 && k == 0) continue;
				if(i+1 <= b){
					dp[i+1][j][k][0] += dp[i][j][k][1] + dp[i][j][k][2];
					dp[i+1][j][k][0] = min(dp[i+1][j][k][0], LIM);
				}
				if(j+1 <= r){
					dp[i][j+1][k][1] += dp[i][j][k][0] + dp[i][j][k][2];
					dp[i][j+1][k][1] = min(dp[i][j+1][k][1], LIM);
				}
				if(k+1 <= s){
					dp[i][j][k+1][2] += dp[i][j][k][0] + dp[i][j][k][1];
					dp[i][j][k+1][2] = min(dp[i][j][k+1][2], LIM);
				}
			}
		}
	}
	if(dp[b][r][s][0] + dp[b][r][s][1] + dp[b][r][s][2] < k){
		cout << "None" << endl; //se n tiver k strings, xablau
		return 0;
	}
	string ans;
	int nb = 0, nr = 0, ns = 0, last = -1;
	for(int i=0; i<b+r+s; i++){
		//cout << endl;
		//cout << "k = " << k << endl;
		//cout << "for b = " << dp[b - nb][r - nr][s - ns][0] << endl;
		//cout << "for r = " << dp[b - nb][r - nr][s - ns][1] << endl;
		//cout << "for s = " << dp[b - nb][r - nr][s - ns][2] << endl;
		//cout << "try to append B" << endl;
		if(nb < b && last != 0){
			if(dp[b - nb][r - nr][s - ns][0] >= k){
				//cout << "append B" << endl;
				ans += 'B';
				last = 0;
				nb++;
				continue;
			}
			else k -= dp[b - nb][r - nr][s - ns][0]; //nao é aq
		}
		//cout << "k = " << k << endl;
		//cout << "for b = " << dp[b - nb][r - nr][s - ns][0] << endl;
		//cout << "for r = " << dp[b - nb][r - nr][s - ns][1] << endl;
		//cout << "for s = " << dp[b - nb][r - nr][s - ns][2] << endl;
		//cout << "try to append R" << endl;
		if(nr < r && last != 1){
			if(dp[b - nb][r - nr][s - ns][1] >= k){
				//cout << "append R" << endl;
				ans += 'R';
				last = 1;
				nr++;
				continue;
			}
			else k -= dp[b - nb][r - nr][s - ns][1]; //so tem como colocar s
		}
		//cout << "append S" << endl;
		ns++;
		ans += 'S';
		last = 2;
	}
	cout << ans << endl;
}
		  
 
