#include <bits/stdc++.h>
#define ROOT 1
#define N 112345

using namespace std;

struct node{
	double sum, lazysum, lazymul;
};

node tree[4*N];

node combine(node a, node b){
	node res;
	res.sum = a.sum + b.sum;
	res.lazysum = a.lazysum + b.lazysum;
	res.lazymul = a.lazymul*b.lazymul;
	return res;
}

void build(int root, int l, int r){
	if(l == r){
		double x;
		cin >> x;
		tree[root].sum = x;
		tree[root].lazysum = 0.0;
		tree[root].lazymul = 1.0;
		return;
	}
	int m = (l+r)>>1;
	build(2*root, l,m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

void propagate(int root, int l , int r){
	if(tree[root].lazysum == 0) return;
	//update tree using lazy node
	tree[root].sum *= tree[root].lazymul;
	tree[root].sum += tree[root].lazysum*(r-l+1);
	if(l != r){
		tree[2*root].lazysum = tree[2*root].lazysum*tree[root].lazymul + tree[root].lazysum;
		tree[2*root].lazymul *= tree[root].lazymul;
		tree[2*root+1].lazysum = tree[2*root+1].lazysum*tree[root].lazymul + tree[root].lazysum;
		tree[2*root+1].lazymul *= tree[root].lazymul;
	}
	tree[root].lazysum = 0;
	tree[root].lazymul = 1;
}

void range_update(int root, int l, int r, int a, int b, double sum, double mul){
	propagate(root, l, r);
	if(l == a && r == b){
		tree[root].lazysum = sum;
		tree[root].lazymul = mul;
		return;
	}
	
	int m = (l+r)/2;
	
	if(b <= m) range_update(2*root, l, m, a, b, sum, mul);
	else if(m < a) range_update(2*root+1, m+1, r, a, b, sum, mul);
	else {
		range_update(2*root, l, m, a, m, sum, mul);
		range_update(2*root+1, m+1, r, m+1, b, sum, mul);
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	build(ROOT, 0, n-1);
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int l1,r1,l2,r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--,r1--, l2--, r2--;
			double avg1 = query(ROOT, 0, n-1, l1, r1).sum/(r1-l1+1);
			double avg2 = query(ROOT, 0, n-1, l2, r2).sum/(r2-l2+1);
			range_update(ROOT, 0, n-1, l1, r1, avg2/(r1-l1+1), double(r1-l1)/(r1-l1+1));
			range_update(ROOT, 0, n-1, l2, r2, avg1/(r2-l2+1), double(r2-l2)/(r2-l2+1));
		}
		else {
			int l,r;
			cin >> l >> r;
			l--, r--;
			cout << fixed << setprecision(8) << query(ROOT, 0, n-1, l, r).sum << endl;
		}
	}
}