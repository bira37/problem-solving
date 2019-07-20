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
#define int long long
 
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
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(NULL));
	int n,r, k;
	cin >> n >> r >> k;
 
	vector<int> ans;
	vector<int> factor;
 
	int tmp = k;
 
	//factorize k
 
	for(int i=2; i<=sqrt(tmp); i++){
		if(tmp%i) continue;
		factor.pb(i);
		int curr = 1;
		while(tmp%i == 0){
			curr *= i;
			tmp/=i;
		}
		if(curr <= r) ans.pb(curr);
	}
	
	if(tmp <= r) ans.pb(tmp);
	
	for(int i=1; i<=sqrt(k); i++){
		if(k%i) continue;
		factor.pb(i);
		factor.pb(k/i);
	}
 
	int lcm = 1;
	for(int x : ans) lcm = x*(lcm/__gcd(x,lcm));
 
	if(lcm != k){
		cout << -1 << endl;
		return 0;
	}
	
	//for(int x : ans){
	//	cout << x << " ";
	//}
	//cout << endl;
	
	sort(ans.begin(), ans.end());
	vector<int> best;
	do {
		vector<int> print;
		print.pb(ans[0]);
		for(int i=1; i<ans.size(); i++){
			if(print.back()*ans[i] <= r) print[print.size()-1] = print.back()*ans[i];
			else {
				print.pb(ans[i]);
			}
		}
		if(print.size() < best.size() || best.size() == 0){
			best.clear();
			for(int x : print) best.pb(x);
		}	
	} while( next_permutation(ans.begin(), ans.end()));
	ans.clear();
	for(int x : best) ans.pb(x);
	
	if(ans.size() == n){
		for(int num : ans) cout << num << " ";
		cout << endl;
		return 0;
	}
	
	if(ans.size() < n){
		set<int> print;
		for(int x : ans) print.insert(x);
		for(int x : factor){
			if(x > r) continue;
			print.insert(x);
			if(print.size() == n){
				for(int num : print) cout << num << " ";
				cout << endl;
				return 0;
			}
		}
		cout << -1 << endl;
		return 0;
	}
	
	cout << -1 << endl;
}
