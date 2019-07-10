#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[212345];
int color[212345];
int vis[212345];
int ans = 0;
 
void dfs(int n, int cp){
	vis[n] = true;
	int c = 0;
	for(int i=0; i<adj[n].size(); i++){
		int v = adj[n][i];
		if(vis[v]) continue;
		c++;
		while(cp == c || c == color[n]) c++;
		color[v] = c;
		ans = max(ans, color[v]);
	}
	
	for(int i=0; i<adj[n].size(); i++){
		int v= adj[n][i];
		if(vis[v]) continue;
		dfs(v, color[n]);
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n;
	for(int i=1; i<=n; i++){
		adj[i].clear();
		color[i] = 0;
	}
	for(int i=0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	color[1] = 1;
	dfs(1,0);
	cout << ans << endl;
	for(int i=0; i<n; i++){
		if(!i) cout << color[i+1];
		else cout << " " << color[i+1];
	}
	cout << endl;
}
