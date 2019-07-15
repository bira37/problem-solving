#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long
using namespace std;

inline int mod(int n){ return (n%1000000007); } 


int32_t main(){
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	vector<int> sum;
	double print = 0.0;
	cout << fixed << setprecision(12);
	while(q--){
		int op;
		cin >> op;
		if(op == 2) cout << print << endl;
		else {
			int x;
			cin >> x;
			if(sum.size() > 0) sum.pb(sum.back()+x);
			else sum.pb(x);
			int l = 0, r = (int)sum.size()-2;
			int ans = -1;
			while(l <= r){
				int m = (l+r)>>1;
				double a1 = (double)x - (double)(sum[m] + x)/(double)(m+2);
				double a2 = (double)x - (double)(sum[m+1] + x)/(double)(m+3);
				if(a1 > a2){
					ans = m;
					r = m-1;
				}
				else l = m+1;
			}
			if(ans != -1) print = (double)x - (double)(sum[ans] + x)/(double)(ans+2);
			if(print < (double)x - (double)sum.back()/(double)sum.size()) print = (double)x - (double)sum.back()/(double)sum.size();
		}
	}
}