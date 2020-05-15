#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	int mat[9][9];
	while(t--){
		//clean mat
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				mat[i][j] = 0;
			}
		}

		//read mat
		for(int i=0; i<9; i+=2){
			for(int j=0; j<=i; j+=2) cin >> mat[i][j];
		}
		
		//complete first line
		for(int i=1; i<9; i+=2){
			mat[8][i] = (mat[6][i-1] - mat[8][i-1] - mat[8][i+1])/2;
		}
		
		//complete all lines
		for(int i=7; i>=0; i--){
			for(int j=0; j<=i; j++){
				 mat[i][j] = mat[i+1][j] + mat[i+1][j+1];
			}
		}
		
		for(int i=0; i<9; i++){
			for(int j=0; j<=i; j++){
				if(j) cout << " ";
				cout << mat[i][j];
			}
			cout << endl;
		} 
	}
}
