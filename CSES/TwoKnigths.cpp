#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 200100
using namespace std;

int n,k;

 
int32_t main(){
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a = i * i * (i * i - 1) / 2;
		int b = 2 * (i - 2) * (2 * (i - 4) + 6);
		cout << a - b << endl;
	}
}