#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	int start = 0;
	for(int i=0; i<t.size()-s.size()+1; i++){
		int match = 0;
		for(int j=0; j<s.size(); j++){
			if(s[j] == t[i+j]) match++;
		}
		if(match > ans){
			ans = match;
			start = i;
		}
	}
	bool flag = true;
	cout << s.size() - ans << endl;
	for(int i = start, j=0; j<s.size(); i++, j++){
		if(s[j] != t[i]){
			if(!flag) cout << " " << j+1;
			else {
				flag = false;
				cout << j+1;
			}
		}
	}
	cout << endl;
}
