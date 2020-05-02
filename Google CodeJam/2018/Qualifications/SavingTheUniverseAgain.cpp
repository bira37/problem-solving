#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

string s;

int dmg(){
	int tot = 0;
	int charge = 1;
	for(int i=0; i<s.size(); i++){
		if(s[i] == 'C') charge*=2LL;
		else tot += charge;
	}
	//cout << "for " << s << " damage is " << tot << endl;
	return tot;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		int n;
		cin >> n;
		cin >> s;
		int ans = 0;
		bool impossible = false;
		while(dmg() > n){
			bool swapped = false;
			for(int i=s.size()-1; i>0; i--){
				if(s[i-1] == 'C' && s[i] == 'S'){
					swap(s[i], s[i-1]);
					swapped = true;
					break;
				}
			}
			if(!swapped){
				impossible = true;
				break;
			}
			ans++;
		}
		if(impossible) cout << "Case #" << test << ": IMPOSSIBLE" << endl;
		else cout << "Case #" << test << ": " << ans << endl;
	}
}
				
