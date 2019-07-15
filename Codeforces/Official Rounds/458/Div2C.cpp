#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
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

string s;
int k;

int target;
int dp[1001] = {0};
int C[1000+1][1000+1];

void solve(int i, int n, int active){
	if(i == s.size()){
		dp[active]++;
		dp[active] %= M;
		return;
	}
	if(s[i] == '0') solve(i+1,n -1, active);
	else {
		for(int i=0; i<=n; i++){
			dp[i+active] += C[n][i];
			dp[i+active] %= M;
		}
		solve(i+1, n-1, active+1);
	}
}

int binomialCoeff(int n, int k)
{
    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j] %= M;
            }
        }
    }

    return C[n][k];
}

int get(int n){
	if(n == 0) return 0;
	int ans = 1;
	while(n != 1){
		int aux = n;
		n = __builtin_popcount(aux);
		ans++;
	}
	return ans;
}
	
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	cin >> k;
	bool one = false;
	for(char c : s) if(c == '1') one = true;
	binomialCoeff(1000,1000);
	
	vector<int> can;
	for(int i=0; i<=1000; i++){
		if(get(i) == k) can.pb(i);
	}
	
	int ans = 0;
	
	solve(0, s.size()-1, 0);
	
	for(int x : can){
		ans += dp[x];
		ans %= M;
	}
	
	cout << ans -( k == 1 && one) << endl;
}