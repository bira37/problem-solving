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
	int n,k;
	cin >> n >> k;
	int v[n+1];
	int awake[n+1];
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	for(int i=1; i<=n; i++){
		cin >> awake[i];
	}
	int p[n+1];
	p[0] = 0;
	for(int i=1; i<=n; i++){
		if(awake[i] == 0) p[i] = v[i] + p[i-1];
		else p[i] = p[i-1];
	}
	int ans = 0;
	for(int i=1; i<=n; i++) if(awake[i] == 1) ans += v[i];
	int best = 0;
	for(int i=k; i<=n; i++){
		best = max(best, p[i] - p[i-k]);
	}
	cout << ans + best << endl;
}