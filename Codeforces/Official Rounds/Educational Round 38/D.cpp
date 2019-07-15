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
#define int long long

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
vector<int> adjc[212345];
int a[212345];
int d[212345];
int dp[212345];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int u,v, c;
		cin >> u >> v >> c;
		adj[u].pb(v);
		adj[v].pb(u);
		adjc[u].pb(2*c);
		adjc[v].pb(2*c);
	}
	
	d[0] = (int)(1e18);
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		adj[0].pb(i);
		adjc[0].pb(x);
		d[i] = (int)(1e18);
	}
	
	priority_queue< ii, vector < ii > , std::greater< ii > > pq;
	pq.push(ii(0,0));
	
	while(!pq.empty()){
		ii curr = pq.top();
		pq.pop();
		if(d[curr.ss] < curr.ff) continue;
		for(int i = 0; i < adj[curr.ss].size(); i++){
			int cost = adjc[curr.ss][i];
			int v = adj[curr.ss][i];
			if(d[v] > curr.ff + cost){
				d[v] = curr.ff+cost;
				pq.push(ii(d[v], v));
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		if(i > 1) cout << " ";
		cout << d[i];
	}
	cout << endl;
}