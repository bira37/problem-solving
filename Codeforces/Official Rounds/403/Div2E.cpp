#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[212345];
vector<int> path;
bool vis[212345];
 
void euler(int n){
	vis[n] = true;
	path.push_back(n);
	for(int i=0; i<adj[n].size(); i++){
		int v = adj[n][i];
		if(vis[v]) continue;
		euler(v);
		path.push_back(n);
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	
	for(int i=1; i<=n; i++){
		adj[i].clear();
		vis[i] = false;
	}
	path.clear();
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	euler(1);
	vector<int> alien[k];
	int ptr = 0;
	int max = 2*n/k + (2*n % k > 0);
	for(int i=0; i<k; i++){
		while(alien[i].size() < max && ptr < path.size()){
			alien[i].push_back(path[ptr++]);
		} 
	}
	for(int i=0; i<k; i++){
		if(alien[i].size() == 0) alien[i].push_back(1);
	}	
	/*for(int i=k-1; i>0; i--){
		if(alien[i].size() == 0){
			int j = i-1;
			while(alien[j].size() == 0 && j>=0) j--;
			if(j < 0) {
				int j = i+1;
				while(alien[j].size() <= 1 && j<k) j++;
			}
			alien[i].push_back(alien[j].back()); 
			alien[j].pop_back();
		}
	}*/
	for(int i=0; i<k; i++){
		cout << alien[i].size();
		for(int j=0; j<alien[i].size(); j++) cout << " " << alien[i][j];
		cout << endl;
	}
	
}
