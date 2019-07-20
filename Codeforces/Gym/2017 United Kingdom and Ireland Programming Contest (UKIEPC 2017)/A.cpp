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
 
struct settlement{
	int h, l, r, cur;
	bool dark;
};
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	settlement v[n];
	int max_hour = 0;
	for(int i=0; i<n; i++){
		cin >> v[i].h >> v[i].l >> v[i].r;
		max_hour = max(max_hour, v[i].h);
	}
	//initialize
	for(int i=0; i<n; i++){
		v[i].cur = 0;
		if(v[i].l < v[i].r){
			if(v[i].l < 0 && 0 < v[i].r) v[i].dark = false;
			else v[i].dark = true;
		}
		else {
			if(v[i].r <= 0 && 0 <= v[i].l) v[i].dark = true;
			else v[i].dark = false;
		}
	}
	int qtd = 0;
	for(int k=0; k<n; k++) qtd += v[k].dark;
	if(qtd == n){
		cout << 0 << endl;
		return 0;
	}
	int ans = 0; 
	for(int i=1; i<=1825; i++){
		for(int j=0; j<max_hour; j++){
			ans++;
			for(int k=0; k<n; k++){
				v[k].cur++;
				v[k].cur %= v[k].h;
				
				if(v[k].l < v[k].r){
					if(v[k].l < v[k].cur && v[k].cur < v[k].r) v[k].dark = false;
					else v[k].dark = true;
				}
				else {
					if(v[k].r <= v[k].cur && v[k].cur <= v[k].l) v[k].dark = true;
					else v[k].dark = false;
				}
			}
			
			int qtd = 0;
			for(int k=0; k<n; k++) qtd += v[k].dark;
			if(qtd == n){
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << "impossible" << endl;
}
	
	
