#include <bits/stdc++.h>
#define MAXN 100100
#define pb push_back
using namespace std;
vector<int> g[MAXN];
vector<int> gt[MAXN];

vector<int> order;
vector<int> used;
vector<int> comp;
int color[MAXN];
void dfs(int v){
	used[v] = true;
	for(int i=0;i<(int)g[v].size();i++){
		int u = g[v][i];
		if(!used[u])dfs(u);
	}
	order.pb(v);
}

void dfs2(int v){
	used[v] = true;
	comp.pb(v);
	for(int i=0;i<(int)gt[v].size();i++){
		int u = gt[v][i];
		if(!used[u])dfs2(u);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
		gt[b].pb(a);
	}
	used.assign(n+1,false);
	for(int i=1;i<=n;i++)if(!used[i])dfs(i);
	used.assign(n+1,false);
	int k = 0;
	for(int i=0;i<n;i++){
		int v = order[n-1-i];
		if(!used[v])dfs2(v);
		else continue;
		++k;
		for(int j=0;j<(int)comp.size();j++){
			color[comp[j]]=k;
		}
		comp.clear();
	}
	cout<<k<<endl;
	for(int i=1;i<=n;i++)cout<<color[i]<<" ";
	cout<<endl;
	
}