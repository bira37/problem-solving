#include <bits/stdc++.h>
 
#define ROOT 1
 
using namespace std;
 
struct node{
	int open, close, sum;
	node(){}
	node(int a, int b, int c) : open(a), close(b), sum(c){}
};
 
string s;
node tree[4*1123456];
 
node combine(node a, node b){
	node ans;
	int inc = min(a.open, b.close);
	ans.sum = a.sum + b.sum + inc;
	ans.open = a.open+b.open-inc;
	ans.close = a.close + b.close-inc;
	return ans;
}
 
void build(int root, int l, int r){
	if(l == r){
		if(s[l] == '(') tree[root] = node(1,0,0);
		else tree[root] = node(0,1,0);
		return;
	}
	int m = (l+r)/2;
	build(2*root, l, m);
	build(2*root+1, m+1, r);
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
	cin >> s;
	build(ROOT, 0, s.size()-1);
	
	int q;
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		a--,b--;
		cout << 2*query(ROOT, 0, s.size()-1, a, b).sum << endl;
	}
}
