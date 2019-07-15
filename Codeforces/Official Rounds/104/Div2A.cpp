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
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i<n; i++){
		if(s[i] != '4' && s[i] != '7'){
			cout << "NO" << endl;
			return 0;
		}
	}
	if(n%2){
		cout << "NO" << endl;
		return 0;
	}
	int sum1 = 0;
	for(int i = 0; i < n/2; i++){
		sum1 += s[i]-'0';
	}
	int sum2= 0;
	for(int i = n/2; i < n; i++){
		sum2+= s[i] - '0';
	}
	//cout << sum1 << " " << sum2 << endl;
	if(sum1 == sum2) cout << "YES" << endl;
	else cout << "NO" << endl;
}