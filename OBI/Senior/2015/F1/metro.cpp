#include <bits/stdc++.h>
#define MAXN 20100
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);
using namespace std;

vector<int> g[MAXN];
int n,m;
int vis[MAXN];
int rem[MAXN];

void takeleaf(int v,int p){
	rem[v] = true;
	for(int i=0;i<(int)g[v].size();i++){
		int u = g[v][i];
		if(u==p || g[u].size()>2)continue;
		takeleaf(u,v);
	}	
}

void takemid(int v,int p){
	rem[v] = true;
	for(int i=0;i<(int)g[v].size();i++){
		int u = g[v][i];
		if(u==p || g[u].size()>2)continue;
		takemid(u,v);
	}
}

int32_t main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(rem,false,sizeof(rem));
	for(int i=1;i<=n;i++){
		if(g[i].size()==1){
			takeleaf(i,-1);
		}
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()>=5){
		//	cout<<i<<endl;
			takemid(i,-1);
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!rem[i])ans++;
	}
	cout<<ans<<endl;
	
	
	
}