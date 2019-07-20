#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int v[n+1];
		int p[n+1];
		p[0] = 0;
		for(int i=1; i<=n; i++){
			cin >> v[i];
			p[i] = v[i] + p[i-1];
		}
		int sum = p[n];
		for(int k=1; k<=n; k++){
			if(sum%k){
				cout << 0;
				continue;
			}
			int part = sum/k;
			int curr = 0;
			bool ok = true;
			int cnt = 0;
			while(curr < n){
				int l = curr, r = n;
				int ans = -1;
				while(l <= r){
					int m = (l+r)>>1;
					if(p[m] - p[curr] == part){
						ans = m;
						break;
					}
					else if(p[m] - p[curr] > part){
						r = m -1;
					}
					else l = m+1;
				}
				if(ans != -1){
					curr = ans;
					cnt++;
				}
				else break;
			}
			ok &= (cnt == k);
			cout << ok;
		}
		cout << endl;
	}
} 
