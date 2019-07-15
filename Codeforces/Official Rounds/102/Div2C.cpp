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
	
	int min_ans = (int)1e18;
	int max_ans = 0;
	
	int n;
	cin >> n;
	for(int i=1; i<=sqrt(n); i++){
		if(n%i == 0){
			int a = i;
			int newn = n/i;
			for(int j=1; j<=sqrt(newn); j++){
				if(newn%j == 0){
					int b = j;
					int c = newn/j;
					//cout << a << " " << b << " " << c << endl;
					a+=1;
					b+=2;
					c+=2;
					//cout << a*b*c - n << endl;
					min_ans = min(min_ans, a*b*c - n);
					max_ans = max(max_ans, a*b*c - n);
					a-=1;
					b-=2;
					c-=2;
				}
			}
			
			a = n/i;
			newn = i;
			
			for(int j=1; j<=sqrt(newn); j++){
				if(newn%j == 0){
					int b = j;
					int c = newn/j;
					//cout << a << " " << b << " " << c << endl;
					a+=1;
					b+=2;
					c+=2;
					//cout << a*b*c - n << endl;
					min_ans = min(min_ans, a*b*c - n);
					max_ans = max(max_ans, a*b*c - n);
					a-=1;
					b-=2;
					c-=2;
				}
			}

		}
	}
	
	cout << min_ans << " " << max_ans << endl;
}
			