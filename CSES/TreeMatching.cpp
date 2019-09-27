#include <bits/stdc++.h>
#define MAXN 200100
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
vector<int> adj[MAXN];
int vis[MAXN];
int res = 0; 
int dp[MAXN][2];
int DFS(int v,int color,int p){
	if(dp[v][color]!=-1)return dp[v][color];
	
	if(color==1){
		int ans = 0;
		for(int i=0;i<(int)adj[v].size();i++){
			int u = adj[v][i];
			if(u==p)continue;
			ans+=DFS(u,0,v);
		}
		
		return dp[v][color]= ans;
	}else{
		int op2 = 0;
		for(int i=0;i<(int)adj[v].size();i++){
			int u = adj[v][i];
			if(u==p)continue;
			op2+=DFS(u,0,v);
		}
		int op1 = 0;
		for(int i=0;i<(int)adj[v].size();i++){
			int u = adj[v][i];
			if(u==p)continue;
			op1 = max(op1,1+op2-DFS(u,0,v)+DFS(u,1,v));
		}
		
		return dp[v][color] = max(op1,op2);
	}

}


int32_t main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	res = DFS(1,0,-1);
	
	cout<<res<<endl;
}