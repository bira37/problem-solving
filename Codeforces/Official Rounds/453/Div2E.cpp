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
typedef long long ll;

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

vector<int> pool;
vector<int> adj[312345];
int v[312345];
int prefix[312345];
int vis[312345];

void dfs(int u, int p){
	vis[u] = 1;
	pool.pb(u);
	for(int ad : adj[u]){
		if(ad == p) continue;
		if(vis[ad] == 1){
			int lb = (int)1e9;
			int ub = (int)-1e9;
			for(int i = pool.size()-1; i>= 0; i--){
				lb = min(lb, pool[i]);
				ub = max(ub, pool[i]);
				if(pool[i] == ad) break;
			}
			v[lb] = ub-1;
		}
		else if(!vis[ad]) dfs(ad, u);
	}
	vis[u] = 2;
	pool.pop_back();
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		if(u == v) continue;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for(int i=1; i<=n; i++){
		v[i] = n;
		vis[i] = 0;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i, -1);
		}
	}
	
	for(int i=n-1; i>=1; i--){
		v[i] = min(v[i+1], v[i]);
	}
	
	//for(int i=1; i<=n; i++) cout << i << " " << v[i] << endl;
	prefix[0] = 0;
	for(int i=1; i<=n; i++) prefix[i] = prefix[i-1] + (v[i]-i+1);
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		int l = x, r = y, ans = x-1;
		while(l <= r){
			int m = (l+r)/2;
			if(v[m] < y){
				ans = m;
				l = m+1;
			}
			else r = m-1;
		}
		int inteiro = prefix[ans] - prefix[x-1]; 
		int resto_todo = ((y - ans)*(y-ans+1))/2LL;
		cout << inteiro + resto_todo << endl;
	}
}