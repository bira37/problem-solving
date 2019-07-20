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
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<int> v;
	
	for(int i=0; i<15; i++){
		char c;
		cin >> c;
		if(c == '?') v.pb(-1);
		else v.pb(c - '0');
	}
	
	for(int a = 0; a < 5; a++){
	
		for(int b = 0; b < 5; b++){
		
			for(int c = 0; c < 5; c++){
			
				for(int d = 0; d < 5; d++){
				
					for(int start = 1; start < 5; start++){
					
						int equal = 0;
						vector<int> curr;
						curr.pb(start);
						
						for(int i=0; i < 14; i++){
							 curr.pb(a*(curr.back()*curr.back()*curr.back()) + b*(curr.back()*curr.back()) + c*(curr.back()) + d);
							 curr[curr.size()-1] %= 5LL;
							 if(curr.back() == 0) equal = -1;
						}
						
						for(int i=0; i<15; i++){
							if(v[i] == -1) equal++;
							else if(v[i] == curr[i]) equal++;
						}
						
						if(equal == 15){
							cout << a << " " << b << " " << c << " " << d << " " << 5 << " " << start << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	
	cout << "-1 -1 -1 -1 -1 -1" << endl;
}
