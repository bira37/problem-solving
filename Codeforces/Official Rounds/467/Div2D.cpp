#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

inline int mod(int n){ return (n%1000000007); } 

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

vector<int> adj[212345];
bool vis[212345][2];
vector<int> ans;
bool yes;
void solve(int u, bool par){
	vis[u][par] = true;
	if(adj[u].size() == 0 && par == 1){
		yes = true;
		ans.push_back(u);
		return;
	}
	for(int v : adj[u]){
		if(vis[v][!par]) continue;
		solve(v, !par);
		if(yes) {
			ans.pb(u);
			return;
		}
	}
}

bool cycle = false;

int vis2[212345] ={0};
void check(int u){
	vis2[u] = 1;
	for(int v : adj[u]){
		if(vis2[v] == 1){
			cycle = true;
		}
		else if(vis2[v] == 0) check(v);
		if(cycle) return;
	}
	vis2[u] = 2;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		for(int j = 0; j<k; j++){
			int ad;
			cin >> ad;
			adj[i].pb(ad);
		}
	}
	
	yes = false;
	int s;
	cin >> s;
	solve(s, 0);
	check(s);
	if(yes){
		cout << "Win" << endl;
		reverse(ans.begin(), ans.end());
		for(int x : ans) cout << x << " ";
		cout << endl;
	}
	else {
		if(cycle){
			cout << "Draw" << endl;
		}
		else cout << "Lose" << endl;
	}
}