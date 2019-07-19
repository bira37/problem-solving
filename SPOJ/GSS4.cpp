#include <bits/stdc++.h>
#define ROOT 1
#define int long long
using namespace std;

struct node{
	long long sum;
	node(){}
	node(long long a) : sum(a) {}
};

node tree[4*100000];
long long v[100000];

node combine(node a, node b){
	node res;
	res.sum = a.sum + b.sum;
	return res;
}

void range_update(int root, int l, int r, int a, int b){
	if(tree[root].sum == r-l+1) return;
	if(l==r){
		tree[root].sum = sqrt(tree[root].sum);
		v[l] = tree[root].sum;
		return;
	}

	int m = (l+r)/2;
	if(b <= m) range_update(2*root, l, m, a, b);
	else if(m < a) range_update(2*root+1, m+1, r, a, b);
	else {
		range_update(2*root, l, m, a, m);
		range_update(2*root+1, m+1, r, m+1, b);
	}
	tree[root] = combine(tree[2*root], tree[2*root+1]);
} 

node query(int root, int l, int r, int a, int b){
	if(l == a && r == b) return tree[root];
	
	int m = (l+r)/2;
	if(b <= m) return query(2*root, l, m, a, b);
	else if(m < a) return query(2*root+1, m+1, r, a, b);
	else {
		node left = query(2*root, l, m, a, m);
		node right = query(2*root+1, m+1, r, m+1, b);
		node ans;
		ans = combine(left, right);
		return ans;
	}
}

void build(int root, int l, int r){
	if(l == r){
		tree[root].sum = v[l];
		return;
	}
	int m = (l+r)/2;
	
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	int n;
	int t = 0;
	while(cin >> n){
		cout << "Case #" << ++t << ":" << endl;
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		build(ROOT, 0, n-1);
	
		int q;
		cin >> q;
		while(q--){
			int c,l,r;
			cin >> c >> l >> r;
			l--, r--;
			if(l > r) swap(l,r);
			if(c == 0) range_update(ROOT, 0, n-1, l, r);
			else cout << query(ROOT, 0, n-1, l, r).sum << endl;
			//for(int i=0; i<n; i++) cout << v[i] << " ";
			//cout << endl;
		}
		cout << endl;
	}
}
		
