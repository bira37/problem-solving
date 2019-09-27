#include <bits/stdc++.h>
#define MAXN 550
#define pb push_back
using namespace std;

int idade[MAXN];
vector<int> adj[MAXN];
int pos[MAXN];
int chave[MAXN];
int vis[MAXN];

int DFS(int v){
	int best = 1000;
	vis[v]=true;
	for(int i=0;i<(int)adj[v].size();i++){
		
		int u = adj[v][i];
		if(vis[u])continue;
		int y = idade[chave[u]];
	//	cout<<u<<" "<<y<<endl;
		best = min(best,y);
		best = min(best,DFS(u));
	}
	return best;
}

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>idade[i];
	for(int i=1;i<=n;i++){
		pos[i] = i ;
		chave[i] = i;
			}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		// a -> b
		adj[b].pb(a);
	}
	while(q--){
		char op;
		cin>>op;
		if(op=='P'){
			int p;
			cin>>p;
			memset(vis,false,sizeof(vis));
			int x = DFS(pos[p]);
			if(x==1000)cout<<"*"<<endl;
			else cout<<x<<endl;
		}else{
			int a,b;
			cin>>a>>b;
		//	int y = chave[a];
			
			
			int x = pos[a];
			pos[a] = pos[b];
			pos[b] = x;
			chave[pos[a]] = a;
			chave[pos[b]] = b;
		//	cout<<pos[a]<<" "<<pos[b]<<endl;
		}
	}
}