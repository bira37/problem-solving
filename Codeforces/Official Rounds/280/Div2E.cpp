#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, m, dx, dy;
	cin >> n >> m >> dx >> dy;
	int v[n], g[n];
	for(int i=0; i<n; i++){
		v[(dx*i)%n] = (dy*i)%n;
		g[i] = 0;
	}
	int best = 0;
	pair<int ,int > ans;
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		int k = (y - v[x] + n)%n;
		g[k]++;
		if(g[k] > best){
			best = g[k];
			ans = make_pair(x,y);
		}
	}
	cout << ans.first << " " << ans.second << endl;
}
	