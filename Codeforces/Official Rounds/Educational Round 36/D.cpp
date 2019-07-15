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
#define N 1123

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

//Implementation uses dsu (cut parallel edges)

set<int> adj[N];
vii test;
int vis[510] = {0};
int quem;
bool continua = false;

bool dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(vis[v] == 2) continue;
		if(vis[v] == 1){
			test.pb(ii(u,v));
			quem = v;
			continua = true;
			return true;
		}
		bool flag = dfs(v);
		if(flag){
			if(continua) test.pb(ii(u,v));
			if(u == quem){
				continua = false;
			}
			return true;
		}
	}
	vis[u] = 2;
	return false;
}

bool check(int u){
	vis[u] = 1;
	bool ret = true;
	for(int v : adj[u]){
		if(vis[v] == 1) return false;
		if(vis[v] == 2) continue;
		ret = ret & check(v);
	}
	vis[u] = 2;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		adj[u].insert(v);
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i] == 0) dfs(i);
		if(test.size() > 0) break;
	}
	
	if(test.size() == 0){
		cout << "YES" << endl;
		return 0;
	}
	
	for(ii e : test){
		//cout << "erasing " << e.ff << " " << e.ss << endl;
		adj[e.ff].erase(adj[e.ff].find(e.ss));
		
		for(int i=0; i<=n; i++) vis[i] = 0;
		bool ok = true;
		for(int i=1; i<=n; i++){
			if(vis[i] == 0) ok = ok & check(i);
		}
		if(ok){
			cout << "YES" << endl;
			return 0;
		}
		adj[e.ff].insert(e.ss);
	}
	
	cout << "NO" << endl;
}