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
	
	string s;
	cin>> s;
	string dec, frac;
	
	bool pt = false;
	int cnt = 0;
	bool minus = false;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '-'){
			minus = true;
			continue;
		}
		if(s[i] == '.'){
			pt = true;
			continue;
		}
		if(pt){
			if(frac.size() < 2) frac += s[i];
		}
		else {
			dec += s[i];
		}
	}
	string newdec;
	for(int i=dec.size()-1; i>=0;i--){
		newdec += dec[i];
		cnt++;
		if(cnt == 3 && i != 0){
			cnt = 0;
			newdec+= ',';
		}
	}
	reverse(newdec.begin(), newdec.end());
	dec = newdec;
	while(frac.size() < 2) frac += '0';
	if(minus){
		cout << "($" << dec << "." <<  frac << ")" << endl;
	}
	else cout << "$" << dec << "." << frac << endl;
}
	
	