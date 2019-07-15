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
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int r, x1,y1,x2,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	cout << fixed << setprecision(15);
	if(r*r <= (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)){
		cout << x1 << " " << y1 << " " << r << endl;
		return 0;
	}
	int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	pair<double, double> vec(x1-x2, y1-y2);
	double size_vec = sqrt(vec.ff*vec.ff + vec.ss*vec.ss);
	double dist = sqrt(d);
	dist += r;
	double new_r = dist/2.00000000000;
	if(size_vec != 0){
		vec.ff *= new_r;
		vec.ss *= new_r;
		vec.ff /= size_vec;
		vec.ss /= size_vec;
		cout << vec.ff+x2 << " " << vec.ss+y2 << " " << new_r << endl;
	}
	else {
		cout << x1 << " " << y1+new_r << " " << new_r << endl;
	}
}