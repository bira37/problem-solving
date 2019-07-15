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

int bit[2][112345+1];

void init(int n){
	for(int i=1; i<=n; i++){
		bit[0][i] = 0;
		bit[1][i] = 0;
	}
}

//auxiliar
void update(int *bit, int idx, int val, int n){
	for(int i = idx; i <= n; i += i&-i){
		bit[i]+=val;
	}
}

//auxiliar
int query(int *bit, int idx){
	int ans = 0;
	for(int i=idx; i>0; i -= i&-i){
		ans += bit[i];
	}
	return ans;
}

void range_update(int l, int r, int val, int n){
	update(bit[0], l, val, n);
	update(bit[0], r+1, -val, n);
	update(bit[1], l, val*(l-1), n);
	update(bit[1], r+1, -val*r, n);
}

int prefix_query(int idx){
	return query(bit[0],idx)*idx - query(bit[1], idx);
}

int range_query(int l, int r){
	return prefix_query(r) - prefix_query(l-1);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	int newl,newr;
	cin >> newl >> newr;
	init(n);
	for(int i=0; i<n; i++){
		if(i) newl--,newr--;
		if(newr == 0) newr = n;
		if(newl == 0) newl = n;
		//cout << newl << " " << newr << endl;
		if(newl > newr){
			range_update(newl, n, v[i], n);
			if(newr-1 > 0) range_update(1, newr-1, v[i], n);
		}
		else range_update(newl, newr-1, v[i], n);
	}
	int best = -1;
	int ans = -1;
	for(int i=1; i<=n; i++){
		if(range_query(i,i) > best){
			best = range_query(i,i);
			ans = i;
		}
	}
	cout << ans << endl;
}