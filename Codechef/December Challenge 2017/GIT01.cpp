#include <bits/stdc++.h>
#define ii pair<int, char>
#define trio pair< int, ii >
#define x first
#define y second.first
#define c second.second
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int cred = 0;
		int cgreen = 0;
	
		bool vis1[n][m], vis2[n][m];
		char mat[n][m];
		for(int i=0; i<n; i++){
			for(int j = 0; j<m; j++){
				cin >> mat[i][j];
				vis1[i][j] = false;
				vis2[i][j] = false;
			}
		}
		
		queue<trio> q;
		q.push(trio(0, ii(0, 'G')));
		
		while(!q.empty()){
			trio u = q.front();
			q.pop();
			if(vis1[u.x][u.y]) continue;
			vis1[u.x][u.y] = true;
			if(mat[u.x][u.y] != u.c){
				if(u.c == 'R') cgreen+=3;
				else cgreen +=5;
			}
			for(int i=0; i<4; i++){
				if(u.x + dx[i] >= 0 && u.x + dx[i] < n && u.y + dy[i] >= 0 && u.y + dy[i] < m && !vis1[u.x + dx[i]][u.y + dy[i]]){
					if(u.c == 'G') q.push(trio(u.x + dx[i], ii(u.y+dy[i], 'R')));
					else q.push(trio(u.x + dx[i], ii(u.y+dy[i], 'G')));
				}
			}
		}
		
		q.push(trio(0, ii(0, 'R')));
		
		while(!q.empty()){
			trio u = q.front();
			q.pop();
			if(vis2[u.x][u.y]) continue;
			vis2[u.x][u.y] = true;
			if(mat[u.x][u.y] != u.c){
				if(u.c == 'R') cred+=3;
				else cred +=5;
			}
			for(int i=0; i<4; i++){
				if(u.x + dx[i] >= 0 && u.x + dx[i] < n && u.y + dy[i] >= 0 && u.y + dy[i] < m && !vis2[u.x + dx[i]][u.y + dy[i]]){
					if(u.c == 'G') q.push(trio(u.x + dx[i], ii(u.y+dy[i], 'R')));
					else q.push(trio(u.x + dx[i], ii(u.y+dy[i], 'G')));
				}
			}
		}
		
		cout << min(cgreen, cred) << endl;
	}
}
		
	
