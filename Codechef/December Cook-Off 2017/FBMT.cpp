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
	int t;
	cin >> t;
	while(t--){
		int n;
		map<string, int> m;
		cin >> n;
		vector<string> a;
		string s;
		if(n > 0){
			cin >> s;
			a.push_back(s);
			m[s]++;
			n--;
		}
		while(n>0){
			cin >> s;
			if(s != a[0]) a.push_back(s);
			m[s]++;
			n--;
		}
		if(a.size() == 0) cout << "Draw" << endl;
		else if(a.size() == 1) cout << a[0] << endl;
		else if(m[a[0]] > m[a[1]]) cout << a[0] << endl;
		else if(m[a[1]] > m[a[0]]) cout << a[1] << endl;
		else cout << "Draw" << endl;
	}
}
