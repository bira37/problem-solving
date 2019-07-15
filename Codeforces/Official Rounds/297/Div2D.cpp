#include <bits/stdc++.h>
#define ii pair<int,int>
#define ff first
#define ss second
#define endl '\n'

using namespace std;

int n,m;
bitset<2000> mat[2000];

int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};

int adjx[] = {0, 1, -1, 0, 1, -1, 1, -1};
int adjy[] = {1, 0, 0, -1, 1, -1, -1, 1};

bool valid(int x, int y){
	return x >= 0 && x+1 < n && y >= 0 && y+1 < m;
}

bool one(int x, int y){
	int cnt = 0;
	for(int i=0; i<4; i++){
		cnt += mat[x+dx[i]][y+dy[i]];
	}
	return cnt == 1;
}

void removeOne(int x, int y){
	for(int i=0; i<4; i++){
		mat[x+dx[i]][y+dy[i]] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char c;
			cin >> c;
			if(c == '.') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}
	
	queue< pair<int,int> > q;
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m-1; j++){
			if(one(i,j)) q.push(ii(i,j));
		}
	}
	
	while(!q.empty()){
		ii curr = q.front();
		q.pop();
		
		if(one(curr.ff, curr.ss)){
			
			removeOne(curr.ff, curr.ss);
		
			for(int i=0; i<8; i++){
				if(valid(curr.ff + adjx[i], curr.ss + adjy[i]) && one(curr.ff + adjx[i], curr.ss + adjy[i])){
					q.push(ii(curr.ff + adjx[i], curr.ss + adjy[i]));
				}
			}
			
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] == 0) cout << '.';
			else cout << '*';
		}
		cout << endl;
	}
}