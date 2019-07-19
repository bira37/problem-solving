#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
int32_t main(){
	int n,m;
	cin >> n >> m;
	int s = 0;
	vector<int> v;
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		v.pb(a-b);
		s += a;
	}
	sort(v.begin(), v.end(), greater<int>());
	
	int compress = 0;
	if(s <=m){
		cout << compress << endl;
		return 0;
	}
	for(int x : v){
		s -= x;
		compress++;
		if(s <=m){
			cout << compress << endl;
			return 0;
		} 
	}
	cout << -1 << endl;
}
