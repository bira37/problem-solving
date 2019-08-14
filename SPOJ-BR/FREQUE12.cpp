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
	int n,ans=0;
	cin >> n;
	bool vis[1000001];
	for(int i=0; i<=1000000; i++){
		vis[i] = false;
	}
	int x;
	while(n--){cin >> x; vis[x] = true;}
	for(int i=0; i<=1000000; i++){
		if(vis[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}
