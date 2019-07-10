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
	long long n,k,ans;
	cin >> n >> k;
	ans = n/k;
	if(ans % 2 == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
