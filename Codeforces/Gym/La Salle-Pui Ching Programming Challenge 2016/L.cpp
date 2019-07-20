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
 
int f[10000001];
int v[100001];
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<=10000000; i++) f[i] = 0;
	for(int i=0; i<n; i++){
		cin >> v[i];
		f[v[i]]++;
	}
 
	for(int i=1; i<=10000000; i++) f[i] += f[i-1];
	cout << fixed << setprecision(8) << endl;
	if(n == 1) cout << 0 << " " << 1 << " " << 0 << endl;
	else {
		for(int i=0; i<n; i++){
			double f1,f2,f3;
 
			f1 = (v[i] == 0 ? 0 : f[v[i]-1]);
			f2 = f[v[i]] - (v[i] == 0 ? 0 : f[v[i]-1]);
			f3 = f[10000000] - f[v[i]];
 
			cout << f3/(n)*1.0 << " " << f2/(n)*1.0 << " " << f1/(n)*1.0 << endl;
		}
	}
}
