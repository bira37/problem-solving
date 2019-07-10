#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define LL_MAX (1e18)
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define SYNC_IO ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>
 
using namespace std;
 
typedef long long ll;
 
struct voucher{
	int l,r;
	ll cost;
	int dur;
};
 
vector< pair<int ,long long> > duration_cost[200001];
 
int main(){
	SYNC_IO(false);
	int n,k;
	cin >> n >> k;
	voucher v[n];
	int max_dur = 0;
	for(int i=0; i<n; i++){
		cin >> v[i].l >> v[i].r >> v[i].cost;
		v[i].dur = v[i].r - v[i].l + 1;
		max_dur = max(max_dur, v[i].dur);
	}
	for(int i=0; i<n; i++){
		duration_cost[v[i].dur].push_back( pair<int, long long>(v[i].l, v[i].cost) );
	}
	ll ans = LL_MAX;
	for(int i=0; i<200001; i++){
		sort(duration_cost[i].begin(), duration_cost[i].end());
		for(int j=duration_cost[i].size() -2; j>=0; j--){
			duration_cost[i][j].second = min(duration_cost[i][j].second, duration_cost[i][j+1].second);
		}
	}
	for(int i=0; i<n; i++){
		if(k - v[i].dur < 0) continue;
		vector< pair<int, long long> >::iterator it = upper_bound(duration_cost[k-v[i].dur].begin(), duration_cost[k-v[i].dur].end(), pair<int, long long>(v[i].r, LL_MAX));
		if(it != duration_cost[k-v[i].dur].end()) ans = min(ans, v[i].cost + it->second);
	} 
	if(ans != LL_MAX) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
