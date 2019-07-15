#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	char mat[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	
	set<int> avr, avc;
	for(int i=0; i<n; i++) avr.insert(i);
	for(int i=0; i<m; i++) avc.insert(i);
	char paint[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			paint[i][j] = '.';
		}
	}
	
	for(int i=0; i<n; i++){
		if(!avr.count(i)) continue;
		avr.erase(i);
		for(int j=0; j<m; j++){
			if(mat[i][j] == '#'){
				if(!avc.count(j)){
					cout << "No" << endl;
					return 0;
				}
				avc.erase(j);
				for(int k=0; k<n; k++){
					if(k == i) continue;
					if(mat[k][j] == '#'){
						for(int l = 0; l <m; l++){
							if(mat[k][l] != mat[i][l]){
								cout << "No" << endl;
								return 0;
							}
						}
						if(avr.count(k)) avr.erase(k);
					}
				}
			}
		}
	}

	cout << "Yes" << endl;
}
	
			
						