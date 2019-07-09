#include <bits/stdc++.h>
 
using namespace std;
 
bool vis[500][500];
 
int main(){
	int n,m;
	cin >> n >> m;
	int mat[n][m];
	pair<int, int> start;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char c;
			cin >> c;
			if(c== 'X'){
				start.first = i;
				start.second = j;
				mat[i][j] = 1;
			}
			else mat[i][j] = 0;
			vis[i][j] = false;
		}
	}
	int altura = 0, largura = 0;
	int vertical,horizontal;
	int posx = start.first;
	int posy = start.second;
	//cout << posx << " " << posy << endl;
	while(posx >= 0 && mat[posx][start.second]){
		posx--;
		altura++;
	}
	while(posy >=0 && mat[start.first][posy]){
		posy--;
		largura++;
	}
	int flag = 1;
	//cout <<"largura " << largura << endl;
	for(int i=0; i<n; i++){
		int aux = 0;
		for(int j=0; j<m; j++){
			if(mat[i][j]) aux++;
		}
		//cout << aux << endl;
		if(aux == 0) continue;
		if(aux != largura) flag = 0;
	}
	//cout << "altura " << altura << endl;
	for(int j=0; j<m; j++){
		int aux = 0;
		for(int i=0; i<n; i++){
			if(mat[i][j]) aux++;
		}
		//cout << aux << endl;
		if(aux == 0) continue;
		if(aux != altura) flag = 0;
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
	
