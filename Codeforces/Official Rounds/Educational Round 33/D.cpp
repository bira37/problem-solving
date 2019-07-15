#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, l;
	cin >> n >> l;
	int v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	int curr = 0;
	for(int i=0; i<n; i++){
		if(v[i] == 0){
			curr = max(curr, 0);
		}
		else curr += v[i];
		if(curr > l){
			cout << -1 << endl;
			return 0;
		}
	}
	int ans = 0;
	curr = 0;
	for(int i=0; i<n; i++){
		if(v[i] == 0){
			if(curr < 0){
				curr = l;
				ans++;
			}
		}
		else curr += v[i];
		curr = min(curr, l);
	}
	cout << ans << endl;
}