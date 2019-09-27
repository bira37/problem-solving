#include <bits/stdc++.h>
#define MAXN 200100
#define pb push_back
using namespace std;

vector<int> adj[MAXN];
int pai[MAXN];
int ans[MAXN][20];
void DFS(int v){
	for(int i=0;i<(int)adj[v].size();i++){
		int u = adj[v][i];
		if(pai[v]==u)continue;
		pai[u]=v;
		DFS(u);
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	pai[1] = -1;
	DFS(1);   
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++){
		ans[i][0] = pai[i];
	}	
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			if(ans[i][j-1]!=-1 && ans[ans[i][j-1]][j-1]!=-1){
				ans[i][j]=ans[ans[i][j-1]][j-1];
			}
		}
	}
	while(q--){
		int x,k;
		cin>>x>>k;
		
		for(int i=19;i>=0;i--){
			if((1<<i)&k && x!=-1){
				x = ans[x][i];
			}
		}
		cout<<x<<endl;
	}
	
}