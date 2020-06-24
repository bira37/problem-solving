#include <bits/stdc++.h>

using namespace std;

vector<int> z;
vector<int> zs;

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

void ZS(string st) {
	int l = 0, r = 0, n = st.size(), cor;
	for(int i = 0; i < n; i++) {
		zs.push_back(0);
	}
	
	zs[0] = 0;
	
	for(int i = 1; i < n; i++) {
		cor = i - l;
		if(i <= r) zs[i] = min(zs[cor], r-i+1);
		while(st[zs[i]] == st[i+zs[i]]) zs[i]++;
		if(i + zs[i]-1 > r) {
			r = i+zs[i]-1;
			l = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	string uau = t+s;
	Z(uau);
	reverse(t.begin(), t.end());
	uau = t + s;
	ZS(uau);
	int mc = 10000000;
	for(int i=t.size(); i<uau.size(); i++){
		if(i + z[i] == uau.size()){
			if(zs[t.size()] >= (i - (int)t.size())) mc = min(mc, (i - (int)t.size()));
		}
	}
	if(mc == 10000000){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << mc << endl;
}
		
