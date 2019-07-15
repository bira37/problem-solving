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
#define Y 1123456
#define double long double

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
	int r;
	cin >> n >> r;
	vector<double> ansy;
	double vx[n];
	for(int i=0; i<n; i++){
		cin >> vx[i];
	}
	ansy.push_back(r);
	for(int i=1; i<n; i++){
		double curr = r;
		for(int j = 0; j<ansy.size(); j++){
			if(abs(vx[j] - vx[i]) > 2*r) continue;
			double dty = (2.0*r)*(2.0*r) - (vx[i]-vx[j])*(vx[i] - vx[j]);
			curr = max(curr, ansy[j]+sqrt(dty));
		}
		ansy.push_back(curr);
	}
	cout << fixed << setprecision(9);
	for(int i=0; i<ansy.size(); i++){
		if(i) cout << " ";
		cout << ansy[i];
	}
	cout << endl;
}