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
	
	int n;
	cin >> n;
	
	set< ii > s;
	for(int i=0; i<=n; i++){
		for(int j=i+1; j<n; j++){
			s.insert(ii(i,j));
		}
	}
	int ans = 0;
	for(int offset = 0; offset <n; offset++){
		for(int i=offset+1; i<=n; i++){
			//cout << offset << " " << i << "//";
			//cout << i << " " << n-offset << endl;
			if(s.find(ii(offset,i)) != s.end()){
				ans++;
				s.erase(s.find(ii(offset,i)));
			}
			if(s.find(ii(i,n-offset)) != s.end()) s.erase(s.find(ii(i,n-offset)));
		} 
	}
	cout << ans+1 << endl;
}
	