#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool v[n];
		bool flag = false, flag2 = true;
		int pz=n, pnz=n;
		int ans = 0;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			v[i] = x;
			if(v[i] == 0 && flag2){
				pz = i;
				flag = true;
				flag2 = false;
			}
			else if(v[i] != 0 && flag){
				pnz = i;
				flag = false;
			}
		}
		while(pz < n && pnz < n){
			if(v[pz] == 0 && v[pnz] != 0){
				swap(v[pz], v[pnz]);
				ans++;
			}
			else if(v[pz] == 0) pnz++;
			else pz++;
			//for(int i=0; i<n; i++) cout << v[i] << " ";
			//cout << endl;
		}
		cout << ans << endl;
	}
}
