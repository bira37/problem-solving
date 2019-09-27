#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define MAXN 100100
using namespace std;
typedef pair<int,int> pii;

int res[MAXN];
int best[MAXN];
vector<int> adj[MAXN];
vector<int> g[MAXN];
int n,m;
int suf[MAXN];
int32_t main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i=1;i<=n;i++){
		res[i] = 1;
		sort(adj[i].begin(),adj[i].end());
	}
	
	for(int i=n;i>=1;i--){
		suf[adj[i].size()] = 0;
		for(int j=(int)adj[i].size()-1;j>=0;j--){
			int v = adj[i][j];
           suf[j] = max(suf[j+1],res[v]);  	
		}
		for(int j=0;j<(int)adj[i].size();j++){
			int v = adj[i][j];
			res[v] = max(res[v],2 + suf[j+1]);
		}
	}
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	cout<<endl;
	
	
}