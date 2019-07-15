#include <stdio.h>
#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ROOT 1
#define N 512345

using namespace std;

struct node{
	int gcd;
	node() {}
	node(int gcd) : gcd(gcd) {}
};

node tree[4*N];

node combine(node a, node b){
	node ans;
	ans.gcd = __gcd(a.gcd, b.gcd);
	return ans;
}

void build(int root, int l, int r){
	if(l == r){
		int x;
		scanf("%d", &x);
		tree[root] = node(x);
		return;
	}
	int m = (l+r)>>1;
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

void update(int root, int l, int r, int idx, int val){
	if(l == r && l == idx){
		tree[root] = node(val);
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
	int n;
	scanf("%d", &n);
	build(ROOT, 0, n-1);
	int q;
	scanf("%d", &q);
	while(q--){
		int op;
		scanf("%d", &op);
		if(op == 2){
			int idx, val;
			scanf("%d%d", &idx, &val);
			idx--;
			update(ROOT, 0, n-1, idx, val);
		}
		else {
			int l, r, guess;
			scanf("%d%d%d", &l, &r, &guess);
			l--, r--;
			int g = query(ROOT, 0, n-1, l, r).gcd;
			if(g%guess == 0 || (r-l+1) == 1){
				printf("YES\n");
			}
			else {
				int la = l, ra = r;
				int ans = l;
				while(la <= ra){
					int m = (la+ra)>>1;
					if(query(ROOT, 0, n-1, l, m).gcd%guess != 0){
						ans = m;
						ra = m-1;
					}
					else la = m+1;
				}
				if(ans+1 > r || query(ROOT, 0, n-1, ans+1, r).gcd%guess == 0){
					 printf("YES\n");
				}
				else printf("NO\n");
			}
		}
	}
}