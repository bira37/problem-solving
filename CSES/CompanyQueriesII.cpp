#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define MAXN 200100
#define pb push_back
#define endl '\n'
#define MAXL 20
#define M 1000000007
using namespace std;
 
inline int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}

int exp(int a,int b,int m){
	if(b==0)return 1;
	if(b==1)return a;
	int k = exp(a,b/2,m);
	if(b&1)return mod(a*mod(k*k,M),M);
	return mod(k*k,M);
}

int fat[2*MAXN+100];
int inv[2*MAXN+100];
int n,q;
int level[MAXN];
vector<int> adj[MAXN];
int pai[MAXN];
int ans[MAXN][MAXL+1];
int euler[MAXN];
int out[MAXN];

int is_ans(int u,int v){
	return euler[u]<=euler[v] && out[v]<=out[u];
}

int LCA(int u,int v){
//	if(euler[u]>euler[v])swap(u,v);
//	cout<<u<<" "<<v<<" "<<euler[u]<<" "<<euler[v]<<" "<<out[v]<<" "<<out[u]<<endl;
	
	if(is_ans(u,v)){
		return u;
	}
	for(int i=MAXL-1;i>=0;i--){
		if(ans[u][i]==-1)continue;
		if(!is_ans(ans[u][i],v))u = ans[u][i];
	}
	//cout<<v<<" "<<u<<" "<<ans[u][0]<<endl;
	return ans[u][0];
}

 
int query(int a,int b){
//	cout<<a<<" "<<b<<" "<<LCA(a,b)<<" "<<level[a]<<" "<<level[b]<<" "<<level[LCA(a,b)]<<endl;
	return level[a]+level[b] - 2*level[LCA(a,b)];
}

int tim = 0;
 
void DFS(int u,int p){
	euler[u]=tim++;
	pai[u]=p;
	level[u] = 1 + level[p];
	for(int i=0;i<(int)adj[u].size();i++){
		int v = adj[u][i];
		if(v==p)continue;
		DFS(v,u);
	}
	out[u] = tim++;
}
 
int32_t main(){
	fastio;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	level[0]=0;
	DFS(1,0);
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<MAXL;j++){
			ans[i][j]=-1;
		}
	}
	
	pai[1]=-1;
	
	for(int i=1;i<=n;i++){
		ans[i][0] = pai[i];
	}
	
	for(int j=1;j<MAXL;j++){
		for(int i=1;i<=n;i++){
			if(ans[i][j-1]!=-1)ans[i][j] = ans[ans[i][j-1]][j-1];	
			else ans[i][j]=-1;	
		}
	}



	while(q--){
		int a,b;
		cin>>a>>b;
		int D = LCA(a,b);
		cout<<D<<endl;
	}
	
}