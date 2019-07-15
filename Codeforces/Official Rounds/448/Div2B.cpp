#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ii pair<int,int>
#define pb push_back
#define N
#define int long long
using namespace std;

int32_t main(){
	//ios_base::sync_with_stdio(false);
	int n, x, k;
	cin >> n >> x >> k;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int ans = 0;
	for(int i=0; i<n; i++){
		int val = a[i]/x;
		if(val < k) continue;
		//cout << "for " << a[i] << endl;
		val = val - k;
		
		int right_bound = upper_bound(a, a+n, a[i]) - a;
		right_bound--;
		int l = 0, r = right_bound;
		int lb = -1, rb = -1;
		while(l <= r){
			int m = (l+r)>>1;
			if((a[m]-1)/x == val){
				lb = m;
				r = m-1;
			}
			else if((a[m]-1)/x < val) l = m+1;
			else r = m-1;
		}
		l = 0, r = right_bound;
		while(l <= r){
			int m = (l+r)>>1;
			if((a[m]-1)/x == val){
				rb = m;
				l = m+1;
			}
			else if((a[m]-1)/x > val) r = m -1;
			else l = m+1;
		}
		//cout << lb << " " << rb << endl;
		if(rb != -1 && lb != -1) ans += (rb-lb+1);
	}
	
	cout << ans << endl;
}
		