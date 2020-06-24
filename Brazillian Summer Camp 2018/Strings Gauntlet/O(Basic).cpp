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
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	s+=t;
	Z(s);
	int ans = 0;
	for(int i=t.size(); i<2*t.size(); i++){
		if(i + z[i] == s.size()) ans = max(z[i], ans);
	}
	cout << t.size() - ans << endl;
}
		
