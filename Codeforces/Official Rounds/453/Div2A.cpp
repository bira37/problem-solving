#include <bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
#define M 1000000007
#define pb push_back
#define endl '\n'
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n,k;
	cin >> n >> k;
	int l = 0, r = 0;
	for(int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		if(l <= x && x <= r) r = max(r,y);
	}
	if(r >= k) cout << "YES" << endl;
	else cout << "NO" << endl; 
}