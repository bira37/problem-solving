#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int expo(int n, int k){
	if(k == 0) return 1;
	if(k == 1) return n;
	int a = expo(n, k/2);
	a*=a;
	if(k%2) a = a*n;
	return a;
}
 
int32_t main(){
	int n,m;
	cin >> n >> m;
	int mat[n][m];
	for(int i=0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		int cont1 = 0;
		int cont0 = 0;
		for(int j=0; j<m; j++){
			if(mat[i][j] == 0) cont0++;
			else cont1++;
		}
		if(cont0 > 1) ans += expo(2, cont0)-1-cont0;
		if(cont1 > 1) ans += expo(2, cont1)-1-cont1;
	}
	for(int j=0; j<m; j++){
		int cont1 = 0;
		int cont0 = 0;
		for(int i=0; i<n; i++){
			if(mat[i][j] == 0) cont0++;
			else cont1++;
		}
		if(cont0 > 1) ans += expo(2, cont0)-1 - cont0;
		if(cont1 > 1) ans += expo(2, cont1)-1 - cont1;
	}
	cout << ans + n*m << endl;
}
