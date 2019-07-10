#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int,int>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	
	int n,k;
	cin >> n >> k;
	int acc = 0;
	int ans = 0;
	int give = 0;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		acc+=x;
		give += min(acc, 8);
		acc -= min(acc, 8);
		if(give < k) ans++;
	}
	if(give >= k) cout << ans+1 << endl;
	else cout << -1 << endl;
}
