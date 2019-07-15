#include <bits/stdc++.h>

#define ii pair<int,int>
#define ff first
#define ss second
#define pb push_back

using namespace std;

int dx[] = {1,0,-1, 0};
int dy[] = {0, 1, 0, -1};
int n,m;
ii s, f;
char mat[505][505];

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && (mat[x][y] == '.' || (x == f.ff && y == f.ss));
}

bool vis[500][500] = {0};

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	
	queue< ii > q;

	
	cin >> n >> m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	
	cin >> s.ff >> s.ss;
	cin >> f.ff >> f.ss;
	s.ff--, s.ss--, f.ff--, f.ss--;
	
	if(s == f){
		int cnt = 0;
		for(int k=0; k<4; k++){
			if(valid(f.ff + dx[k], f.ss + dy[k]) && mat[f.ff+dx[k]][f.ss+dy[k]] == '.') cnt++;
		}
		if(cnt > 0) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	
	for(int i=0; i<4; i++){
		if(valid(s.ff + dx[i], s.ss + dy[i]) && !vis[s.ff+dx[i]][s.ss+dy[i]]){
			q.push(ii(s.ff+dx[i], s.ss+dy[i]));
		}
	}
	
	for(int i=0; i<4; i++){
		if(valid(s.ff + dx[i], s.ss + dy[i])){
			if(s.ff + dx[i] == f.ff && s.ss + dy[i] == f.ss){
				if(mat[f.ff][f.ss] == 'X'){
					cout << "YES" << endl;
					return 0;
				}
				else {
					int cnt = 0;
					for(int k=0; k<4; k++){
						if(valid(f.ff + dx[k], f.ss + dy[k]) && mat[f.ff+dx[k]][f.ss+dy[k]] == '.') cnt++;
					}
					if(cnt >= 1){
						cout << "YES" << endl;
						return 0;
					}
					else {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
	}
	
	while(!q.empty()){
		ii cur = q.front();
		q.pop();
		if(vis[cur.ff][cur.ss]) continue;
		vis[cur.ff][cur.ss] = true;
		for(int i=0; i<4; i++){
			if(valid(cur.ff + dx[i], cur.ss + dy[i]) && !vis[cur.ff+dx[i]][cur.ss+dy[i]]){
				q.push(ii(cur.ff+dx[i], cur.ss+dy[i]));
			}
		}
	}
	//cout << "eu cai aq" << endl;
	if(!vis[f.ff][f.ss]){
		cout << "NO" << endl;
		return 0;
	}
	//cout << "ou n" << endl;
	int cnt = 0;
	for(int k=0; k<4; k++){
		//cout << f.ff + dx[k] << " " << f.ss + dy[k] << " " << valid(f.ff + dx[k], f.ss + dy[k]) <<  endl;
		if(valid(f.ff + dx[k], f.ss + dy[k]) && mat[f.ff+dx[k]][f.ss+dy[k]] == '.'){
			//cout << mat[f.ff+dx[k]][f.ss+dy[k]] << endl;
			cnt++;
		}
	}
	//cout << cnt << endl;
	if(mat[f.ff][f.ss] == 'X' && cnt >= 1){
		cout << "YES" << endl;
		return 0;
	}
	
	if(mat[f.ff][f.ss] == '.' && cnt >= 2){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
}