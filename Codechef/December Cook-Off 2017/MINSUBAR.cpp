#include <bits/stdc++.h>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long
#define N 112345

using namespace std;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

struct node{
	int val;
};

node tree[4*2*N];
node lazy[4*2*N];

node combine(node a, node b){
	node res;
	res.val = max(a.val, b.val);
	return res;
}

void propagate(int root, int l , int r){
	if(lazy[root].val == -1) return;
	tree[root].val = max(lazy[root].val, tree[root].val);
	if(l != r){
		lazy[2*root].val = max(lazy[2*root].val, lazy[root].val);
		lazy[2*root+1].val = max(lazy[2*root+1].val, lazy[root].val);
	}
	lazy[root].val = -1;
}

void range_update(int root, int l, int r, int a, int b, long long val){
	if(l == a && r == b){
		lazy[root].val = max(lazy[root].val, val);
		return;
	}
	
	int m = (l+r)/2;
	
	if(b <= m) range_update(2*root, l, m, a, b, val);
	else if(m < a) range_update(2*root+1, m+1, r, a, b, val);
	else {
		range_update(2*root, l, m, a, m, val);
		range_update(2*root+1, m+1, r, m+1, b, val);
	}
	
	propagate(root, l , r);
	propagate(2*root, l, m);
	propagate(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

node query(int root, int l, int r, int a, int b){
	propagate(root, l, r);
	if(l == a && r == b) return tree[root];
	
	int m = (l+r)/2;
	if(b <= m) return query(2*root, l, m, a, b);
	else if(m < a) return query(2*root+1, m+1, r, a, b);
	else {
		node left = query(2*root, l, m, a, m);
		node right = query(2*root+1, m+1, r, m+1, b);
		node ans = combine(left, right);
		return ans;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int v[n];
		int pre[n+1];
		pre[0] = 0;
		set<int> s;
		s.insert(0);
		s.insert(0-d);
		for(int i=0; i<n; i++){
			cin >> v[i];
			pre[i+1] = pre[i] + v[i];
			s.insert(pre[i+1]);
			s.insert(pre[i+1]-d);
		}
		vector<int> aux;
		for(int x : s) aux.push_back(x);
		map<int, int> comp_to_val;
		map<int, int> val_to_comp;
		for(int i=0; i<=n; i++){
			int idx = lower_bound(aux.begin(), aux.end(), pre[i]) - aux.begin();
			val_to_comp[pre[i]] = idx;
			comp_to_val[idx] = pre[i];
			idx = lower_bound(aux.begin(), aux.end(), pre[i]-d) - aux.begin();
			val_to_comp[pre[i]-d] = idx;
			comp_to_val[idx] = pre[i]-d;
		}
		
		int l = aux.size();
		
		for(int i=0; i<4*aux.size(); i++){
			lazy[i].val = -1;
			tree[i].val = -1;
		}
		
		int ans = (int)1e9;
		
		for(int i=0; i<=n; i++){
			int search = pre[i] - d;
			int csearch = -1;
			if(val_to_comp.count(search)) csearch = val_to_comp[search];
			int rmq = -1;
			if(csearch != -1) rmq = query(1, 0, l-1, 0, csearch).val;
			if(rmq != -1) ans = min(ans, i - rmq);
			//cout << i << " " << rmq << endl;
			range_update(1, 0, l-1, val_to_comp[pre[i]], l-1, i);
		}
		
		
		if(ans == (int)1e9) cout << -1 << endl;
		else cout << ans << endl;
	}
}
		
