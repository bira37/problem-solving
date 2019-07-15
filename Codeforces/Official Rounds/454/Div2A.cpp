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
	int big,mid,small, masha;
	cin >> big >> mid >> small >> masha;
	
	for(int i=1; i<=200; i++){
		for(int j = i+1 ; j<= 200; j++){
			for(int k = j+1; k<= 200; k++){
				if(small <= i && 2*small >= i && mid <= j && 2*mid >= j && big <= k && 2*big >= k){
					if(masha <= i && 2*masha >= i && masha <= j && 2*masha < j && masha <= k && 2*masha < k){
						cout << k << endl << j << endl << i << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
}
	
	