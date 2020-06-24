#include <bits/stdc++.h>
#define int long long
using namespace std;

int r = 1;

vector<int> z;
vector<int> st;

void Z() {
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

int32_t main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	st.push_back(r++);
	int x;
	cin >> x;
	for(int i=1; i<n; i++){
		cin >> x;
		if(x == 0){
			st.push_back(r++);
		}
		else st.push_back(st[x-1]);
	}
	Z();
	for(int i=0; i<n; i++){
		if(i) cout << " ";
		cout << z[i];
	}
	cout << endl;
}
		
