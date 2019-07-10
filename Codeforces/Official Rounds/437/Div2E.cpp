#include <bits/stdc++.h>
#define int long long
#define ROOT 1
 
using namespace std;
 
struct node{
	int val, idx;
	node(){}
	node(int n, int i) : val(n), idx(i) {}
};
 
struct par{
	int id, val;
};
 
par arr[312345];
node tree[4*312345];
int buy[312345];
 
node combine(node a, node b){
	node ans;
	if(a.val < b.val || (a.val == b.val && a.idx > b.idx)){
		ans.val = a.val;
		ans.idx = a.idx;
	}
	else {
		ans.val = b.val;
		ans.idx = b.idx;
	}
	return ans;
}
 
void build(int root, int l, int r){
	if(l == r){
		tree[root] = node(arr[l].val, l);
		return;
	}
	int m = (l+r)/2;
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
} 
 
void update(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root] = node(val, idx);
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
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i].val;
		arr[i].id = i;
		buy[i] = i;
	}
	build(ROOT, 0, n-1);
	int ans = 0;
	for(int i=1; i<n; i++){
		node maior = query(ROOT, 0, n-1, 0, arr[i].id-1);
		if(arr[i].val > maior.val){
			if(buy[maior.idx] != maior.idx){
				ans += arr[i].val - maior.val;
				buy[arr[i].id] = buy[maior.idx];
				buy[maior.idx] = maior.idx;
			}
			else {
				ans += arr[i].val - maior.val;
				update(ROOT, 0, n-1, maior.idx, 1000000000);
				buy[arr[i].id] = maior.idx;
			}
		}
	}
	cout << ans << endl;
}
