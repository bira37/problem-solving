#include <bits/stdc++.h>

#define ROOT 1

using namespace std;

struct node{
	int sum=0;
	node(){}
	node(int a) : sum(a){}
};

node tree[4*1000000];

node combine(node a, node b){
	node ans;
	ans.sum = (a.sum+b.sum);
	return ans;
}

void update(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root].sum += val;
		return;
	}
	
	int m = (l+r)/2;
	if(idx <= m) update(2*root, l, m, idx, val);
	else update(2*root+1, m+1, r, idx, val);
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
	int n,q;
	cin >> n >> q;
	while(q--){
		string a;
		int l,r;
		cin >> a;
		if(a == "add"){
			cin >> l >> r;
			l--;
			update(ROOT, 0, n-1, l, r);
		}
		else {
			cin >> l >> r;
			l--,r--;
			cout << query(ROOT, 0, n-1, l, r).sum << endl;
		}
	}
}
