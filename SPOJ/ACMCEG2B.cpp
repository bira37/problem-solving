#include <bits/stdc++.h>

#define ff first
#define ss second
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define IOS_SYNC ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>
#define vpll vector< pll >
#define vpii vector< pii >

using namespace std;

typedef long long ll;

////////////////////////CODE//////////////////////////////////////////////////////


int main(){
	IOS_SYNC(false);
	map< pii, string> m;
	int n;
	cin >> n;
	for(int w=0; w<n; w++){
		int i,j;
		string s;
		cin >> i >> j >> s;
		m[pii(i,j)] = s;
	}
	int q;
	cin >> q;
	while(q--){
		int i,j;
		cin >> i >> j;
		cout << m[pii(i,j)] << endl;
	}
	return 0;
}
