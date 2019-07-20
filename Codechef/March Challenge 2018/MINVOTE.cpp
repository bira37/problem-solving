#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
pair<int,int>, //change for pair<int,int> to use like multiset
null_type,
less< pair<int,int> >, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int v[n+1];
		vector<int> check;
		int ans1[n+1], ans2[n+1];
		int p[n+1];
		p[0] = 0;
		for(int i=1; i<=n; i++){
			cin >> v[i];
			p[i] = v[i] + p[i-1];
		}
		ordered_set s;
		//do for normal v/ans1
	
		for(int i=1; i<=n; i++){
			s.insert(make_pair(p[i-1] - v[i], i));
		}
		
		/*cout << "inside set" << endl;
		for(pair<int,int> x : s) cout << x.first <<  "," << x.second << " ";
		cout << endl;*/
	
		for(int i=1; i<=n; i++){
			s.erase(s.find(make_pair(p[i-1] - v[i], i)));
			ans1[i] = s.order_of_key(make_pair(p[i], 1123456));
		}
		
		/*cout << "partial ans" << endl;
		for(int i=1; i<=n; i++) cout << ans1[i] << " ";;
		cout << endl;*/
	
		reverse(v+1, v+n+1);
		p[0] = 0;
		for(int i=1; i<=n; i++){
			p[i] = v[i] + p[i-1];
		}
		s.clear();
	
		for(int i=1; i<=n; i++){
			s.insert(make_pair(p[i-1] - v[i], i));
		}
	
		for(int i=1; i<=n; i++){
			s.erase(s.find(make_pair(p[i-1] - v[i], i)));
			ans2[n-i+1] = s.order_of_key(make_pair(p[i], 1123456));
		}
	
		/*cout << "partial ans 2" << endl;
		for(int i=1; i<=n; i++) cout << ans2[i] << " ";;
		cout << endl;*/
		
		for(int i=1; i<=n; i++){
			if(i>1) cout << " ";
			cout << ans1[i] + ans2[i];
		}
		cout << endl;
	}
}
