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

vector<int> adj[112345];
int dg[112345];
int t[112345];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> t[i];
	}
	queue< int > pro, co;
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
		dg[u]++;
	}
	
	for(int i=0; i<n; i++){
		if(dg[i] == 0){
			if(t[i]) co.push(i);
			else pro.push(i);
		}
	}
	int ans = 0;
	while(!co.empty() || !pro.empty()){
		while(!pro.empty()){
			int now = pro.front();
			pro.pop();
			for(int v : adj[now]){
				dg[v]--;
				if(dg[v] == 0){
					if(t[v]) co.push(v);
					else pro.push(v);
				}
			}
		}
		if(!co.empty()) ans++;
		while(!co.empty()){
			int now = co.front();
			co.pop();
			for(int v : adj[now]){
				dg[v]--;
				if(dg[v] == 0){
					if(t[v]) co.push(v);
					else pro.push(v);
				}
			}
		}
	}
	cout << ans << endl;
}