#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int t = 0;
	while(cin >> n, n){
		cout << "Teste " << ++t << endl;
		int senha[n][5][2];
		char pattern[n][6];
		int cont[6][10];
		for(int j=0; j<n; j++){
			for(int i=0; i<10; i++){
				cin >> senha[j][i/2][i%2];
			}
			for(int i=0; i<6; i++){
				cin >> pattern[j][i];
			}
		}
		for(int i=0; i<6; i++){
			for(int j=0; j<10; j++) cont[i][j] = 0;
		}
		for(int j=0; j<n; j++){
			for(int i=0; i<6; i++){
				int p0 = pattern[j][i] - 'A';
				cont[i][senha[j][p0][0]]++;
				cont[i][senha[j][p0][1]]++;
			}
		}
		for(int i=0; i<6; i++){
			if(i) cout << " ";
			int max=0, idx=0;
			for(int j=0; j<10; j++){
				if(max < cont[i][j]){
					idx = j;
					max = cont[i][j];
				}
			}
			cout << idx;
		}
		cout << endl<<endl;
	}
}
	
	
	

