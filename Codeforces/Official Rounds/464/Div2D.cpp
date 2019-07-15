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

vector<int> adj[26];
bool vis[26];

bool possible(int s, int t){
	for(int i=0; i<26; i++) vis[i] = false;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		if(u == t) return true;
		for(int v : adj[u]){
			if(vis[v]) continue;
			q.push(v);
		}
	}
	if(vis[t]) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	vector< ii > ans;
	for(int i=0; i<s.size(); i++){
		if(s[i] != t[i]){
			if(possible(s[i]-'a',t[i]-'a') || possible(t[i]-'a',s[i]-'a')) continue;
			adj[s[i]-'a'].pb(t[i]-'a');
			adj[t[i]-'a'].pb(s[i]-'a');
			ans.pb(ii(s[i]-'a', t[i]-'a'));
		}
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		cout << char('a'+ans[i].ff) <<  " " << char('a'+ans[i].ss) << endl;
	}

}