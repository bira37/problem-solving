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

int mask(int b){
	string num;
	while(b > 0){
		num += (b%10 + '0');
		b/=10;
	}
	reverse(num.begin(), num.end());
	string ans;
	for(int i=0; i<num.size(); i++){
		if(num[i] == '4' || num[i] == '7') ans += num[i];
	}
	int ret = 0;
	for(int i=0; i<ans.size(); i++){
		ret = ret*10 + (ans[i] - '0');
	}
	return ret;
}
 
int main(){
	int a,b;
	cin >> a >> b;
	for(int i=a+1; i <= 10000000; i++){
		if(mask(i) == b){
			cout << i << endl;
			return 0;
		}
	}
}