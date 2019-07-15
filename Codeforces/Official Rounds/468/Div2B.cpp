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
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> v;
	for(int i=0; i<n; i++){
		v.push_back(i+1);
	}
	int ans = 0;
	while(true){
		ans++;
		vector<int> new_v;
		for(int i=0; i<v.size(); i+=2){
			if(v[i] == a && v[i+1] == b || v[i] == b && v[i+1] == a){
				if(v.size() == 2) cout << "Final!" << endl;
				else cout << ans << endl;
				return 0;
			}
			if(v[i] == a || v[i] == b){
				new_v.push_back(v[i]);
			}
			else if(v[i+1] == a || v[i+1] == b){
				new_v.push_back(v[i+1]);
			}
			else new_v.push_back(v[i]);
		}
		v.clear();
		for(int x : new_v) v.push_back(x);
	}
}
	