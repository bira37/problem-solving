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

struct edge{
	int u,v,c;
	edge() {}
	edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

vector<int> adj[112345];
vector<int> adjc[112345];
int d[112345];

vector<edge> e;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,s;
	cin >> n >> m >> s;
	for(int i=0; i<112345; i++) d[i] = (int)1e9;
	for(int i=0; i<m; i++){
		int u,v,c;
		cin >> u >> v >> c;
		e.pb(edge(u,v,c));
		adj[u].pb(v);
		adj[v].pb(u);
		adjc[u].pb(c); adjc[v].pb(c);
	}
	int l;
	cin >> l;
	if(l == 0){
		cout << 1 << endl;
		return 0;
	}
	priority_queue< ii, vector< ii > , greater< ii > > pq;
	pq.push(ii(0, s));
	d[s] = 0;
	while(!pq.empty()){
		ii curr = pq.top();
		pq.pop();
		if(curr.ff > d[curr.ss]) continue;
		for(int i=0; i<adj[curr.ss].size(); i++){
			int v = adj[curr.ss][i];
			int dist = adjc[curr.ss][i];
			if(curr.ff + dist >= d[v]){
				continue;
			}
			d[v] = curr.ff + dist;
			pq.push(ii(d[v], v));
		}
	}
	int ans = 0;
	for(int i=0; i<e.size(); i++){
		int u = e[i].u;
		int v = e[i].v;
		int c = e[i].c;
		//cout << "at " << u << " " << v << " " << c << endl;
		//cout << "d " << d[u] << " " << d[v] << endl;
		//cout << (l-d[u]) << " " << (c - (l-d[u])) << endl;
		if(d[u] < l && (l - d[u]) < c && c - (l-d[u]) + d[v] > l) ans++;
		if(d[v] < l && (l - d[v]) < c && c - (l-d[v]) + d[u] > l) ans++;
		if(d[v] < l && d[u] < l && d[u] + d[v] + c == 2*l) ans++;
	}
	//cout << ans << endl;
	for(int i=1 ; i<= n; i++) if(d[i] == l) ans++;
	cout << ans << endl;
}