#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n, n != 0){
		int ans = 0;
		int v[n];
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		sort(v,v+n);
		for(int i=0; i<n-2; i++){
			for(int j=i+1; j<n-1; j++){
				int pos = upper_bound(v,v+n, v[i]+v[j]) - v;
				ans += (n-pos);
			}
		}
		cout << ans << endl;
	}
}
			
