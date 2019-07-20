#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string s,t;
	cin >> s >> t;
	if(s.size() != t.size()){
		cout << "NO" << endl;
		return 0;
	}
	int l = 0;
	int r = s.size()-1;
	while(l < s.size() && s[l] == t[l]) l++;
	while(r > l && s[r] == t[r]) r--;
	
	reverse(s.begin()+l, s.begin()+r+1);
	
	if(s == t) cout << "YES" << endl;
	else cout << "NO" << endl;
}
