#include <bits/stdc++.h>

using namespace std;

vector<int> z;

void Z(string st) {
	int l = 0, r = 0, n = st.size(), cor;
	for(int i = 0; i < n; i++) {
		z.push_back(0);
	}
	
	z[0] = 0;
	
	for(int i = 1; i < n; i++) {
		cor = i - l;
		if(i <= r) z[i] = min(z[cor], r-i+1);
		while(st[z[i]] == st[i+z[i]]) z[i]++;
		if(i + z[i]-1 > r) {
			r = i+z[i]-1;
			l = i;
		}
	}
}

int main() {
	string st;
	cin >> st;
	string revst = st;
	reverse(revst.begin(), revst.end());
	int n = st.size();
	st += revst;
	Z(st);
	
	int ans = 0;
	
	for(int i=n; i<2*n; i++){
		ans = max(ans, z[i]);
	}	
	
	cout << ans << endl;
}
