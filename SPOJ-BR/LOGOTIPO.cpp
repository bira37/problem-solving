#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,j,x,y,mat,k,m,n,logo,l,w,flag,teste=0;
	while(cin >> x >> y, x+y){
		int logotipo[x][y];
		logo=0;
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				cin >> logotipo[i][j];
			}
		}
		cin >> mat >> m >> n;
		for(k=0;k<mat;k++){
			int prop[m][n];
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					cin >> prop[i][j];
				}
			}
			for(i=0;i+x<=m;i++){
				for(j=0;j+y<=n;j++){
					flag = 1;
					for (w = 0; w < x && flag != 0; w++)
						for (l = 0; l < y; l++)
							if (logotipo[w][l] != prop[i+w][j+l]) {
								flag = 0;
								break;
							}
					if(flag==1) logo++;
				}
			}
		}
		teste++;
		cout << "Logotipo " << teste << endl;
		cout << logo << endl << endl;
	}
}

