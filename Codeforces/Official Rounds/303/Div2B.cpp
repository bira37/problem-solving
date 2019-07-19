#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string s,t;
	cin >> s >> t;
	int n = s.size();
	int diff = 0;
	for(int i=0; i<n; i++){
		diff += (s[i] != t[i]);
	}
	if(diff%2){
		cout << "impossible" << endl;
		return 0;
	}
	diff -= diff/2;
	int cnt = 0;
	string k;
	for(int i=0; i<n; i++){
		if(s[i] != t[i] && cnt < diff){
			k += t[i];
			cnt++;
		}
		else k += s[i];
	}
	cout << k << endl;
}
