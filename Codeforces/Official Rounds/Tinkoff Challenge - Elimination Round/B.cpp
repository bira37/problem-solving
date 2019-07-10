#include <bits/stdc++.h>
#define N 0
#define S 1
#define L 2
#define O 3
#define A 4
 
using namespace std;
 
struct road{
	int ff,ss,turn;
	int dir;
	road(int f, int s, int d, int t){
		ff = f;
		ss = s;
		dir = d;
		turn  = t;
	}
};
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	deque< road > q;
	char mat[n][m];
	bool vis[n][m][5];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			vis[i][j][0] = false;
			vis[i][j][1] = false;
			vis[i][j][2] = false;
			vis[i][j][3] = false;
			vis[i][j][4] = false;
			if(mat[i][j] == 'S') {
				q.push_front(road(i,j,A, 0));
			}
		}
	}
 
	while(!q.empty()){
		road v = q.front();
		q.pop_front();
		if(v.turn >= 3) continue;
		if(vis[v.ff][v.ss][v.dir]) continue;
		if(mat[v.ff][v.ss] == 'T' && v.turn <= 2){
			cout << "YES" << endl;
			return 0;
		}
		vis[v.ff][v.ss][v.dir] = true;
		//cout << "visiting " << v.ff << " " << v.ss << " with turn " << v.turn << " " << v.dir << endl; 
		if(v.ff > 0 && !vis[v.ff-1][v.ss][v.dir] && mat[v.ff-1][v.ss] != '*'){
			if(v.dir == A) q.push_front(road(v.ff-1, v.ss, N, v.turn));
			else if(v.dir == L || v.dir == O) q.push_back(road(v.ff-1, v.ss, N, v.turn+1));
			else if(v.dir == N) q.push_front(road(v.ff-1, v.ss, N, v.turn));
		}
		if(v.ff < n-1 && !vis[v.ff+1][v.ss][v.dir] &&  mat[v.ff+1][v.ss] != '*'){
			if(v.dir == A) q.push_front(road(v.ff+1, v.ss, S, v.turn));
			else if(v.dir == L || v.dir == O) q.push_back(road(v.ff+1, v.ss, S, v.turn+1));
			else if(v.dir == S) q.push_front(road(v.ff+1, v.ss, S, v.turn));
		}
		if(v.ss < m-1 && !vis[v.ff][v.ss+1][v.dir] &&  mat[v.ff][v.ss+1] != '*'){
			if(v.dir == A) q.push_front(road(v.ff, v.ss+1, L, v.turn));
			else if(v.dir == N || v.dir == S) q.push_back(road(v.ff, v.ss+1, L, v.turn+1));
			else if(v.dir == L) q.push_front(road(v.ff, v.ss+1, L, v.turn));
		}
		if(v.ss > 0 && !vis[v.ff][v.ss-1][v.dir] &&  mat[v.ff][v.ss-1] != '*'){
			if(v.dir == A) q.push_front(road(v.ff, v.ss-1, O, v.turn));
			else if(v.dir == N || v.dir == S) q.push_back(road(v.ff, v.ss-1, O, v.turn+1));
			else if(v.dir == O) q.push_front(road(v.ff, v.ss-1, O, v.turn));
		}	
	}
 
	cout << "NO" << endl;
}
