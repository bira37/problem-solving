#include <bits/stdc++.h>
#define ROOT 1
#define endl '\n'

using namespace std;

struct node{
	int val;
	node() {}
	node(int v) : val(v) {};
};

int L[11234], vis[11234], P[11234], ch[11234], subsz[11234], st[11234], heavy[11234], vet[11234];
int t = 0;
vector<int> adj[11234];
map<pair<int,int>, int> adj_cost;
pair<int,int> idx_to_edge[11234];
node tree[4*11234];
int n;

void init(){
	t = 0;
	adj_cost.clear();
	for(int i=0; i<=4*n; i++) tree[i].val = 0;
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
	node ans;
	ans.val = max(a.val, b.val);
	return ans;
}

void build(int root, int l, int r){
	if(l == r){
		tree[root].val = vet[l];
		return;
	}
	int m = (l+r)/2;
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

void seg_update(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root] = node(val);
		return;
	}
	int m = (l+r)/2;
	if(idx <= m) seg_update(2*root, l, m, idx, val);
	else seg_update(2*root+1, m+1, r, idx, val);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

node seg_query(int root, int l, int r, int a, int b){
	if(l == a && r == b) return tree[root];
	int m = (l+r)/2;
	if(b <= m) return seg_query(2*root, l, m, a, b);
	else if(m < a) return seg_query(2*root+1, m+1, r, a, b);
	
	node left = seg_query(2*root, l, m, a, m);
	node right = seg_query(2*root+1, m+1, r, m+1, b);
	node ans = combine(left, right);
	return ans;
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

void st_dfs(int u, int c){
	vis[u] = true;
	vet[t] = c;
	st[u]=t++;
	if(heavy[u] != -1){
		ch[heavy[u]] = ch[u];
		st_dfs(heavy[u], adj_cost[make_pair(u, heavy[u])]);
	}
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v] || v == heavy[u]) continue;
		st_dfs(v, adj_cost[make_pair(u,v)]);
	}
}
	
int query(int a, int b){
	int ans = 0;
	if(a == b) return 0;
	while(ch[a] != ch[b]){
		if(L[ch[b]] > L[ch[a]]) swap(a,b);
		ans = max(ans, seg_query(ROOT, 0, n-1, st[ch[a]], st[a]).val);
		a = P[ch[a]];
	}
	if(L[b] < L[a]) swap(a,b);
	if(st[a]+1 <= st[b]) ans = max(ans, seg_query(ROOT, 0, n-1, st[a]+1, st[b]).val);
	return ans;
}

void update(int i, int val){
	pair<int, int> edge = idx_to_edge[i];
	seg_update(ROOT, 0, n-1, max(st[edge.first],st[edge.second]), val);
}
		

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	//bool flag = false;
	while(q--){
		//if(flag) cout << endl;
		//else flag = true;
		cin >> n;
		init();
		for(int i=0; i<n-1; i++){
			int u,v,c;
			cin >> u >> v >> c;
			adj[u].push_back(v);
			adj[v].push_back(u);
			idx_to_edge[i] = make_pair(u,v);
			adj_cost[make_pair(u,v)] = c;
			adj_cost[make_pair(v,u)] = c;
		}
		pre_dfs(1);
		for(int i=1; i<=n; i++) vis[i] = false;
		st_dfs(1, -1);
		build(ROOT, 0, n-1);
		string consulta;
		while(cin >> consulta, consulta != "DONE"){
			int a,b;
			cin >> a >> b;
			if(consulta == "QUERY"){
				//cout << "fazendo query" << endl;
				cout << query(a,b) << endl;
			}
			else if(consulta == "CHANGE"){
				a--;
				//cout << "fazendo update" << endl;
				update(a, b);
			}
		}
	}
}
