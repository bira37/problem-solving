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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, p, l, r;
	cin >> n >> p >> l >> r;
	if(l <= p && p <= r){
		int outl = (l-1); 
		int outr = (n - r);
		int ans = 0;
		if(outl > 0 && outr > 0){
			ans += min((p-l), (r-p)) + (r-l);
			ans += 2;
		}
		else if(outl > 0){
			ans += (p-l);
			ans++;
		}
		else if(outr > 0){
			ans += (r-p);
			ans++;
		}
		cout << ans << endl;
		return 0;
	}
	else {
		int outl = (l-1); 
		int outr = (n - r);
		int ans = 0;
		if(outl > 0 && outr > 0){
			ans += 2;
			ans += max(abs(p-l), abs(r-p));
		}
		else if(outl > 0){
			ans++;
			ans += abs(p-l);
		}
		else if(outr > 0){
			ans++;
			ans += abs(r-p);
		}
		cout << ans << endl;
		return 0;
	}
}		
