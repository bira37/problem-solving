#include <bits/stdc++.h>

using namespace std;

int d,n,m;
int mat[200][200];
bool vis[200][200];

void dfs(int x, int y, int cor){
	vis[x][y] = true;
	d++;
	if(x-1 >= 0 && mat[x-1][y] == cor && vis[x-1][y] == false) dfs(x-1,y,cor);
	if(y-1 >= 0 && mat[x][y-1] == cor && vis[x][y-1] == false) dfs(x,y-1,cor);
	if(x+1 < n && mat[x+1][y] == cor && vis[x+1][y] == false) dfs(x+1,y,cor);
	if(y+1 < m && mat[x][y+1] == cor && vis[x][y+1] == false) dfs(x,y+1,cor);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i =0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			vis[i][j] == false;
		}
	}
	int res = 0x3f3f3f3f;
	for(int i =0; i<n; i++){
		for(int j=0; j<m; j++){
			d=0;
			if(vis[i][j] == false){
				dfs(i,j,mat[i][j]);
				if(d < res) res = d;
			}
		}
	}
	cout << res << endl;
}
