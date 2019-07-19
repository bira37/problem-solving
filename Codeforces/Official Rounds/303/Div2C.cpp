#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct tree{
	int x,h;
};
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	tree v[n];
	for(int i=0; i<n; i++) cin >> v[i].x >> v[i].h;
	int ans = 1;
	int last = v[0].x;
	for(int i=1; i<n; i++){
		if(v[i].x - v[i].h > last){
			ans++;
			last = v[i].x;
		}
		else if(i+1 == n || v[i].x + v[i].h < v[i+1].x){
			ans++;
			last = v[i].x + v[i].h;
		}
		last = max(last, v[i].x);
	}
	cout << ans << endl;
}
