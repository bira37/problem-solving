#include <bits/stdc++.h>

using namespace std;

/*int pre[(int)1e6+10];

string s;

void prefix(int n) {
	pre[0] = 0;
	for(int i = 1; i < n; i++) {
		pre[i] = pre[i-1];
		while(pre[i] > 0 && s[i] != s[pre[i]]) pre[i] = pre[pre[i]-1];
		if(s[i] == s[pre[i]]) pre[i]++;
	}
}*/


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
	string s;
	while(cin >> s){
		Z(s);
		z.clear();
		int ans = s.size();
		for(int i=0; i<s.size(); i++){
			if(i + z[i] == s.size()) ans = min(ans, i);
		}
		for(int i=0; i<ans; i++) cout << s[i];
		cout << endl;
	}
	
}

