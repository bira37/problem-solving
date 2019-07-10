#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int cont0 = 0, cont1 = 0;
		char x;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin >> x;
				if (i==0 || j==0 || i==n-1 || j==m-1){
					if (x == '0') cont0++;
				}
				else{
					if (x == '1') cont1++;
				}
			}
		}
		if (cont0 > cont1) cout << -1 << endl;
		else cout << cont0 << endl;
	}
}
