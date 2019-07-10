#include <bits/stdc++.h>
#define int long long 
using namespace std;
 
int hist_b[26];
int hist_a[26];
int qmark;
 
bool check(int checker){
	int sum = 0;
	for(int i=0; i<26; i++){
		sum += max(hist_b[i]*checker - hist_a[i], 0LL);
	}
	if(sum <= qmark) return true;
	return false;
}
 
string solve(int val, string a){
	string ans = a;
	int pointer = 0;
	for(int i=0; i<ans.size(); i++){
		while(pointer < 26 && hist_b[pointer]*val <= hist_a[pointer]) pointer++;
		if(ans[i] == '?'){
			if(pointer < 26) {
				ans[i] = 'a'+pointer;
				hist_a[pointer]++;
			}
			else ans[i] = 'a';
		}
	}
	return ans;
} 
 
int32_t main(){
	string a,b;
	cin >> a >> b;
	for(int i=0; i<26; i++) hist_b[i] = 0;
	for(int i=0; i<26; i++) hist_a[i] = 0;
	qmark = 0;
	for(int i=0; i<a.size(); i++){
		if(a[i] == '?') qmark++;
	}
	for(int i=0; i<b.size(); i++) hist_b[b[i]-'a']++;
	for(int i=0; i<a.size(); i++) if(a[i] != '?') hist_a[a[i]-'a']++;
	int l = 0, r = 100000000;
	int ans = 0;
	while(l <= r){
		int m = (l+r)/2;
		if(check(m)){
			ans = m;
			l = m+1;
		}
		else r  = m-1;
	}
	cout << solve(ans, a) << endl;
}
