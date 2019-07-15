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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int v[n];
	map<int,int> cnt,cnt2, cnt3, cnts, cnt4;
	int maxi = -10000000, mini = 10000000;
	for(int i=0; i<n; i++){
		cin >> v[i];
		cnt[v[i]]++;
		cnt2[v[i]]++;
		cnts[v[i]]++;
		maxi = max(maxi, v[i]);
		mini = min(mini, v[i]);
	}
	int ans[n];
	int ans2[n];
	if(abs(maxi - mini) == 2){
		//sol1
		int p = 0;
		while(cnt[maxi] > 0 && cnt[mini] > 0){
			ans[p++] = mini+1;
			ans[p++] = mini+1;
			cnt[maxi]--;
			cnt[mini]--;
		}
		while(cnt[maxi] > 0){
			ans[p++] = maxi;
			cnt[maxi]--;
		}
		while(cnt[mini] > 0){
			ans[p++] = mini;
			cnt[mini]--;
		}
		while(cnt[mini+1] > 0){
			ans[p++] = mini+1;
			cnt[mini+1]--;
		}
		int eq = 0;
		for(int i=0; i<n; i++) cnt3[ans[i]]++;
		for(pair<int,int> x : cnt3) eq += min(cnt2[x.first], x.second);
		
		//sol2
		int p2 = 0;
		while(cnts[mini+1] >= 2){
			ans2[p2++] = mini;
			ans2[p2++] = maxi;
			cnts[mini+1] -= 2;
		}
		while(cnts[mini] > 0){
			ans2[p2++] = mini;
			cnts[mini]--;
		}
		while(cnts[maxi] > 0){
			ans2[p2++] = maxi;
			cnts[maxi]--;
		}
		while(cnts[mini+1] > 0){
			ans2[p2++] = mini+1;
			cnts[mini+1]--;
		}
		int eq2 = 0;
		for(int i=0; i<n; i++) cnt4[ans2[i]]++;
		for(pair<int,int> x : cnt4) eq2 += min(cnt2[x.first], x.second);
		
		//get better
		if(eq < eq2){
			cout << eq << endl;
			for(int i=0; i<n; i++){
				if(i) cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
		else {
			cout << eq2 << endl;
			for(int i=0; i<n; i++){
				if(i) cout << " ";
				cout << ans2[i];
			}
			cout << endl;
		}
	}
	else {
		cout << n << endl;
		for(int i=0; i<n; i++){
			if(i) cout << " ";
			cout << v[i];
		}
		cout << endl;
	}
}