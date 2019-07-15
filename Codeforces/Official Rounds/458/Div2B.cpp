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
	int cnt[100001];
	for(int i=0; i<=100000; i++) cnt[i] = 0;
	set<int> s;
	vector<int> v;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		cnt[x]++;
		s.insert(x);
	}
	
	for(int x : s) v.pb(x);
	reverse(v.begin(), v.end());
	bool flag = false;
	for(int x : v){
		if(cnt[x] % 2) flag = true;
	}
	if(flag) cout << "Conan" << endl;
	else cout << "Agasa" << endl;
}