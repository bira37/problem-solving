#include <bits/stdc++.h>

#define ff first
#define ss second
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define IOS_SYNC ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>
#define vpll vector< pll >
#define vpii vector< pii >

using namespace std;

typedef long long ll;

////////////////////////CODE//////////////////////////////////////////////////////

int main(){
	IOS_SYNC(false);
	int n,c1,c2,c3;
	int t =1;
	while(cin >> n, n!=0){
		cin >> c1 >> c2 >> c3;
		int a[n+1];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		int dp[25][31];
		for(int i=0; i<25; i++){
			for(int j=0; j<=30; j++){
				dp[i][j] = INT_MAX;
			}
		}
		dp[1][a[1]] = (c1+c2)*a[1];
		for(int i=1; i<n; i++){
			for(int j=1; j<=30; j++){
				if(dp[i][j] == INT_MAX) continue;
				if(j < a[i+1]){
					dp[i+1][a[i+1]] = min(dp[i+1][a[i+1]], a[i+1]*c2 + dp[i][j] + (a[i+1]-j)*c1);
				}
				else {
					for(int k=j; k>=a[i+1]; k--){
						dp[i+1][k] = min(dp[i+1][k], dp[i][j] + c2*k + (j-k)*c3);
					}
				}
			}
		}
		int ans = INT_MAX;
		for(int i=0; i<=30; i++){
			ans = min(dp[n][i], ans);
		}
		cout << "Case " << t++ << ", cost = $" << ans << endl;
	}
	return 0;
}
