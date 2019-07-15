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

vector<int> adj[1123];
bool leaf[1123];
int cnt[1123];

void check(int u){
	if(adj[u].size() == 0) leaf[u] = true;
	for(int v : adj[u]){
		check(v);
		cnt[u] += leaf[v];
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	leaf[1] = false;
	for(int i=2; i<=n; i++){
		int u;
		cin >> u;
		adj[u].pb(i);
		leaf[i] = false;
	}
	check(1);
	bool flag = true;
	for(int i=1; i<=n; i++){
		if(!leaf[i] && cnt[i] < 3) flag = false;
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}