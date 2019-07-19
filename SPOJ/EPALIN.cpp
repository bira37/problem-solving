#include <bits/stdc++.h>

using namespace std;

void precompute(string & s, int * z){
	//string s = str + pattern;
	for(int i=0; i<s.size(); i++) z[i] = 0;
	z[0] = s.size();
	for(int i=1, l = 0, r = 0; i<s.size(); i++){
		if(i <= r) z[i] = min(z[i-l], r-i+1);
		while(s[z[i]] == s[i+z[i]]) z[i]++;
		if(i+z[i] -1 > r){
			r = i+z[i]-1;
			l = i;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	while(cin >> s){
		string rs = s;
		reverse(rs.begin(), rs.end());
		string conc = rs+s;
		int z[conc.size()];
		precompute(conc, z);
		int ans = 0;
		for(int i=1; i<conc.size(); i++){
			if(i+z[i] == conc.size()) ans = max(z[i],ans);
		}
		if(s == rs) cout << s << endl;
		else {
			string res = s.substr(0, s.size()-ans);
			string res2 = rs.substr(0, ans);
			string res3 = res;
			reverse(res3.begin(), res3.end());
			cout << res + res2 + res3 << endl;
		}
	}
}
