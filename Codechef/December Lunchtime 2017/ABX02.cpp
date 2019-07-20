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

int dp[101][101][101][51][2];
int p,q,b1,b2,s1,s2, n;

int solve(int i, int l1, int l2, int qtd1, bool flag){
	if(i == n) return 1;
	if(dp[i][l1][l2][qtd1][flag] != -1) return dp[i][l1][l2][qtd1][flag];
	
	dp[i][l1][l2][qtd1][flag] = 0;
	
	//box 1
	if(flag){
		if(l1 < b1){
			for(int c=1; c<=s1 && c+i <= n && qtd1+c <= p; c++){
				dp[i][l1][l2][qtd1][flag] += solve(i+c, l1+1, l2, qtd1+c, !flag);
				dp[i][l1][l2][qtd1][flag] = mod(dp[i][l1][l2][qtd1][flag]);
			}
		}
	}
	
	//box 2
	if(!flag){
		if(l2 < b2){
			for(int c=1; c<=s2 && c+i <= n && (i-qtd1) + c <= q; c++){
				dp[i][l1][l2][qtd1][flag] += solve(i+c, l1, l2+1, qtd1, !flag);
				dp[i][l1][l2][qtd1][flag] = mod(dp[i][l1][l2][qtd1][flag]);
			}
		}
	}
	
	//cout << "solve for " << i << " " << l1 << " " << l2 << " is -> " << dp[i][l1][l2][flag] << endl;
	
	return mod(dp[i][l1][l2][qtd1][flag]);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
	
		cin >> p >> q >> n >> b1 >> b2 >> s1 >> s2;
	
		for(int i=0; i<=n; i++){
			for(int j=0; j<=min(b1,100LL); j++){
				for(int k =0; k<=min(b2,100LL); k++){
					for(int w=0; w <= p; w++) dp[i][j][k][w][0] = dp[i][j][k][w][1] = -1;
				}
			}
		}
		
		int ans = solve(0,0,0, 0,true) + solve(0,0,0, 0,false);
	
		cout << mod(ans) << endl;
	}
}
