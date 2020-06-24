#include <bits/stdc++.h>

using namespace std;



int pre[(int)1e6+10];

string s;

void prefix(int n) {
	pre[0] = 0;
	for(int i = 1; i < n; i++) {
		pre[i] = pre[i-1];
		while(pre[i] > 0 && s[i] != s[pre[i]]) pre[i] = pre[pre[i]-1];
		if(s[i] == s[pre[i]]) pre[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	int n = s.size();
	prefix(n);
	
	for(int i = 0; i < n; i++) {
		cout << pre[i] << " ";
	}
	cout << endl;
}
