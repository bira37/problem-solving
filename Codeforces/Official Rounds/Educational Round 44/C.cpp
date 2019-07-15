#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
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
	
	int n,k,l;
	cin >> n >> k >> l;
	int m = n*k;
	int v[m];
	multiset<int, greater<int> > s;
	for(int i=0; i<m; i++){
		cin >> v[i];
		s.insert(v[i]);
	}
	sort(v, v+m);
	vector<int> b[n];
	int cnt = 0;
	int cur = -1;
	multiset<int> starter, useless;
	for(int i=0; i<m; i++){
		if(v[i] - v[0] <=l){
			cnt++;
			starter.insert(v[i]);
		}
		else useless.insert(v[i]);
	}
	if(cnt < n){
		cout << 0 << endl;
		return 0;
	}
	int rem = n;
	for(int i=0; i<n; i++){
		b[i].pb(*starter.begin());
		starter.erase(starter.begin());
		rem--;
		while(b[i].size() < k){
			if(starter.size() > rem){
				b[i].pb(*starter.begin());
				starter.erase(starter.begin());
			}
			else {
				b[i].pb(*useless.begin());
				useless.erase(useless.begin());
			}
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		int menor = INT_MAX;
		for(int x : b[i]){
			menor = min(menor, x);
			//cout << x << " ";
		}
		ans += menor;
		//cout << endl;
	}
	cout << ans << endl;
}