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
	string s;
	cin >> s;
	int x = 0, y = 0;
	int ans = 0;
	bool top;
	for(char c : s){
		if(x == 0 && y == 0){
			if(c == 'U'){
				top = true;
				y++;
			}
			else {
				top = false;
				x++;
			}
			continue;
		}
		if(c == 'U'){
			if(x == y && top == false) ans++, top = true;
			y++;
		}
		else {
			if(x == y && top == true) ans++, top = false;
			x++;
		}
	}
	cout << ans << endl;
}
		