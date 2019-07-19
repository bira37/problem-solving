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

int v[1001][2];
int memo[1001][2];

////////////////////////CODE//////////////////////////////////////////////////////

ll dp(int n, int l){
	if(n < 0) return 0;
	else if(memo[n][l] != -1) return memo[n][l];
	else{
		memo[n][l] = max(dp(n-1,0) + v[n][0] + abs(v[n+1][!l] - v[n][1]), dp(n-1, 1) + v[n][1] + abs(v[n+1][!l] - v[n][0]));
		//cout << "calculando dp[" << n << "][" << l << "]" << endl;
		//cout << v[n][0] + abs(v[n+1][!l] - v[n][1]) << endl;
		//cout << v[n][1] + abs(v[n+1][!l] - v[n][0]) << endl;
	}
	//cout << "memo[" << n << "][" << l << "] = " << memo[n][l] << endl;
	return memo[n][l];
}

int main(){
	IOS_SYNC(false);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i][0] >> v[i][1];
		memo[i][0] = -1;
		memo[i][1] = -1;
	}
	
	cout << max(dp(n-2,0) + v[n-1][0], dp(n-2, 1) + v[n-1][1]) << endl;
}
