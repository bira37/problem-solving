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
	cin >> s;
	int z[s.size()];
	precompute(s,z);
	int cont[s.size()+1];
	for(int i=0; i<=s.size(); i++) cont[i] = 0;
	cont[s.size()] = 1;
	int ans = 1;
	int dp[s.size()+1];
	for(int i=0; i<s.size()+1; i++) dp[i] = 0;
	for(int i=1; i<s.size(); i++){
		if(i+z[i] == s.size()){
			cont[z[i]] = 2;
			ans++;
		}
	}
	
	for(int i=1; i<s.size(); i++){
		int aux;
		if(i+z[i] < s.size() && cont[z[i]] > 0) cont[z[i]]++;
		dp[z[i]]++;
	}
	for(int i=s.size()-1; i>=0; i--){
		dp[i] += dp[i+1];
	}
	cout << ans << endl;
	for(int i=1; i<s.size(); i++){
		//if(cont[i] != 0 ) cout << cont[i] << endl;
		if(cont[i] != 0) cout << i << " " << cont[i]+(dp[i]-cont[i])+1 << endl;
	}
	cout << s.size() << " " << 1 << endl;
}
