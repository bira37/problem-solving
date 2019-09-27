#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 100100
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
inline int mod(int n, int m){int ret = n%m; if(ret < 0) ret += m; return ret;}
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }    else return mod(k*k,m);
}


vector<pii> adj[MAXN];
int vis[MAXN];
int sz[MAXN];

int dfs(int u,int p){
	vis[u] = 1;
	sz[u] = 1;
	for(int i=0;i<(int)adj[u].size();i++){
		if(adj[u][i].ff==p || vis[adj[u][i].ff]==1)continue;
		if(adj[u][i].ss==0){
			sz[u]+=dfs(adj[u][i].ff,u);
		}
	}
	return sz[u];
}

int32_t main(){
	fastio;
	//conecta cada letra a sua posicao + vezes para apertar
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].pb(pii(b,c));
		adj[b].pb(pii(a,c));
	}
	int resp = (n-1)*n;
	
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			int tira = dfs(i,-1);
			resp-= tira*(tira-1);
		}
	}
	cout<<resp/2<<endl;
}