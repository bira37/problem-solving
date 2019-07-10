#include <bits/stdc++.h>
#define ROOT 1
#define endl '\n'
 
using namespace std;
 
struct node{
	int lazy = 0;
	int val = 0;
	node() {}
};
 
int L[2*112345], vis[2*112345], P[2*112345], ch[2*112345], subsz[2*112345], st[2*112345], ed[2*112345], heavy[2*112345], vet[2*112345];
int t = 0;
vector<int> adj[2*112345];
node tree[2*4*2*112345];
int n,q;
 
void init(){
	t = 0;
	for(int i=0; i<=n; i++){
		vis[i] = false;
		adj[i].clear();
		ch[i] = i;
		L[i] = 0;
		P[i] = -1;
		subsz[i] = 1;
		heavy[i] = -1;
	}
}
 
node combine(node a, node b){
	node res;
	res.val = a.val+b.val;
	return res;
}
 
void build(int root, int l, int r){
	tree[root].lazy = 0;
	if(l == r){
		tree[root].val = vet[l];
		return;
	}
	int m = (l+r)/2;
	build(2*root, l,m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}
 
void propagate(int root, int l , int r){
	if(tree[root].lazy == 0) return;
	
	if(tree[root].lazy%2) tree[root].val = (r-l+1)-tree[root].val;
	
	if(l != r){
		tree[2*root].lazy += tree[root].lazy;
		tree[2*root+1].lazy += tree[root].lazy;
	}
	
	tree[root].lazy = 0;
}
 
void seg_update(int root, int l, int r, int a, int b, int type){
	propagate(root, l , r);
	if(l == a && r == b){
		tree[root].lazy += type;
		return;
	}
	
	int m = (l+r)/2;
	
	if(b <= m) seg_update(2*root, l, m, a, b, type);
	else if(m < a) seg_update(2*root+1, m+1, r, a, b, type);
	else {
		seg_update(2*root, l, m, a, m, type);
		seg_update(2*root+1, m+1, r, m+1, b, type);
	}
	
	propagate(root, l , r);
	propagate(2*root, l, m);
	propagate(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}
 
node seg_query(int root, int l, int r, int a, int b){
	propagate(root, l, r);
	if(l == a && r == b) return tree[root];
	
	int m = (l+r)/2;
	if(b <= m) return seg_query(2*root, l, m, a, b);
	else if(m < a) return seg_query(2*root+1, m+1, r, a, b);
	else {
		node left = seg_query(2*root, l, m, a, m);
		node right = seg_query(2*root+1, m+1, r, m+1, b);
		node ans = combine(left, right);
		return ans;
	}
}
 
void pre_dfs(int u){
	vis[u] = true;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v]) continue;
		P[v] = u;
		L[v]=L[u]+1;
		pre_dfs(v);
		if(heavy[u] == -1 || subsz[heavy[u]] < subsz[v]) heavy[u] = v;
		subsz[u]+=subsz[v];
	}
}
 
void st_dfs(int u){
	vis[u] = true;
	st[u]=t++;
	if(heavy[u] != -1){
		ch[heavy[u]] = ch[u];
		st_dfs(heavy[u]);
	}
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v] || v == heavy[u]) continue;
		st_dfs(v);
	}
	ed[u] = t++;
}
 
void atualiza(int u){
	seg_update(ROOT, 0, t-1, st[u], ed[u], 1);
}		
 
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	init();
	for(int i=2; i<=n; i++){
		int v;
		cin >> v;
		adj[i].push_back(v);
		adj[v].push_back(i);
	}
	pre_dfs(1);
	for(int i=0; i<=n; i++) vis[i] = false;
	st_dfs(1);
	for(int i=1; i<=n; i++){
		cin >> vet[st[i]];
		vet[ed[i]] = vet[st[i]];
	}
	build(ROOT, 0, t-1);
	cin >> q;
	//for(int i=1; i<=n; i++){
	//	cout << seg_query(ROOT, 0, t-1, st[i]).val << " ";
	//}
	//cout << endl;
	while(q--){
		string x;
		int k;
		cin >> x >> k;
		if(x == "pow") atualiza(k);
		else {
			cout << seg_query(ROOT, 0, t-1, st[k], ed[k]).val/2 << endl; 
		}
		//for(int i=1; i<=n; i++){
		//	cout << seg_query(ROOT, 0, t-1, st[i]).val << " ";
		//}
		//cout << endl;
	}
}
