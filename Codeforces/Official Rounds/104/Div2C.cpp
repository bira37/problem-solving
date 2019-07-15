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
	string a,b;
	cin >> a >> b;
	int cnta[2], cntb[2];
	for(int i=0; i<2; i++){
		cnta[i] = cntb[i] = 0;
	}
	int ans = 0;
	for(int i=0; i<a.size(); i++){
		if(a[i] == '7') cnta[1]++;
		else cnta[0]++;
		if(b[i] == '7') cntb[1]++;
		else cntb[0]++;
	}
	
	if(cnta[0] < cntb[0]){
		for(int i =0; i<a.size() && cnta[0] < cntb[0]; i++){
			if(b[i] == '4' && a[i] == '7'){
				a[i] = '4';
				ans++;
				cnta[0]++;
			}
		}
	}
	else if(cnta[1] < cntb[1]){
		for(int i =0; i<a.size() && cnta[1] < cntb[1]; i++){
			if(b[i] == '7' && a[i] == '4'){
				a[i] = '7';
				ans++;
				cnta[1]++;
			}
		}
	}
	int num_err = 0;
	for(int i=0; i<a.size(); i++){
		if(a[i] != b[i]) num_err++;
	}
	cout << ans + num_err/2 << endl;
}