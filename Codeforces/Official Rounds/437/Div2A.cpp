#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	char last = s[0];
	int cnt1 = 0, cnt2=0;
	for(int i=1; i<n; i++){
		if(s[i] == 'F' && last == 'S') cnt1++;
		else if(s[i] == 'S' && last == 'F') cnt2++;
		last = s[i];
	}
	if(cnt1>cnt2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
