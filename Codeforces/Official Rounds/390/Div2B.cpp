#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char mat[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin >> mat[i][j];
		}
	}
	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(mat[i][j] == 'x'){
				if((i+2 < 4) && ((mat[i+1][j] == 'x' && mat[i+2][j] == '.') || (mat[i+1][j] == '.' && mat[i+2][j] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((i-2 >= 0) && ((mat[i-1][j] == 'x' && mat[i-2][j] == '.') || (mat[i-1][j] == '.' && mat[i-2][j] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((j+2 < 4) && ((mat[i][j+1] == 'x' && mat[i][j+2] == '.') || (mat[i][j+1] == '.' && mat[i][j+2] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((j-2 >=0) && ((mat[i][j-1] == 'x' && mat[i][j-2] == '.') || (mat[i][j-1] == '.' && mat[i][j-2] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((j+2 < 4 && i+2 < 4) && ((mat[i+1][j+1] == 'x' && mat[i+2][j+2] == '.') || (mat[i+1][j+1] == '.' && mat[i+2][j+2] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((j-2 >=0 && i+2 < 4) && ((mat[i+1][j-1] == 'x' && mat[i+2][j-2] == '.') || (mat[i+1][j-1] == '.' && mat[i+2][j-2] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((j-2 >=0 && i-2 >= 0) && ((mat[i-1][j-1] == 'x' && mat[i-2][j-2] == '.') || (mat[i-1][j-1] == '.' && mat[i-2][j-2] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
				if((j+2 < 4 && i-2 >= 0) && ((mat[i-1][j+1] == 'x' && mat[i-2][j+2] == '.') || (mat[i-1][j+1] == '.' && mat[i-2][j+2] == 'x'))){
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "NO" << endl;
}
