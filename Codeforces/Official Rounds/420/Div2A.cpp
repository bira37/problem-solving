#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int mat[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			cin >> mat[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			if(mat[i][j] == 1) continue;
			int val = mat[i][j];
			bool flag = false;
			for(int k1 = 0; k1 < n && !flag; k1++){
				for(int k2=0; k2 < n && !flag; k2++){
					if(mat[k1][j] + mat[i][k2] == val) flag = true;
				}
			}
			if(!flag){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
