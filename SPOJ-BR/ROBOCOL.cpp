#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int main(){
	int n,m,k;
	while(cin >> n >> m >> k, n+m+k){
		pii ini;
		char dir;
		char mat[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> mat[i][j];
				if(mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O'){
					ini = pii(i,j);
					dir = mat[i][j];
					mat[i][j] = '.';
				}
			}
		}
		int ans = 0;
		for(int i=0; i<k; i++){
			char order;
			cin >> order;
			if(order == 'D'){
				if(dir == 'L') dir = 'S';
				else if(dir == 'S') dir = 'O';
				else if(dir == 'O') dir = 'N';
				else if(dir == 'N') dir = 'L';
			}
			else if(order == 'E'){
				if(dir == 'L') dir = 'N';
				else if(dir == 'N') dir = 'O';
				else if(dir == 'O') dir = 'S';
				else if(dir == 'S') dir = 'L';
			}
			else if(order == 'F'){
				if(dir == 'L' && ini.ss+1 < m && mat[ini.ff][ini.ss+1] != '#') ini.ss++;
				else if(dir == 'O' && ini.ss-1 >= 0 && mat[ini.ff][ini.ss-1] != '#') ini.ss--;
				else if(dir == 'N' && ini.ff-1 >= 0 && mat[ini.ff-1][ini.ss] != '#') ini.ff--;
				else if(dir == 'S' && ini.ff+1 < n && mat[ini.ff+1][ini.ss] != '#') ini.ff++;
			}
			if(mat[ini.ff][ini.ss] == '*'){
				ans++;
				mat[ini.ff][ini.ss] = '.';
			}
		}
		cout << ans << endl;
	}
}
	
		
		

