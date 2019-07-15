#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
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
	int n;
	cin >> n;
	int k = n/2;
	int v[k];
	for(int i=0; i<k; i++) cin >> v[i];
	sort(v, v+k);
	
	int ans = INT_MAX;
	
	//white
	int cur = 0;
	for(int i=0; i<k; i++){
		cur += abs(v[i] - (2*i+1));
	}
	ans = min(ans, cur);
	
	//black
	cur = 0;
	for(int i=0; i<k; i++){
		cur += abs(v[i] - (2*i+2));
	}
	ans = min(ans, cur);
	
	cout << ans << endl;
}