#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
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

inline int mod(int n){ return (n%1000000007); } 

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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n,h;
	cin >> n >> h;
	int v[n+1];
	for(int i=1; i<=n; i++) cin >> v[i];
	int dp[n+1][n+1];
	for(int i=0; i<=n; i++) dp[0][i] = 0;
	dp[0][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j = 0; j<=n; j++){
			if(v[i] + j == h){
				dp[i][j] = mod((j-1 >= 0 ? dp[i-1][j-1] : 0) + dp[i-1][j]);
			}
			else if(v[i] + j + 1 == h){
				dp[i][j] = mod(dp[i-1][j] + (j+1 <= n ? (j+1)*dp[i-1][j+1] : 0) + j*dp[i-1][j]);
			}
			else dp[i][j] = 0;
			if(dp[i][j] > (int)1e9 + 7) cout << "VAI TOMAR NO CU" << endl;
			//cout << "dp of " << i << " " << j << " = " << dp[i][j] << endl;
		}
	}
	cout << mod(dp[n][0]) << endl;
}
		
		
		
		