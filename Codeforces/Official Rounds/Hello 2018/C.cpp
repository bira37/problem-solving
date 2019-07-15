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

int cost[33];
int L, n;
int best[33];

int process(int x){
	if(best[x] != -1) return best[x];
	best[x] = min(cost[x], 2*process(x-1));
	return best[x];
}

int solve(int L, int x){
	if(L <= 0) return 0;
	if(x != 0){
		int op1 = ((L/(1LL<<(x))) + (L%((1LL<<(x))) != 0))*best[x];
		int op2 = (L/(1LL<<(x)))*best[x] + solve(L%((1LL<<(x))), x-1);
		return min(op1, op2);
	}
	else{
		int op1 = ((L/(1LL<<(x))) + (L%((1LL<<(x))) != 0))*best[x];
		return op1;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> L;
	for(int i=0; i<n; i++){
		cin >> cost[i];
		best[i] = -1;
	}
	best[0] = cost[0];
	process(n-1);
	cout << solve(L, n-1) << endl;
}