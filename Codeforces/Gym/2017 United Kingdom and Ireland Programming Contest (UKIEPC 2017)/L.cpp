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
#define int long long
 
using namespace std;
using namespace __gnu_pbds;
 
vector<int> lis;
 
int calculate_lis(vector<int> & v){
	int n = v.size();
	lis.resize(n+1);
	for(int i=1; i<=n; i++) lis[i] = INT_MAX;
	lis[0] = INT_MIN;
	for(int i=0; i<n; i++){
		int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
		index--;
		lis[index+1] = min(lis[index+1], v[i]);
	}
	for(int i=n; i>=1; i--){
		if(lis[i] != INT_MAX) return i;
	}
	return 0;
} 
 
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
 
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x,y;
	cin >> x >> y;
	
	int n;
	cin >> n;
	
	map< ii, vector< pair<int,int> > > m;
	
	
	for(int i=0; i<n; i++){
		int xa,ya,h;
		cin >> xa >> ya >> h;
		int vx = xa - x, vy = ya - y;
		int g;
		if(vx != 0 && vy != 0) g = gcd(abs(vx), abs(vy));
		else g = 0;
		if(g != 0) vx /= abs(g);
		if(g != 0) vy /= abs(g);
		if(vx == 0 && vy != 0){
			g = abs(vy);
			vy /= abs(vy);
		}
		if(vy == 0 && vx != 0){
			g = abs(vx);
			vx /= abs(vx);
		}
		g = abs(g);
		m[ii(vx,vy)].pb(ii(g, h));
	}
	
	
	int ans = 0;
	for(auto & p : m){
		vector<int> v;
		sort(p.second.begin(), p.second.end());
		for(ii x : p.second) v.pb(x.second);
		ans += calculate_lis(v);
	}
	cout << ans << endl;
}
