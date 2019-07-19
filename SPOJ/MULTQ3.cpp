#include <bits/stdc++.h>

#define ROOT 1

using namespace std;

struct node{
	int one, two, zero;
	node(){}
	node(int a, int b, int c) : one(a), two(b), zero(c) {}
};

node tree[4*1000000];
int lazy[4*1000000];

node combine(node a, node b){
	node res;
	res.one = a.one + b.one;
	res.two = a.two + b.two;
	res.zero = a.zero + b.zero;
	return res;
}

void propagate(int root, int l , int r){
	if(lazy[root] == 0) return;
	
	if(lazy[root] == 1){
		int aux = tree[root].zero;
		tree[root].zero = tree[root].one;
		tree[root].one = tree[root].two;
		tree[root].two = aux;
	}
	else if(lazy[root] == 2){
		int aux = tree[root].zero;
		tree[root].zero = tree[root].two;
		tree[root].two = tree[root].one;
		tree[root].one = aux;
	}
		
	if(l != r){
		lazy[2*root] = (lazy[2*root] + lazy[root])%3;
		lazy[2*root+1] = (lazy[2*root+1] + lazy[root])%3;
	}
	
	lazy[root] = 0;
}

void range_update(int root, int l, int r, int a, int b){
	if(l == a && r == b){
		lazy[root]++;
		return;
	}
	
	int m = (l+r)/2;
	
	if(b <= m) range_update(2*root, l, m, a, b);
	else if(m < a) range_update(2*root+1, m+1, r, a, b);
	else {
		range_update(2*root, l, m, a, m);
		range_update(2*root+1, m+1, r, m+1, b);
	}
	
	propagate(root, l , r);
	propagate(2*root, l, m);
	propagate(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

node query(int root, int l, int r, int a, int b){
	propagate(root, l, r);
	if(l == a && r == b){
		return tree[root];
	}
	
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

void build(int root, int l, int r){
	if(l == r){
		tree[root] = node(0,0,1);
		return;
	}
		
	int m = (l+r)/2;
	
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
	lazy[root] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	int n,q;
	cin >> n >> q;
	build(ROOT, 0, n-1);
	while(q--){
		int c,l,r;
		cin >> c >> l >> r;
		if(l > r) swap(l, r);
		if(c == 0) range_update(ROOT, 0, n-1, l, r);
		else cout << query(ROOT, 0, n-1, l, r).zero << endl;
	}
}
