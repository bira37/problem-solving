#include <bits/stdc++.h>
#define int long long
#define MAXN 200100
using namespace std;

struct Node{
	int pre,suf,sum;
	int maxsum;
};
Node tree[4*MAXN];
int A[MAXN];
Node merge(Node b,Node c){
	Node res;
	res.sum = b.sum+c.sum;
	res.pre = max(b.pre,b.sum+c.pre);
	res.suf = max(c.suf,c.sum+b.suf);
	res.maxsum = max(max(b.maxsum,c.maxsum),b.suf+c.pre);
	return res;
}

void build(int no,int i,int j){
	int m = (i+j)>>1,l=2*no,r=2*no+1;
	if(i==j){
		tree[no].sum = A[i];
		tree[no].pre = max(A[i],0LL);
		tree[no].suf = max(A[i],0LL);
		tree[no].maxsum = max(A[i],0LL);
	}else{
		build(l,i,m);
		build(r,m+1,j);
		tree[no] = merge(tree[l],tree[r]);
	}
}

Node query(int no,int i,int j,int a,int b){
	if(i>j){
		Node c = {0,0,0,0};
		return c;
	}
	if(i==a && j==b){
		return tree[no];
	}
	int m = (a+b)/2;
	return merge(query(2*no,i,min(j,m),a,b),query(2*no+1,max(i,m+1),j,m+1,b));
}

void update(int no,int i,int j,int pos,int val){
	if(i==j){
		tree[no].sum = val;
		tree[no].pre = max(0LL,val);
		tree[no].suf = max(0LL,val);
		tree[no].maxsum = max(0LL,val);
	}else{
		int m = (i+j)/2;
		if(pos<=m){
			update(2*no,i,m,pos,val);
		}else update(2*no+1,m+1,j,pos,val);
		
		tree[no] = merge(tree[2*no],tree[2*no+1]);
	}
	
}


int32_t main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>A[i];
	build(1,0,n-1);
	while(q--){
		int pos,k;
		cin>>pos>>k;
		pos--;
		update(1,0,n-1,pos,k);
		cout<<query(1,0,n-1,0,n-1).maxsum<<endl;
	}
}
