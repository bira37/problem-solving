#include <bits/stdc++.h>
#define MAXN 100100
#define pb push_back
using namespace std;

int d[MAXN];
int dist[MAXN];
int vis[MAXN];
int pai[MAXN];
int n;
vector<int> adj[MAXN];
int BFS(){
	
	memset(vis,false,sizeof(vis));
	queue<int> fila;
	for(int i=1;i<=n;i++){
		if(adj[i].size()==1){
			fila.push(i);
			pai[i] = 0;
			vis[i] = true;
		}
	}
	dist[0] = -1;
	int res = n;
	while(!fila.empty()){
		int v = fila.front();
		fila.pop();
		for(int i=0;i<(int)adj[v].size();i++){
			int u = adj[v][i];
			if(u==pai[v])continue;
			if(!vis[u]){
			fila.push(u);pai[u]=v;dist[u]=dist[v]+1;vis[u]=true;}
			else{
				res = min(res,dist[v]+1+dist[u]);
			}
		}
		
		
		
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		d[a]++;
		d[b]++;
	}
	cout<<BFS()<<endl;
}