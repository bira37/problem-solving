#include <bits/stdc++.h>
 
using namespace std;
vector<int> cont;
vector<int> adj[150001];
int vis[150001];
int k=-1;
 
void dfs(int n){
	vis[n] = k;
	cont[k]++;
	for(int i=0; i<adj[n].size(); i++){
		if(vis[adj[n][i]] == -1) dfs(adj[n][i]);
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) vis[i] = -1;
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		if(vis[i] == -1){
			k++;
			cont.push_back(0);
			dfs(i);
		}
	}
 
	for(int i=1; i<=n; i++){
		if(cont[vis[i]]-1 != adj[i].size()){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
}
			
