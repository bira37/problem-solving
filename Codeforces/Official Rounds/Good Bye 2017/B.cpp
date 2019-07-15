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

char ins[] = {'U', 'D', 'L', 'R'};

vector<int> v;

char mat[100][100];

ii start;

string s;

int n,m;

bool test(){
	ii curr = start;
	for(char c : s){
		//cout << mat[curr.ff][curr.ss] << endl;
		int d = c - '0';
		if(ins[v[d]] == 'U') curr.ff--;
		else if(ins[v[d]] == 'D') curr.ff++;
		else if(ins[v[d]] == 'L') curr.ss--;
		else curr.ss++;
		if(curr.ff < 0 || curr.ff >= n || curr.ss >= m || curr.ss < 0) return false;
		if(mat[curr.ff][curr.ss] == '#') return false;
		if(mat[curr.ff][curr.ss] == 'E') return true;
	}
	if(mat[curr.ff][curr.ss] == 'E') return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 'S') start = ii(i,j);
		}
	}
	cin >> s;
	v.pb(0);
	v.pb(1);
	v.pb(2);
	v.pb(3);
	int ans = 0;
	do {
		//cout << "goin" << endl;
		//cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
		ans += test();
		//cout << ans << endl;
	} while(next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}
	