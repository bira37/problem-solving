#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
int32_t main(){
	int n,m;
	cin >> n >> m;
	int v[m+1];
	for(int i=0; i<=m; i++) v[i] = 0;
	for(int i=0; i<n; i++){
		int l,r;
		cin >> l >> r;
		for(int j=l; j<=r; j++) v[j]++;
	}
	vector<int> ans;
	for(int i=1; i<=m; i++) if(v[i] == 0) ans.pb(i);
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
}
