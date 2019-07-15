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

struct query{
	int id, x;
};

bool in[1123456];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	int v[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	vector< query > list[n];
	for(int i=0; i<q; i++){
		int l,x;
		cin >> l >> x;
		query k;
		k.id = i;
		k.x = x;
		list[l-1].push_back(k);
	}
	int pr = 0;
	vector<int> pool;
	int cnt = 1;
	pool.pb(0); // start
	in[0] = true;
	int ans[q];
	for(int i=0; i<n; i++){
		if(in[v[i]]) cnt = mod(cnt*2);
		else {
			in[v[i]] = true;
			int sz = pool.size(); //dynamic
			for(int j=0; j<sz; j++){
				pool.pb((pool[j]^v[i]));
				in[(pool[j]^v[i])] = true;
			}
		}
		for(int id = 0; id < list[i].size(); id++){
			ans[list[i][id].id] = cnt*(int)in[list[i][id].x];
		}
	}
	for(int i=0; i<q; i++) cout << ans[i] << endl;
}