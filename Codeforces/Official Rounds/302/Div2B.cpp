#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n, k;
	cin >> n >> k;
	
	char mp[n][n];
	
	
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n; j++) {
			mp[i][j] = 'S';
		}
	}
	
	int ans = 0;
	for(int i = 0 ; i < n; i++) {
		if(ans == k) break;
		for(int j = i%2; j < n; j+=2) {
			mp[i][j] = 'L';
			ans++;
			if(ans == k) break;
		}
	}
	
	
	if(ans == k) {
		cout << "YES"<<endl;
		for(int i = 0 ; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << mp[i][j];
			}
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}
 	
}
