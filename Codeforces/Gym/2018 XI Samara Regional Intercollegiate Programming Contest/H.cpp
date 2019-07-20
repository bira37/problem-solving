#include <bits/stdc++.h>
#define ii pair<int,int>
#define ff first
#define ss second
 
using namespace std;
 
vector< vector<char> > mat;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n,m,d;
	cin >> n >> m  >> d;
	ii s,f;
	char mat[n][m];
	bool vis[n][m];
	
	
	queue< ii > q;
	queue<int> cd;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			vis[i][j] = false;
			if(mat[i][j] == 'S') s = ii(i,j);
			else if(mat[i][j] == 'F') f = ii(i,j);
			else if(mat[i][j] == 'M'){
				vis[i][j] = true;
				q.push(ii(i,j));
				cd.push(0);
			}
		}
	}
	
	while(!q.empty()){
		ii curr = q.front();
		q.pop();
		int dist = cd.front();
		cd.pop();
		
		mat[curr.ff][curr.ss] = 'M';
		
		if(dist == d) continue;
		
		if(curr.ff-1 >= 0 && !vis[curr.ff-1][curr.ss]){
			vis[curr.ff-1][curr.ss] = true;
			q.push(ii(curr.ff-1, curr.ss));
			cd.push(dist+1);
		}
		if(curr.ff+1 < n && !vis[curr.ff+1][curr.ss]){
			vis[curr.ff+1][curr.ss] = true;
			q.push(ii(curr.ff+1, curr.ss));
			cd.push(dist+1);
		}
		if(curr.ss-1 >= 0 && !vis[curr.ff][curr.ss-1]){
			vis[curr.ff][curr.ss-1] = true;
			q.push(ii(curr.ff, curr.ss-1));
			cd.push(dist+1);
		}
		if(curr.ss+1 < m && !vis[curr.ff][curr.ss+1]){
			vis[curr.ff][curr.ss+1] = true;
			q.push(ii(curr.ff, curr.ss+1));
			cd.push(dist+1);
		}
	}
	
	if(mat[s.ff][s.ss] == 'M' || mat[f.ff][f.ss] == 'M'){
		cout << -1 << endl;
		return 0;
	}
	
	while(!q.empty()) q.pop();
	while(!cd.empty()) cd.pop();
	
	vis[s.ff][s.ss] = true;
	q.push(s);
	cd.push(0);
	
	while(!q.empty()){
		ii curr = q.front();
		q.pop();
		int dist = cd.front();
		cd.pop();
		
		if(curr == f){
			cout << dist << endl;
			return 0;
		}
		
		if(curr.ff-1 >= 0 && !vis[curr.ff-1][curr.ss]){
			vis[curr.ff-1][curr.ss] = true;
			q.push(ii(curr.ff-1, curr.ss));
			cd.push(dist+1);
		}
		if(curr.ff+1 < n && !vis[curr.ff+1][curr.ss]){
			vis[curr.ff+1][curr.ss] = true;
			q.push(ii(curr.ff+1, curr.ss));
			cd.push(dist+1);
		}
		if(curr.ss-1 >= 0 && !vis[curr.ff][curr.ss-1]){
			vis[curr.ff][curr.ss-1] = true;
			q.push(ii(curr.ff, curr.ss-1));
			cd.push(dist+1);
		}
		if(curr.ss+1 < m && !vis[curr.ff][curr.ss+1]){
			vis[curr.ff][curr.ss+1] = true;
			q.push(ii(curr.ff, curr.ss+1));
			cd.push(dist+1);
		}
	}
	
	cout << -1 << endl;
}
