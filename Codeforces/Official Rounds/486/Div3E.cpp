#include <bits/stdc++.h>
 
using namespace std;
 
string st;
int n;
 
int solve(char s1, int p) {
	int ans = -1;
	for(int i = p; i >= 0; i--) {
		if(st[i] == s1) {
			for(int j = i; j < p; j++) {
				swap(st[j], st[j+1]);
			}
			ans = p-i;
			break;
		}
	}
	
	return ans;
}
 
int fix() {
	int ans = -1;
	if(st[0]!='0') return 0;
	for(int i = 0; i < n-2; i++) {
		if(st[i]!='0') {
			for(int j = i; j >= 1; j--) {
				swap(st[j], st[j-1]);
			}
			ans = i;
			break;
		}
	}
	return ans;
}
 
int main(){
	string ss;
	cin >> ss;
	n = ss.size();
	if(ss == "0" || ss == "50" || ss == "75" || ss == "25"){
		cout << 0 << endl;
		return 0;
	}
	char s1[] = {'0','5','0','5'};
	char s2[] = {'0','2','5','7'};
	
	int ans = -1;
	string sans;
	for(int i = 0; i < 4; i++) {
		st = ss;
		int r1 = solve(s1[i], n-1);
		int r2 = solve(s2[i], n-2);
		int r3 = fix();
		if(r1 == -1 || r2 == -1 || r3 == -1) continue;
		if(ans == -1) ans = r1+r2+r3;
		if(r1+r2+r3 <= ans) {
			sans = st;
			ans = r1+r2+r3;
		}
	}
	
	//cout << sans << endl;
	
	cout << ans << endl;
}
