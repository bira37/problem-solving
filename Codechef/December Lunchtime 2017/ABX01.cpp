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

int digitsum(int n){
	int sum = 0;
	while(n > 0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int solve(int n, int k){
	if(k == 1){
		int ret = digitsum(n);
		while(ret >= 10) ret = digitsum(ret);
		return ret;
	}
	else {
		int ret1,ret2;
		if(k%2){
			ret1 = solve(n, k/2);
			ret2 = ret1*n;
		}
		else {
			ret1 = solve(n,k/2);
			ret2 = ret1;
		}
		while(ret1 >= 10) ret1 = digitsum(ret1);
		while(ret2 >= 10) ret2 = digitsum(ret2);
		int ret = ret1*ret2;
		ret = digitsum(ret);
		while(ret >= 10) ret = digitsum(ret);
		return ret;
	}
}	

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}
