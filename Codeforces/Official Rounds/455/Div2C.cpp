#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define mod(n) (n%1000000007)
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long
using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

char v[5123];
int dp[5123][5123];
int n;

int solve(int i, int f){
	if(dp[i][f] != -1) return dp[i][f];
	if(i == n && f == 0){
		dp[i][f] = 1;
		//cout << "dp[" << i << "][" << f << "] -> " << dp[i][f] << endl;
		return 1;
	}
	if(i == n){
		dp[i][f] = 0;
		//cout << "dp[" << i << "][" << f << "] -> " << dp[i][f] << endl;
		return 0;
	}
	dp[i][f] = 0;
	if(v[i] == 's'){
		if(f > 0) dp[i][f] += solve(i+1, f-1);
		dp[i][f] = mod(dp[i][f]);
		dp[i][f] += solve(i+1, f);
		dp[i][f] = mod(dp[i][f]);
	}
	else if(v[i] == 'f'){
		if(f == 0) dp[i][f] += solve(i+1, f+1);
		else {
			dp[i][f] += solve(i+1, f);
			dp[i][f] = mod(dp[i][f]);
			dp[i][f] += solve(i+1, f+1);
			dp[i][f] = mod(dp[i][f]);
		}
			
	}
	//cout << "dp[" << i << "][" << f << "] -> " << dp[i][f] << endl;
	dp[i][f] = mod(dp[i][f]);
	return dp[i][f];
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++) dp[i][j] = -1;
	}
	cout << solve(0,0) << endl;
}