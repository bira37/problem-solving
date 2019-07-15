#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
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
int v[512345] = {0};
int n, r, k;

int check(int m){
	vector<int> acc(n);
	int sum = 0;
	int res = 0;
	for(int i=0; i<n; i++){
		if(res > (int)1e18) return res;
		sum += acc[i];
		if(v[i] < m - sum){
			int need = m - v[i] - sum;
			sum += need;
			res += need;
			if(i + 2*r +1 < n) acc[i+2*r+1] -= need;
		}
	}
	return res;
}

map<int,int> m;
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> r >> k;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v[max(0LL, i-r)] += x;
		if(i+r+1 <= n-1) v[i+r+1] -= x;
	}
	
	for(int i=1; i<n; i++){
		v[i] += v[i-1];
	}
	int l = 0, r = (int)2e18;
	int ans = 0;
	while(l <=r){
		int m = (l+r)>>1;
		if(check(m) <= k){
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	cout << ans << endl;
}