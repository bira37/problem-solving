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
	int k1,k2,k3;
	cin >> k1 >> k2 >> k3;
	if(min(k1, min(k2,k3)) == 1){
		cout << "YES" << endl;
		return 0;
	}
	int cnt2=0, cnt3= 0, cnt4 = 0;
	if(k1 == 2) cnt2++;
	else if(k1 == 3) cnt3++;
	else if(k1 == 4) cnt4++;
	
	if(k2 == 2) cnt2++;
	else if(k2 == 3) cnt3++;
	else if(k2 == 4) cnt4++;
	
	if(k3 == 2) cnt2++;
	else if(k3 == 3) cnt3++;
	else if(k3 == 4) cnt4++;
	
	if(cnt2 >= 2 || cnt3 == 3 || (cnt2 == 1 && cnt4 == 2)) cout << "YES" << endl;
	else cout << "NO" << endl;
}				