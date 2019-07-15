#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define mod(n) (n%1000000007)
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define N 3123

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

int bit[2][N+1];

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int v[n];
	int inv[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			inv[i][j] = 0;
		}
	}
	for(int i=0; i<n; i++) cin >> v[i];
	for(int i=0; i<n; i++){
		range_update(v[i], v[i], 1, n);
		for(int j=i+1; j<n; j++){
			inv[i][j] = inv[i][j-1] + range_query(v[j]+1, n);
			range_update(v[j], v[j], 1, n);
		}
		range_update(v[i], v[i], -1, n);
		for(int j=i+1; j<n; j++){
			range_update(v[j], v[j], -1, n);
		}
	}
	int inversion = inv[0][n-1];
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		l--,r--;
		int aux = ((r-l+1)*(r-l))/2;
		inversion -= inv[l][r];
		inversion += (aux - inv[l][r]);
		inv[l][r] = aux;
		if(inversion % 2) cout << "odd" << endl;
		else cout << "even" << endl;
	}
}
	