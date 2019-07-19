#include <bits/stdc++.h>
#define ROOT 1

using namespace std;

struct node {
	int sum=0, prefix=0, sufix=0, maxsum=0;
	node(){}
	node(int a, int b , int c , int d) 
		: sum(a), prefix(b), sufix(c), maxsum(d)
	{}
};

node tree[4*51234];
int v[51234];

node combine(node a, node b) {
	node ans(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	ans.sum = a.sum + b.sum;
	ans.prefix = max(a.prefix, a.sum + b.prefix);
	ans.sufix = max(b.sufix, b.sum + a.sufix);
	ans.maxsum = max(a.maxsum, max(b.maxsum, a.sufix + b.prefix));
	return ans;
}


void update(int root, int l, int r, int idx, int val){
	//cout << l << " " << r << endl;
	if(l == idx && r == idx){
		tree[root].sum = tree[root].prefix = tree[root].sufix = tree[root].maxsum = val;
		return;
	}
	int m  = (l+r)/2;
	if(m < idx) update(2*root+1, m+1, r, idx, val);
	else if(idx <= m) update(2*root, l, m, idx, val);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

node query(int root, int l, int r, int a, int b){
	if(l == a && r == b) return tree[root];
	int m = (l+r)/2;
	if(b <= m) return query(2*root, l, m, a, b);
	else if(m < a) return query(2*root+1, m+1, r, a, b);
	else {
		node val1 = query(2*root, l, m, a, m);
		node val2 = query(2*root+1, m+1, r, m+1, b);
		node ans = combine(val1, val2);
		return ans;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i];
		update(ROOT, 0, n-1, i, v[i]);
	}
	int q;
	cin >> q;
	while(q--){
		int c,l,r;
		cin >> c >> l >> r;
		if(c == 0){
			l--;
			update(ROOT, 0, n-1, l, r);
		}
		else{
			l--, r--;
			cout << query(ROOT, 0, n-1, l, r).maxsum << endl;
		}
	}
}
	


		
		


	 
