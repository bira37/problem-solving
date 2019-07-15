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
	int n;
	cin >> n;
	int p[n+1];
	int v[n+1];
	int s[n+1];
	p[0] = 0;
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		s[i] = x;
		p[i] = x + p[i-1];
	}
	int pr[n+1];
	int to_add[n+1];
	to_add[0] = 0;
	for(int i=1; i<=n; i++){
		pr[i] = 0;
		to_add[i] = 0;
	}
	for(int i=1; i<=n; i++){
		int l = i, r = n;
		int ans = n+1;
		while(l <= r){
			int m = (l+r)/2;
			if(p[m] - p[i-1] >= v[i]){
				ans = m;
				r = m-1;
			}
			else l = m+1;
		}
		//cout << "for " << i << " ans is " << ans << endl;
		to_add[i]++;
		if(ans <= n) to_add[ans]--;
		if(ans <= n){
			int tira = v[i] - (p[ans-1] - p[i-1]);
			pr[ans]+=tira;
		}
	}
	for(int i=1; i<=n; i++){
		to_add[i]+=to_add[i-1];
		pr[i] += to_add[i]*s[i];
	}
	for(int i=1; i<=n; i++){
		cout << pr[i] << " ";
	}
	cout << endl;
}