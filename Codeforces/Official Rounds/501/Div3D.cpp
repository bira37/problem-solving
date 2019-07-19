#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
int32_t main(){
	int n,k,s;
	int k2;
	cin >> n >> k >> s;
	k2 = k;
	if(s < k){
		cout << "NO" << endl;
		return 0;
	}
	vector<int> ans;
	int pos = 1;
	bool flag_do_poder = false;
	while(k--){
		if(flag_do_poder){
			s--;
			if(pos + 1 <= n){
				ans.pb(pos+1);
				pos++;
			}
			else {
				ans.pb(pos-1);
				pos--;
			}
			continue;
		}
		if(pos == 1){
			if(s - abs(pos-n) >= k){
				ans.pb(n);
				s -= abs(pos-n);
				pos = n;
			}
			else {
				int anda = s - k;
				ans.pb(pos + anda);
				s -= anda;
				pos = pos+anda;
				flag_do_poder = true;
			}
		}
		else if(pos == n){
			if(s - abs(pos-1) >= k){
				ans.pb(1);
				s -= abs(pos-1);
				pos = 1;
			}
			else {
				int anda = s - k;
				ans.pb(pos - anda);
				s -= anda;
				pos = pos-anda;
				flag_do_poder = true;
			}
		}
	}
	if(s == 0 && ans.size() == k2){
		cout << "YES" << endl;
		for(int x : ans) cout << x << " ";
		cout << endl;
		return 0;
	}
	cout << "NO" << endl;
			
}
