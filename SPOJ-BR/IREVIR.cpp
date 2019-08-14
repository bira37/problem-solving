#include <bits/stdc++.h>

using namespace std;

bool vis[2001];
bool vis2[2001];
vector<int> adj[2001];
vector<int> adj2[2001];
int cont=0;
int cont2=0;

void dfs(int n){
	cont++;
	vis[n]=true;
	for(int i=0; i < adj[n].size(); i++){
		if(vis[adj[n][i]] == true) continue;
		dfs(adj[n][i]);
	}
}

void dfs2(int n){
	cont2++;
	vis2[n]=true;
	for(int i=0; i < adj2[n].size(); i++){
		if(vis2[adj2[n][i]] == true) continue;
		dfs2(adj2[n][i]);
	}
}

int main(){
	int n,m;
	while(cin >> n >> m, n+m != 0){
		cont=0;
		cont2=0;
		for(int i=1;i <=n; i++){
			vis[i]=false;
			adj[i].clear();
			vis2[i]=false;
			adj2[i].clear();
		}
		for(int i=0; i<m; i++){
			int x,y,z;
			cin >> x >> y >> z;
			adj[x].push_back(y);
			adj2[y].push_back(x);
			if(z==2){
				adj[y].push_back(x);
				adj2[x].push_back(y);
			}
		}
		dfs(1);
		dfs2(1);
		if(cont+cont2 == 2*n) cout << "1" << endl;
		else cout << "0" << endl;
	}
}
		

