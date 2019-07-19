#include <bits/stdc++.h>
#define ROOT 1

using namespace std;

struct node{
	int maxnum=0, maxsum=0;
	node(){}
	node(int a, int b) : maxnum(a), maxsum(b){}
};

int v[112345];
node tree[4*112345];

node combine(node a, node b){
	node ans(INT_MIN, INT_MIN);
	ans.maxnum = max(a.maxnum, b.maxnum);
	ans.maxsum = max(a.maxsum, max(b.maxsum, a.maxnum + b.maxnum));
	return ans;
}

void update(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root] = node(val,val);
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
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i];
		update(ROOT, 0, n-1, i, v[i]);
	}
	int q;
	cin >> q;
	while(q--){
		char c;
		int a, b;
		cin >> c;
		cin >> a >> b;
		if(c == 'Q'){
			a--,b--;
			cout << query(ROOT, 0, n-1, a, b).maxsum << endl;
		}
		else update(ROOT, 0, n-1, a-1, b);
	}
}
