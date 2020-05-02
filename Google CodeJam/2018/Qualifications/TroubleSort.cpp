#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

string s;

vector<int> even, odd, v, v2;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		cout << "Case #" << test << ": ";
		
		int n;
		cin >> n;
		even.clear(); odd.clear(); v.clear(); v2.clear();
		even.resize((n+1)/2);
		odd.resize(n/2);
		v.resize(n);
		v2.resize(n);
		for(int i=0; i<n; i++){
			if(i%2 == 0){	
				cin >> even[i/2];
				v[i] = even[i/2];
			}
			else {
				cin >> odd[i/2];
				v[i] = odd[i/2];
			}
			
		}
		
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		sort(v.begin(), v.end());
		bool par = true;
		int p1 = 0, p2 = 0;
		for(int i=0; i<n; i++){
			if(par) v2[i] = even[p1++];
			else v2[i] = odd[p2++];
			par = !par;
		}
		int error = 1123456;
		for(int i=0; i<n; i++) if(v[i] != v2[i]) error = min(error, i);
		if(error == 1123456) cout << "OK" << endl;
		else cout << error << endl;
	}
}
