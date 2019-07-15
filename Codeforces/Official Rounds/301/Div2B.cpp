#include <bits/stdc++.h>

#define ii pair<int,int>
#define ff first
#define ss second
#define pb push_back

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	n -= k;
	
	if(p < y){
		cout << -1 << endl;
		return 0;
	}
	
	int sum = 0;
	int v[k];
	for(int i=0; i<k; i++){
		int l;
		cin >> l;
		v[i] = l;
		sum += l;
	}
	
	x -= sum;
	
	if(x < 0){
		cout << -1 << endl;
		return 0;
	}
	
	
	if(x < n){
		cout << -1 << endl;
		return 0;
	}
	
	x -= n;
		
	pair<int, bool> ans[n+k];
	for(int i=0; i<n; i++){
		ans[i] = make_pair(1, true);
	}
	
	for(int i = n; i<n+k; i++){
		ans[i] = make_pair(v[i-n], false);
	}
	
	
	n+=k;
	
	sort(ans, ans+n);
	if(ans[n/2].ss && ans[n/2].ff < y) while(x > 0 && ans[n/2].ff < y) ans[n/2].ff++, x--;
	for(int i=0; i<n; i++){
		if(ans[i].ss){
			while(x > 0 && ans[i].ff < y) ans[i].ff++, x--;
		}
	} 
	
	sort(ans, ans+n);
	//cout << ans[n/2].ff << endl;
	if(ans[n/2].ff < y){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i=0; i<n; i++){
		if(ans[i].ss) cout << ans[i].ff << " ";
	}
	cout << endl;
}