#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	int q;
	cin >> q;
	int flip[s.size()];
	for(int i=0; i < s.size(); i++){
		flip[i] = 0;
	}
	while(q--){
		int x;
		cin >> x;
		//cout << x-1 << " " << (n-x+1)-1 << endl;
		flip[(x-1)]++;
		flip[(n-x+1)]--;
	}
	for(int i=1; i<n; i++){
		flip[i] += flip[i-1];
	}
	for(int i=0; i<n; i++){
		flip[i] %= 2;
		//cout << "i = " << flip[i] << endl;
	}
	for(int i=0; i<n; i++){
		if(flip[i] == 1){
			int pos = (n-i+1)-2;
			swap(s[i], s[pos]);
			flip[pos] = 0;
		}
	}
	cout << s << endl;
}