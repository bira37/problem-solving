#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define IOS_SYNC ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>
#define vpll vector< pll >
#define vpii vector< pii >
 
using namespace std;
 
typedef long long ll;
 
////////////////////////CODE//////////////////////////////////////////////////////
 
//uses anc
 
#include <bits/stdc++.h>
 
using namespace std;
int p[(int)1e5+1];
int L[(int)1e5+1];
int anc[20][(int)1e5+1];
int st[(int)1e5+1];
int ed[(int)1e5+1];
bool vis[(int)1e5+1];
int tempo = 0;
 
vector<int> adj[(int)1e5+1];
 
void dfs(int u){
	vis[u] = true;
	st[u] = tempo++;
	for(int v : adj[u]){
		if(!vis[v]){
			L[v] = L[u]+1;
			dfs(v);
		}
	}
	ed[u] = tempo++;
}
 
bool is_ancestor(int u, int v){
    return st[u] <= st[v] && st[v] <= ed[u];
}
 
int lca(int u, int v){
    if(is_ancestor(u,v)) return u;
    for(int i=19; i>=0; --i){
	if(anc[i][u] == -1) continue;
        if(!is_ancestor(anc[i][u],v)) u = anc[i][u];
    }
    return p[u];
}
 
int dist(int a, int b){
	int l = lca(a,b);
	return L[a]+L[b] - 2*L[l];
}
 
int solve(int a, int b, int c){
	int lca1 = lca(a,b), lca2 = lca(a,c) , lca3 = lca(b,c);
	if(lca1 == lca2){
		return 1+ max(max(dist(lca3,b), dist(lca3, c)), dist(lca3,a));
	}
	else if(lca1 == lca3){
		return 1+max(dist(lca2,a), max(dist(lca2,b), dist(lca2, c)));
	}
	else {
		return 1+max(dist(lca1,a), max(dist(lca1,b), dist(lca1, c)));
	}
}
 
 
int main(){
	IOS_SYNC(false);
	int n,q;
	cin >> n >> q;
	for(int i=1; i<n; i++){
		int x;
		cin >> x;
		x--;
		p[i] = x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	p[0] = -1;
	for(int i=0; i<n; i++) vis[i] = false;
	for(int i=0; i<n; i++){
		if(p[i] == -1){
			L[i] = 0;
			dfs(i);
		}
	}
	for(int i=0; i<n; i++){
		anc[0][i] = p[i];
	}
	for(int i=1; i<20; i++){
		for(int j=0; j<n; j++){
			if(anc[i-1][j] != -1){
				anc[i][j] = anc[i-1][anc[i-1][j]];
			}
			else anc[i][j] = -1;
		}
	}
 
	while(q--){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		int ans = 0;
		ans = max(ans, solve(a,b,c));
		ans = max(ans, solve(b,a,c));
		ans = max(ans, solve(a,c,b));
		ans = max(ans, solve(b,c,a));
		ans = max(ans, solve(c,b,a));
		ans = max(ans, solve(c,a,b));
		cout << ans << endl;
	}
	return 0;
}
