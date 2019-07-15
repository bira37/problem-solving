#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9

using namespace std;

inline int mod(int n){ return (n%1000000007); }


int32_t main(){
	DESYNC;
	
	int a,b,q;
	cin >> a >> b >> q;
	
	//for(int i=0; i<8; i++) cout << a + b*i << " ";
	//cout << endl;
	
	while(q--){
		int lb,t,k;
		cin >> lb >> t >> k;
		int qtd = t*k;
		int l = lb;
		int r = (int)1e8;
		int ans = -1;
		while(l <= r){
			int m = (l+r)>>1;
			
			int cur = a*(m-lb+1) + b*(((m)*(m-1))/2 - ((lb-1)*(lb-2))/2);
			//cout << "m is " << m << endl;
			//cout << "cur " << cur << "//qtd " << qtd << endl;
			if(cur <= qtd && a + b*(m-1) <= t){
				ans = m;
				l = m+1;
			}
			else r = m-1;
		}
		cout << ans << endl;
	}
}
	