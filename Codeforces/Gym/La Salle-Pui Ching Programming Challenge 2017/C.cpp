#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string s;
	cin >> s;
	string a = "LSC";
	string b = "PCMS";
	int cnta = 0, cntb = 0;
	for(int i=0; i<s.size(); i++){
		int k = 0;
		for(int j=i; k<a.size() && j < s.size(); k++, j++){
			if(s[j] != a[k]) break;
		}
		if(k == a.size()) cnta++;
	}
	for(int i=0; i<s.size(); i++){
		int k = 0;
		for(int j=i; k<b.size() && j < s.size(); k++, j++){
			if(s[j] != b[k]) break;
		}
		if(k == b.size()) cntb++;
	}
	if(cnta < cntb) cout << "PCMS" << endl;
	else if(cnta > cntb) cout << "LSC" << endl;
	else cout << "Tie" << endl;
}
