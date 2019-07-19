#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, a, b;
		cin >> a >> b;
		cin >> n;
		pair<int, int> v[n];
		int weight[n];
		int dp[2][22][80];
		for(int i=0; i<n; i++){
			cin >> v[i].ff >> v[i].ss >> weight[i];
		}
		for(int i=0; i<=21; i++){
			for(int j =0; j<=79; j++){
				dp[0][i][j] = 10000000;
				dp[1][i][j] = 10000000;
			}
		}
		dp[1][0][0] = 0;
		for(int i=0; i<n; i++){
			for(int j=a; j>=0; j--){
				for(int k = b; k>=0; k--){
					dp[i%2][j][k] = min(dp[!(i%2)][j][k], dp[!(i%2)][max(0, j-v[i].ff)][max(0,k-v[i].ss)] + weight[i]);
				}
			}
		}
		cout << dp[!(n%2)][a][b] << endl;
	}
}
			
	
