#include <bits/stdc++.h>

using namespace std;

int z[1123456];

void precompute(string & s, int * z){
	//string s = str + pattern;
	for(int i=0; i<s.size(); i++) z[i] = 0;
	z[0] = 0;
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
	string s;
	cin >> s;
	precompute(s,z);
	for(int i=0; i<s.size(); i++){
		if(i) cout << " ";
		cout << z[i];
	}
	cout << endl;
}
