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

int dp[501][501] = {0};
int memo[501][501] = {0};
string s;
	
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		int num = 0;
		vector<int> v;
		for(int j =0; j<m; j++){
			char c;
			cin >> c;
			if(c == '1'){
				num++;
				v.pb(j);
			}
		}
		for(int j=0; j<=k; j++) dp[i][j] = 100000000;
		for(int j=0; j<v.size(); j++){
			for(int j2 = j; j2<v.size(); j2++){
				int maintain = j2-j+1;
				int poped = num - maintain;
				if(poped <= k){
					dp[i][poped] = min(dp[i][poped], v[j2] - v[j] +1);
				}
			}
		}
		for(int j=v.size(); j<=k; j++) dp[i][j] = 0;
	}		
	for(int i=0; i<=n; i++){
		for(int j = 0; j<=k; j++) memo[i][j] = (int)1e9;
	}
	memo[0][0] = 0;
	for(int i=1; i<=n; i++){
	
		for(int j=0; j<=k; j++){
			
			for(int h=0; h<=j; h++){
				memo[i][j] = min(memo[i][j], memo[i-1][h] + dp[i-1][j-h]);
			}
		}
	}
	cout << memo[n][k] << endl;
}