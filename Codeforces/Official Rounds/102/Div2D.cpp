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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	int black = 0;
	int white = 0;
	if(n < 2){
		cout << m << endl;
		return 0;
	}
	if(m < 2){
		cout << n << endl;
		return 0;
	}
	if(n == 2 && m == 2){
		cout << 4 << endl;
		return 0;
	}
	if(m == 2) swap(n,m);
	if(n == 2){
		if(m%4 == 1) cout << m+1 << endl;
		else cout << 4*((m+3)/4) << endl;
	}
	else {
		cout << (n*m+1)/2 << endl;
	}
}