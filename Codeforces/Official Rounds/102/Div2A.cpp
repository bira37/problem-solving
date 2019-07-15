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
	int r1,r2,c1,c2,d1,d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	
	for(int a = 1; a<10; a++){
		for(int b =  1; b< 10; b++){
			for(int c = 1; c<10; c++){
				for(int d = 1; d < 10; d++){
					if(a+d == d1 && b+c == d2 && a+b == r1 && c+d == r2 && a+c == c1 && b+d == c2){
						if(a == b || a == c || a == d || b == c || b == d || c == d) continue;
						cout << a << " " << b << endl;
						cout << c << " " << d << endl;
						return 0;
					}
				}
			}
		}
	}
	
	cout << -1 << endl;
}