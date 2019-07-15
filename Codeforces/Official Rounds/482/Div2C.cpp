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

int sz[312345];

vector<int> adj[312345];

int n,x,y;
int ans1 = 0, ans2 = 0;

bool dfs(int u, int p){
	bool ret = false;
	sz[u] = 1;
	int tira = 0;
	for(int v : adj[u]){
		if(v == p) continue;
		if(dfs(v,u)){	
			ret |= true;
			tira = sz[v];
		}
		sz[u] += sz[v];
	}
	if(ret && p == -1){
		ans1 = sz[u] - tira;
	}
	ret |= (u == y);
	return ret;
}

bool dfs2(int u, int p){
	bool ret = false;
	sz[u] = 1;
	int tira = 0;
	for(int v : adj[u]){
		if(v == p) continue;
		if(dfs2(v,u)){	
			ret |= true;
			tira = sz[v];
		}
		sz[u] += sz[v];
	}
	if(ret && p == -1){
		ans2 = sz[u] - tira;
	}
	ret |= (u == x);
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> x >> y;
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(x, -1);
	dfs2(y, -1);
	
	//cout << ans1 << " " << ans2 << endl;
	cout << (n*(n-1)) - (ans1*ans2) << endl;
	
}
