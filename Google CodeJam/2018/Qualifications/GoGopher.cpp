#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

bool mat[70][3];

bool check_adj(int x, int y){
	x--, y--;
	int bleh = 0;
	bleh += mat[x][y];
	bleh += mat[x-1][y];
	bleh += mat[x][y-1];
	bleh += mat[x-1][y-1];
	bleh += mat[x+1][y];
	bleh += mat[x][y+1];
	bleh += mat[x+1][y+1];
	bleh += mat[x-1][y+1];
	bleh += mat[x+1][y-1];
	return (bleh != 9);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int A;
		cin >> A;
		if(A == 20){
			//do a 7x3 mat
			for(int i=0; i<7; i++){
				for(int j=0; j<3; j++){
					mat[i][j] = false;
				}
			}
			cout << "2 2" << endl;
			cout.flush();
			int x,y;
			cin >> x >> y;
			mat[x-1][y-1] = true; 
			int it = 1;
			while(it < 1000){
				for(int i=2; i<=6; i++){
					if(check_adj(i,2)){
						cout << i << " 2" << endl;
						cout.flush();
						cin >> x >> y;
						if(x == 0 && y == 0) break;
						if(x == -1 && y == -1) break; 
						mat[x-1][y-1] = true;
					}
				}
				if(x == 0 && y == 0) break;
				if(x == -1 && y == -1) break;
			}
		}
		else {
			//do a 70x3 mat
			for(int i=0; i<70; i++){
				for(int j=0; j<3; j++){
					mat[i][j] = false;
				}
			}
			cout << "2 2" << endl;
			cout.flush();
			int x,y;
			cin >> x >> y;
			mat[x-1][y-1] = true; 
			int it = 1;
			while(it < 1000){
				for(int i=2; i<=69; i++){
					if(check_adj(i,2)){
						cout << i << " 2" << endl;
						cout.flush();
						cin >> x >> y;
						if(x == 0 && y == 0) break;
						if(x == -1 && y == -1) break; 
						mat[x-1][y-1] = true;
					}
				}
				if(x == 0 && y == 0) break;
				if(x == -1 && y == -1) break;
			}
		}
	}
}
