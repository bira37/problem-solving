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
	int n;
	cin >> n;
	pair<int,int> v[n];
	int a[n];
	for(int i=0; i<n; i++){
	  cin >> v[i].ff;
	  v[i].ss = i;
	}
	sort(v, v+n);
	int ans[n];
	int median = n/2-1;
	for(int i=0; i<n; i++){
	  if(i > median) ans[v[i].ss] = v[median].ff;
	  else ans[v[i].ss] = v[median+1].ff;
	}
	for(int i=0; i<n; i++){
	  cout << ans[i] << endl;
	}
}
