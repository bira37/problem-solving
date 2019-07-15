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
	int n,m;
	cin >> n >> m;
	char mat[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			if(mat[i][j] == '.') mat[i][j] = 'D'; 
		}
	}
	bool ok = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] == 'W'){
				if(i -1 >= 0 && mat[i-1][j] == 'S') ok = false;
				if(i +1 < n && mat[i+1][j] == 'S') ok = false;
				if(j -1 >= 0 && mat[i][j-1] == 'S') ok = false;
				if(j+1 < m && mat[i][j+1] == 'S') ok = false;
			}
		}
	}
	if(ok ){
		cout << "Yes" << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
	else cout << "No" << endl;
}