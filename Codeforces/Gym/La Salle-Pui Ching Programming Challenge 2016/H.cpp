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
 
short dp[1001][10001];
ii last[1001][10001];
 
vector< ii > adj[1123];
 
int a,b;
int k;
 
bool solve(int u, int d, int p, int ld){
	if(dp[u][d] != -1) return dp[u][d];
	if(u == b && d == k){
		last[u][d] = ii(p, ld);
		dp[u][d] = 1;
		return dp[u][d];
	}
	dp[u][d] = 0;
	last[u][d] = ii(p, ld);
	for(ii v : adj[u]){
		if(d + v.ss > k) continue;
		dp[u][d] += solve(v.ff, d + v.ss, u, d);
		dp[u][d] = min(dp[u][d], short(1));
	}
	
	return dp[u][d];
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n,m;
	cin >> n >> m >> k;
	cin >> a >> b;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=10000; j++){
			dp[i][j] = -1;
		}
	}
	
	for(int i=0; i<m; i++){
		int u,v, c;
		cin >> u >> v >> c;
		adj[u].pb(ii(v,c));
		adj[v].pb(ii(u,c));
	}
	if(solve(a,0, -1, -1) == 1){
		vector<int> path;
		ii curr(b, k);
		while(curr.ff != -1){
			//cout << "recovering " << curr.ff << " " << curr.ss << endl;
			path.pb(curr.ff);
			curr = last[curr.ff][curr.ss];
			//cin.get();
		}
		reverse(path.begin(), path.end());
		for(int x : path) cout << x << " ";
		cout << endl;
	}
	else cout << "Impossible" << endl;
} 
