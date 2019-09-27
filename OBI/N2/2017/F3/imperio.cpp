#include <bits/stdc++.h>
#define MAXN 100100
#define pb push_back
using namespace std;

int vis[MAXN];
int peso[MAXN];
int n;
int res=MAXN;
vector<int> adj[MAXN];

int DFS(int v){
	vis[v]=true;
	peso[v]=1;
	
	for(int i=0;i<(int)adj[v].size();i++){
		int u = adj[v][i];
		if(vis[u])continue;
		peso[v]+=DFS(u);
	}
	
	int atual = abs((n-peso[v])-peso[v]);
	res=min(res,atual);
	return peso[v];
}



int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	memset(vis,false,sizeof(vis));

	DFS(1);
	cout<<res<<endl;
}