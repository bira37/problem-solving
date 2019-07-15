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
	int cnt4, cnt7, cnt47, cnt74;
	cin >> cnt4 >> cnt7 >> cnt47 >> cnt74;
	
	int c4 = 0;
	int c7 = 0;
	if(abs(cnt47 - cnt74) > 1){
		cout << -1 << endl;
		return 0;
	}
	string s;
	if(cnt47 > cnt74){
		for(int i=0; i<cnt47; i++){
			s += '4';
			s += '7';
		}
	}
	else if(cnt74 > cnt47){
		for(int i=0; i<cnt74; i++){
			s += '7';
			s += '4';
		}
	}
	else if(cnt74 == cnt47){
		if(cnt4 >= cnt74+1){
			for(int i=0; i<cnt74; i++){
				s += '4';
				s += '7';
			}
			s += '4';
		}
		else {
			for(int i=0; i<cnt74; i++){
				s += '7';
				s += '4';
			}
			s += '7';
		}
	}
	int first=9999999,last;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '4') first = min(first, i);
		if(s[i] == '4') c4++;
		else c7++;
	}
	for(int i=s.size()-1; i>=0; i--){
		if(s[i] == '7'){
			last = i;
			break;
		}
	}
	if(c4 > cnt4 || c7 > cnt7){
		cout << -1 << endl;
		return 0;
	}
	cnt7-=c7;
	cnt4-=c4;
	for(int i=0; i<s.size(); i++){
		if(i == last) while(cnt7 > 0){
			cout << '7';
			cnt7--;
		}
		cout << s[i];
		if(i == first) while(cnt4 > 0){
			cout << '4';
			cnt4--;
		}
	}
	cout << endl;
}