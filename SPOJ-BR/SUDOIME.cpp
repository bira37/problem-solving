#include <bits/stdc++.h>

using namespace std;

bool vis[9];

bool flag;
void reset(){
	for(int i=0; i<9; i++) vis[i] = false;
}

bool check(){
	int cont = 9;
	for(int i=0; i<9; i++) if(vis[i]) cont--;
	if(cont) return false;
	return true;
}

int main(){
	int mat[9][9];
	int t;
	cin >> t;
	for(int ble=1; ble<=t; ble++){
		cout << "Instancia " << ble << endl;
		flag = true;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cin >> mat[i][j];
				mat[i][j]--;
			}
		}
	
		reset();

		for(int i=0; i<9 && flag; i++){
			reset();
			for(int j=0; j<9; j++){
				
				vis[mat[i][j]] = true;
			}
			
			if(!check()){
				cout << "NAO" << endl;
				cout << endl;
				flag = false;
			}
		}

		for(int j=0; j<9 && flag; j++){
			reset();
			for(int i=0; i<9; i++){
				
				vis[mat[i][j]] = true;
			}
			
			if(!check()){
				cout << "NAO" << endl;
				cout << endl;
				flag = false;
			}
		}

		if(!flag) continue;
		reset();
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=3; i<6; i++){
			for(int j=0; j<3; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=6; i<9; i++){
			for(int j=0; j<3; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=0; i<3; i++){
			for(int j=3; j<6; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}

		reset();
		for(int i=3; i<6; i++){
			for(int j=3; j<6; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=6; i<9; i++){
			for(int j=3; j<6; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=0; i<3; i++){
			for(int j=6; j<9; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=3; i<6; i++){
			for(int j=6; j<9; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		reset();
		for(int i=6; i<9; i++){
			for(int j=6; j<9; j++){
				vis[mat[i][j]] = true;
			}
		}
		if(!check()){
			cout << "NAO" << endl;
			cout << endl;
			flag = false;
		}
		if(!flag) continue;
		cout << "SIM" << endl;
		cout << endl;
	}
}

		


		
		



