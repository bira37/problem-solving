#include <bits/stdc++.h>

#define ROOT 1

using namespace std;

struct node{
	int sqr;
	node(){}
	node(int a) : sqr(a){}
};

int v[100000];
node tree[4*100000];

node combine(node a, node b){
	node ans(INT_MIN);
	ans.sqr = a.sqr + b.sqr;
	return ans;
}

void update(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root] = node(val*val);
		return;
	}
	
	int m = (l+r)/2;
	if(idx <= m) update(2*root, l, m, idx, val);
	else update(2*root+1, m+1, r, idx, val);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

void updatesum(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root] = node(tree[root].sqr*tree[root].sqr + 2*tree[root].sqr*val + val*val);
		return;
	}
	
	int m = (l+r)/2;
	if(idx <= m) updatesum(2*root, l, m, idx, val);
	else updatesum(2*root+1, m+1, r, idx, val);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

node query(int root, int l, int r, int a, int b){
	if(l == a && r == b) return tree[root];
	int m = (l+r)/2;
	if(b <= m) return query(2*root, l, m, a, b);
	else if(m < a) return query(2*root+1, m+1, r, a, b);
	
	node left = query(2*root, l, m, a, m);
	node right = query(2*root+1, m+1, r, m+1, b);
	node ans = combine(left, right);
	return ans;
} 

int main(){
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		cout << "Case " << i+1 << ":" << endl;
		
		int n,q;
		cin >> n >> q;
		for(int i=0; i<n; i++){
			cin >> v[i];
			update(ROOT, 0, n-1, i, v[i]);
		}
		
		while(q--){
			int c,l,r;
			cin >> c >> l >> r;
			l--,r--;
			if(l > r) swap(l,r);
			if(c == 2){
				cout << query(ROOT, 0, n-1, l, r).sqr << endl;
			}
			else if(c == 1){
				int val;
				cin >> val;
				for(int i=l; i<=r; i++)
					updatesum(ROOT, 0, n-1, i, val);
			}
			else {
				int val;
				cin >> val;
				for(int i=l; i<=r; i++)
					update(ROOT, 0, n-1, i, val);
			}
		}
	}
} 
