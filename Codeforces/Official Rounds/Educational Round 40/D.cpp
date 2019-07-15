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

vector<int> adj[1123];
set< ii > e;
int p[1123];
int ds[1123], dt[1123];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		e.insert(ii(min(u,v), max(u,v)));
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=0; i<=n; i++) ds[i] = dt[i] = 100000;
	
	queue< ii > q;
	q.push(ii(s, 0));
	ds[s] = 0;
	
	while(!q.empty()){
		ii curr = q.front();
		q.pop();
		for(int v : adj[curr.ff]){
			if(ds[v] <= curr.ss+1) continue;
			ds[v] = curr.ss+1;
			q.push(ii(v,ds[v]));
		}
	}
	q.push(ii(t,0));
	dt[t] = 0;
	while(!q.empty()){
		ii curr = q.front();
		q.pop();
		for(int v : adj[curr.ff]){
			if(dt[v] <= curr.ss+1) continue;
			dt[v] = curr.ss+1;
			q.push(ii(v,dt[v]));
		}
	}
	int ans = 0;	
	int dist = ds[t];
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			//cout << i << " and " << j << endl;
			//cout << ds[i] << " " << dt[j] << endl;
			//cout << dt[i] << " " << ds[j] << endl;
			//cout << endl;
			if(e.count(ii(min(i,j), max(i,j)))) continue;
			if(min(ds[i] + dt[j], ds[j] + dt[i])+1 < dist) continue;
			ans++;
		}
	}
	
	cout << ans << endl;
}
		