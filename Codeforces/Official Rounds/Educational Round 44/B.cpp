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
	
	int n,m;
	cin >> n >> m;
	char mat[n][m];
	int sum[m];
	for(int i=0; i<m; i++){
		sum[i] = 0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			if(mat[i][j] == '1') sum[j]++;
		}
	}
	bool ok = false;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] == '1') sum[j]--;
		}
		bool nice = true;
		for(int j=0; j<m; j++) if(sum[j] == 0) nice = false;
		ok |= nice;
		for(int j=0; j<m; j++){
			if(mat[i][j] == '1') sum[j]++;
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}
	