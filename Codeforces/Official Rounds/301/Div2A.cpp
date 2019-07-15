#include <bits/stdc++.h>

#define ii pair<int,int>
#define ff first
#define ss second
#define pb push_back

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	int ans = 0;
	for(int i=0; i<n; i++){
		int x = a[i] -'0';
		int y = b[i] -'0';
		int cur = abs(x-y);
		cur = min(cur, y + (9-x) + 1);
		cur = min(cur, (9-y) + x + 1);
		ans += cur;
	}
	cout << ans << endl;
}