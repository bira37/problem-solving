#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int count[n];
	string verse[n];
	for(int i=0; i<n ; i++) cin >> count[i];
	cin.ignore();
	for(int i=0; i<n; i++) getline(cin, verse[i]);
	for(int i=0; i<n; i++){
		int ans = 0;
		for(const char c : verse[i]){
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') ans++;
		}
		//cout << ans << endl;
		if(ans != count[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
 
 
	cout << "YES" << endl;
}
