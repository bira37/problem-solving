#include <bits/stdc++.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ROOT 1

using namespace std;

struct node{
	vector< pair<int, int> > arr;
	node(){
		arr.clear();
	}
};

node tree[4*112345];
pair<int, int> v[112345];
int n,r;

int get_ans(vector< pair<int, int> > & v, int limit){
	int index = upper_bound(v.begin(), v.end(), make_pair(limit, INT_MAX)) - v.begin();
	index--;
	if(index == -1) return INT_MAX;
	return v[index].second;
}

void build(int root, int l, int r){
	if(l == r){
		tree[root].arr.push_back(v[l]);
		return;
	}
	int m = (l+r)>>1;
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	int i=0,j=0;
	while(i < tree[2*root].arr.size() && j < tree[2*root+1].arr.size()){
		if(tree[2*root].arr[i] < tree[2*root+1].arr[j]) tree[root].arr.push_back(tree[2*root].arr[i++]);
		else tree[root].arr.push_back(tree[2*root+1].arr[j++]);
	}
	while(i < tree[2*root].arr.size()) tree[root].arr.push_back(tree[2*root].arr[i++]);
	while(j < tree[2*root+1].arr.size()) tree[root].arr.push_back(tree[2*root+1].arr[j++]);
}

void build_prefix(int root, int l, int r){
	if(l == r) return;
	int m = (l+r)>>1;
	build_prefix(2*root, l, m);
	build_prefix(2*root+1, m+1, r);
	for(int i=1; i<tree[root].arr.size(); i++){
		tree[root].arr[i].second = min(tree[root].arr[i].second, tree[root].arr[i-1].second);
	}
}

int query(int root, int l, int r, int a, int b, int limit){
	if(l == a && r == b) return get_ans(tree[root].arr, limit);
	int m = (l+r)/2;
	if(b <= m) return query(2*root, l, m, a, b, limit);
	else if(m < a) return query(2*root+1, m+1, r, a, b, limit);
	
	int left = query(2*root, l, m, a, m, limit);
	int right = query(2*root+1, m+1, r, m+1, b, limit);
	return min(left, right);
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> adj[112345];
int L[112345];
int C[112345];
int tempo = 0;
int subsz[112345];
int st[112345];

void process(int u, int p, int l){
	st[u] = tempo;
	L[u] = l;
	v[tempo++] = make_pair(l, C[u]); 
	subsz[u] = 1;
	for(int v : adj[u]){
		if(v == p) continue;
		process(v, u, l+1);
		subsz[u] += subsz[v];
	}
}

int32_t main(){
	scanf("%d%d", &n, &r);
	for(int i=0; i<n; i++){
		scanf("%d", &C[i+1]);
	}
	for(int i=0; i<n-1; i++){
		int u,v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	L[r] = 0;
	process(r, -1, 0);
	build(ROOT, 0, tempo-1);
	build_prefix(ROOT, 0, tempo-1);
	
	int m;
	scanf("%d", &m);
	int ans = 0;
	while(m--){
		int p,q;
		scanf("%d%d", &p, &q);
		int x = (p+ans)%n +1;
		int k = (q+ans)%n;
		ans = query(ROOT, 0, tempo-1, st[x], st[x]+subsz[x]-1, L[x]+k);
		printf("%d\n", ans);
	}
}