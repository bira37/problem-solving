#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
string s;
void solve(int i, char last){
	if(ans >= 2) return;
	if(i == n){
		ans++;
		return;
	}
	if(i == 0 && s[i] == '?'){
		solve(i+1, 'C');
		solve(i+1, 'M');
		solve(i+1, 'Y');
		return;
	}
	if(s[i] != '?'){
		if(s[i] != last) solve(i+1, s[i]);
		return;
	}
	if(last == 'C'){
		solve(i+1, 'M');
		solve(i+1, 'Y');
		return;
	}
	if(last == 'M'){
		solve(i+1, 'C');
		solve(i+1, 'Y');
		return;
	}
	if(last == 'Y'){
		solve(i+1, 'C');
		solve(i+1, 'M');
		return;
	}
}
		

int main(){
	cin >> n;
	cin >> s;
	for(int i=0; i<n-1; i++) if(s[i] == s[i+1] && s[i] != '?'){
		cout << "No" << endl;
		return 0;
	}
	solve(0, 'K');
	if(ans >= 2) cout << "Yes" << endl;
	else cout << "No" << endl;
}